# 接收器 mode1/2 TIMER 与连续接线（1.20，冻结）

新增 `receiver_legacy_timer.c/.h`，恢复原入口 **23023C60 / 23022ED4**，包括CC0..7优先级、时槽切换、RX超时动作、发现/握手发送、两peer应答队列选择、周期计数与断连通知。复用已验证的队列、握手、RTOS timed模块；没有成功桩，没有设备操作。

**3,584组原TIMER入口全部通过**：3,576完整返回，8组在真实context-switch `0E0611CC`前停止。执行582,588步；实际进入511次sem、553次message_put、42次purge、1,364次timeout_abort及594次timeout_start。3072组为时槽/门控/发送辅助，512组针对断连和活动等待线程。比对128KiB RAM、RADIO/TIMER/auxiliary/RTC完整窗口及BASEPRI、pending入口/参数。

另为连续接线新增 **768组q255原RADIO样本全部通过**（384重复序号、384新序号；103,296步），旧2688组IRQ样本全部回归通过。**24个C连续组件场景也通过**：288周期、2496次TIMER、768次RADIO→SWI、112次真实定时器生成255后的新确认。这24场景是组件集成，不计为新增原指令数据或RF验证。

## 时槽与优先级

两入口每次只处理第一个值等于1的COMPARE事件，顺序CC0到CC7；非1值保留。mode1的CC3带接收超时动作，不能当作仅清事件；mode2 CC3..7仅清事件。公开API直接对应两个内部入口，根入口3230<2门控由调用方负责。

|路径|CC0设置 CC0/CC1/CC2/CC3|CC1槽推进|CC2表|
|---|---|---|---|
|mode1 interval1|16000/2880/3840/11200|0→1→2→3→4→0|(2880,3840)、(5600,6560)、(8320,9280)、(11840,12640)、末槽(15040,0)|
|mode1其他|16000/3680/4640/2560|0→1→2→3→0|(3680,4640,0)、(7040,8000,0)、(11680,12640,10560)、末槽(15040,0,0)|
|mode2|16000/4160/4640，CC3不改|0→1→2→0|slot1(8800,9600)，slot2(14720,0)|

mode1 interval1只有slot0和slot4订阅配置，其他中间slot保持原寄存器；其他间隔在slot0/2订阅RX、slot1/3订阅TX。`23023268`另行更新6274选择peer0或2。连续测试确认：其他间隔的第二次RX不能仅在CC1准备完就注入，必须等CC2执行选peer0；订阅和软件选择不是同一动作。341E待用间隔仅在周期回0时，且3420等于context2计数5376才应用并清零。

mode1接收动作保留state11/12差异、STOP任务、`(DMA长度−1)>11`条件，以及interval/slot决定的失败标志或peer0计数调用。原任务助手清READY/END/DISABLED；模型不将任务写自动变成新的硬件事件。

## 发现、握手与应答

mode2 `230226C8`按connection<2、==2、>2分配发现、握手、正常数据订阅。发现用5376 bit7选择频道表项37/39；握手使用四项表 `0E06FBAC`，计数奇偶控制TX/RX和地址掩码。`23022888`恢复state7的握手计数/清包/频道推进，构造0x11或0x24包，以及state8取消、state11数据接收准备。复用已有offer算法，实际传入参数以GNU指令为准，未采纳反编译多出的第三header参数。

mode1应答按六队列优先peek，没队列则构造class0 opcode1F候选索引同步记录；无队列分支保持原selectedqueue旧值，不加人工reset。interval1没有reply时调用强制失败计数；其他间隔没有此额外计数。两者清reply并保留DISABLE副作用。

mode2应答优先peer0，其reply必须等于1且有非空队列；然后检查peer1。原header合并两peer reply、选中peer/flag和频道统计，不使用mode4格式。没有队列时使用候选索引同步记录；完全无reply则取消TX并DISABLE。

## q255 是真实衔接状态

原mode2 TIMER在搜队列前，把两个peer的selectedqueue（context+96）写255。上轮RADIO模型合同仅接受0..5，所以无法接收这个定时器真实产物。本轮经协调仅扩大 `receiver_legacy_radio.c/.h` 的255输入域，保留其他范围限制。

原RADIO的新序号分支只检查`q!=0`，并没有忽略255；原 `2302073C`无下标保护，实际对 **context+259字节**执行uint8加1，与 **context+25F字节**比较，相等才归0。新模块在legacy路径内明确投影这两处原偏移，不把255伪装成第六队列，不修改公共business_tx有效域。重复序号完全不做此pop，但仍清selectedqueue到0。768组原指令已逐字节验证重复/新序号及加1回绕。

旧阶段源码hash、报告和冻结清单保存在 `receiver-legacy-radio-stage1-*`；本轮当前版本与回归证据在 `receiver-legacy-radio-revision2.json`，不擦除历史。

## 周期与断连

mode1只计peer0/2，业务间隔在已有值小于200时加1，>=200保持；先写新32CA再选频率。mode2计peer0/1/2，业务间隔按u32自然回绕，使用旧32CA选频率后才更新channel bit。选择器2/3保留现有频道置换/重映射写回30E3/30E4/3228，选择器0/1访问候选表，其他返回原0x962。

失败计数超过99进入断连。mode1清订阅、radio state0，**不清connection word**，再回退mode2；mode2先清connection并设radio state11，然后回退，先检查peer0再peer1。不能用一个统一的“清连接”动作替代这些顺序。

随后原221A4写disconnect flag，执行真实timed semaphore；活动等待线程从列表摘出、timeout取消、ready排序、timeslice动作后执行type2通知，满队列实际purge重试。每peer的24B旧栈尾是显式环境输入，身份和类型字段独立构造。8组线程切换边界保留此前所有写入，返回CPU entry/arg0；**重新调用TIMER/IRQ不是resume**。RTC高字busy的-4状态保留自公共timed合同，本批新增TIMER输入未单独触发该状态。

## 文件与边界

源码 `recovered-code/portable/receiver_legacy_timer.c/.h`；原脚本 `EmulateReceiverLegacyTimer.java`、`EmulateReceiverLegacySentinel.java`；验证 `verify_receiver_legacy_timer.py`、`verify_receiver_legacy_sentinel.py`；连续组件 `test_receiver_legacy_continuous.py`。对应original.jsonl、comparison.json、exact.json、freeze.json均在analysis下。exact.json保存23个关键原入口/分支的原字节及镜像偏移。

固件SHA256为 `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`。AdaptedEmulator执行原Thumb，不替换目标函数；BASEPRI getter桥接相同ArmCpuState，exception为显式CPU环境。未验证真实屏障、RF、DPPI、自动IRQ派发、并发队列生产者或可烧录固件。共享RTOS/timeout/business模块没有改动。
