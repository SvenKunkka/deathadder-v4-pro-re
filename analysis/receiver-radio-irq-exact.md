# 接收器 1.20：mode4 RADIO IRQ、CC1 应答调度与业务入口

本报告所列 CC0/CC2 未恢复范围已由后续 `receiver_radio_timer` 扩展覆盖：2,304 组原指令验证，正常路径完整返回，18 组停在真实 RTOS 唤醒入口。见 [定时器扩展](receiver-radio-timer-exact.md)。本报告原有 1,536 组范围保持不变。


本轮恢复为可编译 C，并与原固件 Thumb 指令执行结果逐字节差分。**1,536 组全部通过**；不是射频或实机验证，也不是全部中断分支已经恢复。

- 源码：`recovered-code/portable/receiver_radio_irq.c/.h`。
- 原指令：`ghidra-scripts/EmulateReceiverRadioIrq.java`；记录 `analysis/receiver-radio-irq-original.jsonl`。
- 可复验：`python3 analysis/verify_receiver_radio_irq.py`；结果 `analysis/receiver-radio-irq-comparison.json`。
- 固件：`firmware-extracted-1.20/Suit1FWData__radio_radio.bin`，SHA256 `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`。

## 完整执行范围和测试

|实际原入口|用例|范围|
|---|---:|---|
|`23020A00`|768|mode4 RADIO IRQ 整函数，包括状态11..17、CRC/校验接受与拒绝、序号去重、队列确认、扫描E/F/10路径和事件顺序|
|`23021BBC`|576|TIMER IRQ CC1选中分支，slot0..5；队列优先级、无队列同步包、RX窗口与过期TX取消|
|`23020A00`后`23021BE4`|192|先实际IRQ返回，再显式调用实际SWI4；class0/1/3/5各48组，进入现有完整业务消费者、统计、dispatch_finish及后续失败统计|

总计245,320条原指令；每组检查完整64KiB数据RAM、RADIO4KiB、TIMER2KiB和辅助外设2KiB、NVIC最后存储值与通知请求位。Ghidra AdaptedEmulator执行只读项目中的原字节；先验证flash映像及RAM映射完全一致。**无目标函数替换、无成功返回桩、无CPU userop补丁。** 提供事件/CC7/RSSI的初始寄存器快照；任务寄存器写入不会自动产生新的外设事件。

## 同状态组件集成

另有192组C组件链测试（`analysis/test_receiver_radio_irq_integration.py`）通过：先RADIO IRQ→SWI4并匹配既有原指令终态，再向同一RAM状态显式提供下一CC1事件。175组选择排队ACK、17组无队列同步回退、96组超过截止时刻取消TX；检查数据包内容、队列读指针未二次pop、peek标志、选中类别、寄存器动作和回复标志清除。结果见`receiver-radio-irq-integration.json`。**这些是组件集成测试，新增原指令样本数为0**；人为提供slot1/4和CC7边界，不声称硬件自行调度了下一时隙。

## 接收与ACK确认

`23020A00 → 2302440C → 23024190`：依次处理TXREADY、RXREADY、ADDRESS、END、DISABLED。状态由slot选择：slot2/5使用context2，其他slot使用context0；本分支不是普通peer1。

状态12收到END(event4)时，仅CRCOK==1且DMA长度非零才进入附加校验：长度减1，累加字节1至原长度−1，要求字节[原长度]等于和的负值。通过后拷贝16字节至context+0x114，再清DMA长度；数据不足16字节时仍保留原DMA尾部行为。header[1]的bit7分别写+0x9C与+0x9D，低4位写+0x9E，bits4..6为确认序号。新序号清相应失败计数；如+0x96选中队列<6，发送序号+0x9A递增且8回1，执行实际`2302073C`队列pop；重复序号不pop。最终+0x96=255，状态回11。

接收成功真实调用`23021C24`将peer写71A4并请求NVIC位0x10000000，之后`2302233C`请求0x08000000。NVIC ISPR真实为W1S，两次请求都有效；仅观察快照最后存储值会漏掉SWI4。本模块分别保留nvic_last与nvic_requests；模拟器通过实际通知入口记录请求，未用此记录替换执行。

## CC1实际应答发送与接收窗口

`23021BBC`先判断CC0，再CC1。此模块在CC0==1或CC1!=1时返回显式未恢复边界−2，不清事件、不伪造完成。CC1被选择时：

- slot0→1、2→3、3→4、5→0：更新订阅，调用`230240AC(action4)`准备RX。state11/12有效；PACKETPTR=23003050并清DMA长度。state11时捕获CC7；slot0且CC7<3200或slot3且CC7>8000触发RXEN，否则仅更新状态为12。
- slot1→2、4→5：停止当前RX窗口并修改订阅。context2 state必须13。reply==0时触发DISABLE并转扫描state14。
- 有reply时，真实`230207EC`依class0..5查首个非空队列，标记队列项+2=1并peek数据。**此处不pop**，pop发生于后续上行的新确认序号。
- 无队列时构造长度5、class0/序号字段、opcode1F、BE16事件计数的同步记录，序号8回1；遵守原固件未在此路径清3488的行为。
- header填bit7=1、3488<<6及当前频道失败统计低字节，拷贝16B至23003070，PACKETPTR指向它。slot2时CC7>5280或slot5时CC7>13280取消TX并触发DISABLE；否则写5300E440=1及5300E000=1。此处只证明寄存器写入，未将辅助外设命名或写入冒充已发出空口ACK。

## 扫描状态与业务桥接

state14收到DISABLED后执行`23021AF4`倒计时/23项扫描推进；成功设置订阅、查固件频率表并RXEN→15。state15在RXREADY时RSSISTART→16；state16取RSSI，设置扫描结果标志并发通知，回13。扫描表循环、等待时间200/5000与停止标志均保留。

`rr_receiver_radio_swi4`在独立调度步骤调用完整`rr_receiver_business_flow`，随后恢复`230247D0→230216BC`：模式0/1按频道写失败值，模式2/3按频率索引取较大值。这个SWI是IRQ返回后的显式调用，不声称Ghidra自动实现了NVIC抢占/优先级。USB驱动保留已有pending/resume，统计尾段在resume后才执行。本轮192组选择了不进入USB驱动的路径；未新增该边界的原指令证据。

## 残余范围

CC0/CC2的时隙定时、跳频、事件计数、重试超时和断连生命周期仍未恢复到此模块。mode1/2及globalstate5的BLE路由不在本轮范围。class2/4密码业务与USB驱动continuation依赖已验证既有组件，但不在新增192组IRQ→SWI4用例内。DMA长度、RAM/队列元数据需有效；没有对任意损坏内存进行安全扩展或原行为等价承诺。当前不具有真实PHY、DPPI或时钟模型，不能据此宣称完成硬件端到端链路。

## 精确来源

以下列出RAM地址、镜像偏移和入口16原字节；所有地址映射为`offset=VA−23020000+79C`，完整清单也在同名JSON。

|地址|镜像偏移|入口16字节|用途|
|---|---|---|---|
|0x23020a00|0x119c|`094b1a88052a07d09b88042b08d0012b`|RADIO IRQ mode4|
|0x2302440c|0x4ba8|`08b5254bd3f80422012a04bf0022c3f8`|mode4 RADIO wrapper|
|0x23024190|0x492c|`2de9f843934db5f8a040022c05d0a4f1`|mode4 radio event states|
|0x23021bbc|0x2358|`084b1a88012a06d99b88042b04d0012b`|TIMER IRQ, CC1 branch|
|0x23023fa4|0x4740|`38b53a4ab2f8a0303bb1013b042b2dd8`|slot subscription|
|0x230240ac|0x4848|`324ad2f880300b2b17d00c2b14d10428`|RX window action|
|0x230207ec|0xf88|`40f68473114a10b503fb002353fa81fc`|actual queue peek|
|0x2302073c|0xed8|`40f68472084b02fb0033194491f86021`|actual queue pop|
|0x23021af4|0x2290|`224bb3f8021149bb40f6847210b4204c`|scan increment|
|0x23020f1c|0x16b8|`30b400240125054b0260c3f80042c3f8`|task-state transition|
|0x23021be4|0x2380|`0d4b9b88042b04d0012b0cd0022b0ed0`|SWI4|
|0x2302455c|0x4cf8|`40f684732de9f04f00fb03f3964d87b0`|business dispatch full|
|0x230247d0|0x4f6c|`024640f68471054b054801fb023390f8`|post-business stat|
|0x230216bc|0x1e58|`0d4ad3898bb1012b0fd0022b01d0032b`|stat update|
|0x23021c24|0x23c0|`4ff080520249034b0880c3f808217047`|pend business SWI4|
|0x2302233c|0x2ad8|`4ff0006230b4044b044d054c28802180`|pend notification SWI3|

768组独立RADIO样本中：成功接收29组，其中context2为12组；新确认序号11组，发生实际队列pop 7组。状态分布：{'11': 114, '12': 114, '13': 108, '14': 108, '15': 108, '16': 108, '17': 108}。这些数字为固定fixture覆盖，不是实机统计。

## 审阅修正：NVIC写动作与旧值区分

已确认旧实现可能在SWI4没有写ISPR时，把调用前nvic_last=08000000/10000000误累计成新请求。现按实际唯一写分支记录：合法长度1..127、class0、opcode2B才累计08000000；即使与旧last相同也记录这次真实写入。无写路径保持已有requests不变。此条件对应`rr_control_consume`及原接收控制分支，未修改共享模块。

修正后1536组原指令差分、192组组件集成全部重新通过；另48组C回归覆盖两种旧last、空/已有requests、长度0/1/127/128及opcode2B/2C/55。48组为写动作记录的C回归，未计入新增原指令组数。源码与证据哈希已更新并重新冻结。
