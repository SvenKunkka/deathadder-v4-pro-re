# 鼠标1.20：mode1/2无线中断恢复与业务交接

本报告的旧接口保留非空 ACK 回调边界。后续新增 `mouse_timer_lifecycle` 与 `rr_mouse_radio_irq_lifecycle` 已恢复已识别的 class3 回调及活动定时器停止，并用 384 组完整 IRQ 原指令验证；见 [生命周期扩展](mouse-timer-lifecycle-exact.md)。旧 2,944 组在 hook 扩展后回归通过。


新增 `recovered-code/portable/mouse_radio_irq.c/.h`。`rr_mouse_radio_irq(ram,radio,timer,&nvic,mode)`分别对应 mode1入口230236ac、mode2入口23022fbc；不是完整23021704顶层分派，也不包含mode4/握手/测试模式。复用现有`business_tx.c`真实队列pop语义；共享模块未修改。

**2944组原Thumb指令/C差分全部通过**：2048组两入口基础覆盖、640组mode1失败门控遍历、256组显式IRQ返回后再运行23022508的交接。比较全部65536字节RAM、4096字节RADIO、1536字节TIMER020以及NVIC字。另4组域外预检不改变输入。

## API及运行边界

RAM基址23000000；RADIO窗口5302c000；TIMER020窗口53028000；NVIC参数模拟E000E208写入字。mode参数明确选择原始子入口，不能把直接执行子入口的测试等同于顶层ISR在所有global_state下均可达。

返回0表示支持域内执行完成；-1参数错误；-2成功RX且当前TX队列id为3、23006b68回调非零；-3实际DISABLED RX但bank不在0/1投影域。后两者是预检边界，全部输入保持原样；它们不是固件自身验证或返回码。23023a10正常周期按事件计数bit1产生bank0/1，原始IRQ没有bank范围检查。

不自动调用业务消费者或SWI。IRQ挂起SWI之后，应由独立调度阶段调用已有`rr_mouse_business_flow`；随后消费者仍按真实work延期。256组交接测试显式选择了这个顺序，未恢复中断优先级、队列唤醒或并发时序。

## 事件入口和清理

两模式先对TXREADY(+204)、RXREADY(+208)、ADDRESS(+20c)、END(+218)执行“值恰为1才清零”。DISABLED(+220)不等于1就返回，CRCOK/CRCERROR保持原值。DISABLED等于1时清零，最后通过230218d8无条件清CRCOK(+22c)、CRCERROR(+230)，包括非RX状态。

mode2状态19仅清SUBSCRIBE_TXEN(+100)，不把状态改成18。mode1状态19没有这个订阅清理。两者只在状态1a处理接收响应；其他状态不处理payload。

RX时两者清SUBSCRIBE_RXEN(+104)。mode1原指令对它写零两次，再清SHORTS(+400)的bit19；C存储投影保留相同末值，不声称复刻两次外设写入的物理时序。mode2清SUBSCRIBE_DISABLE(+110)和TIMER020 SUBSCRIBE_CAPTURE7(+dc)，不清SHORTS。CRCOK恰等于1才走成功分支，CRCERROR本身不参与这个判定。

## 成功ACK

若u32[29c4]和u32[29cc]都为0，mode2捕获TIMER CC7(+55c)到29c4。mode1在rate29ac=1或slot_phase283c=1时直接捕获；rate不为1且phase=3时捕获CC7-250（32位回绕）；其他phase不更新。

复制DMA区23002630的16字节到23002a96，然后仅清源长度byte2630，保留源其他15字节。推进发送周期byte2a1e，以8位截断；结果恰为8改成1，其他值没有额外归一化（例如255→0）。清u16 no_response_count2a0c和当前bank的u16失败计数2a14+bank*2，置byte2a22=1。

mode1另清byte2a26以及24字节聚合cache2670..2687；成功前bank失败数>2时，先把频道byte29d5+bank加1，仅在结果等于frequency_count29df时wrap0，再清失败数。mode2成功不推进频道，不清该聚合cache，也不清2a26。

当前TX队列id来自u16[2a1a]，小于6时调用2302145c(0,id)：读指针以8位加1、等于capacity才wrap0，没有先检查队列是否为空。这里释放的是当前TX队列，不是回包业务class。随后真实执行23025eb4；id不是3自然返回；id=3且回调为空也自然返回。成功写NVIC E000E208=10000000（挂起SWI4），状态置18。

成功到队列释放间没有比较回包的序号与发送周期序号；回包payload按class去重发生在之后23022508。此结论仅描述本静态路径，不等同于空口可利用性或缺乏其他硬件门控。

## 失败、换频门控与下一次发送边界

两模式失败均不释放TX队列，不推进发送周期序号，不清聚合cache；清byte2a26，置byte29d0=2，状态置18。

mode1额外处理：rate=1调用230238f0(arg0=1,require_due=0)；rate不为1且phase=1只置2a25=1；phase=3调用230238f0(1,1)；其他phase不改due。mode2没有这段失败计数辅助调用。

230238f0在require_due非零而2a25=0时立即返回。否则global_state2794=3时，rate1/2/4/8每次允许计数，16/32/64分别要求u16[2a0a]模2/4/8为0，其他rate不计数；global_state=4且arg0=1允许；其他不允许。允许则16位失败数加1，结果>3才推进频道并清该计数；65535→0不触发>3。最后清due。频道递增只检查等于count，不是大于等于。640组专门遍历10种rate×16种事件计数×4种旧失败数。

本模块恢复的是IRQ内的ACK释放、失败保留和换频计数；真正下一次TXEN、定时槽、待发组包及重发时机属于TIMER/发送状态机，本模块不宣称已经覆盖。

## 非空class3 ACK回调

23025eb4只对id3检查u32[23006b68]；非空就实际间接调用并清指针。已定位23025cac设置其为23025c2d。该回调23025c2c停止timer230015b0，并进入23022d88（清连接/无线初始化、停止timer23001540、清三个模式状态、停清TIMER020、通知上层）。这里涉及真正RTOS timer与生命周期链，尚未在本模块恢复，故返回明确边界-2，不能用“回调已成功”空函数替代。

## 原指令验证

`EmulateMouseRadioIrq.java`校验官方1.20二进制SHA256和RAM LMA→VMA映射后执行原始入口至返回哨兵。2688个单IRQ样本完整经过真实pop、失败辅助、callback-null返回，未修改目标指令，也未用CPU userop补丁。256个交接样本在IRQ返回后显式调用23022508，原重组和work fast-return真实执行；仅此部分沿用Ghidra缺失BASEPRI getter到同一ArmCpuState的桥接，ISB仍为Ghidra惰性实现并在日志记录。

验证事件值0/1/2/ffffffff、DISABLED未发生/发生、TX及其他状态、CRC0/1/2、两bank、队列0..5/6/ff/ffff、读指针/容量边界、发送序号回绕、rate与slot_phase、计时捕获与减250回绕、成功/失败频道推进和保持旧DMA/cache内容。测试比较NVIC写入内存值，不把它当成真实W1S寄存器时序仿真；C的队列pop以串行内存语义实现，未建模PRIMASK并发。

复核命令：`rtk proxy python3 outputs/razer-radio-re/analysis/verify_mouse_radio_irq.py`。原记录`mouse-radio-irq-original.jsonl`，结果`mouse-radio-irq-comparison.json`，原指令范围/bytes/hash与固件来源`mouse-radio-irq-evidence.json`，GNU反汇编`mouse-radio-irq-instructions.txt`。没有设备I/O，未修改现有共享模块或主报告。
