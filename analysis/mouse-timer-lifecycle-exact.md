# 鼠标 1.20：活动定时器停止与 ACK 断开生命周期

新增 `mouse_timer_lifecycle.c/.h`。恢复活动定时器从 delta 链表摘除、必要的 RTC 比较值重设，以及 class3 ACK 触发的断开流程。已接入 mode1/2 RADIO 子入口原有回调位置。它是具有明确边界的主机 C 恢复模块，不是完整 RTOS 或固件。

## 原指令验证

共 2,304 组原指令输入全部完整返回并与 C 模块一致：abort、stop、disconnect、ACK 回调体、ACK 分派各 384 组，另 384 组从 mode1/2 无线 IRQ 子入口开始，一直执行真实非空 ACK 回调及断开流程。执行的原 Thumb 指令总数为 721406。

逐字节比较 65,536 B 数据 RAM、4,096 B RADIO、1,536 B TIMER、4,096 B RTC、8 B 高速时钟寄存器；IRQ 用例还比较 NVIC 存储。abort 的原返回值也比较。没有替换被调函数或注入成功返回。两份数据集相互独立，分别为 `mouse-timer-lifecycle-original.jsonl`（1,920）和 `mouse-ack-lifecycle-original.jsonl`（384）。

六种有效链表形态覆盖空、唯一节点、首、尾、中间及多个节点。计数覆盖 32/64 位边界、负 delta、溢出；RTC 测试包含频道 7/13/14/15、无效频道及被占用频道。原模拟器缺少的 BASEPRI getter 读取内建 setter 使用的同一 ArmCpuState，初始优先级 0/0x20/0x80 均恢复；屏障不产生并发效果。

复验：`python3 analysis/verify_mouse_timer_lifecycle.py`。详见同名 comparison JSON；输入脚本为 `EmulateMouseTimerLifecycle.java` 和 `EmulateMouseAckLifecycle.java`。旧 mode1/2 IRQ 2,944 组也已回归通过，不重复计数。

## 活动定时器实际语义

`0E096594` 返回 −22 表示未活动，0 表示已移除。非尾节点把自身 64 位相对期限加到下一节点，按 64 位回绕；尾节点不把期限加到哨兵。随后更新前后指针并清自身指针。

若移除的是原队首，则读取当前时钟及基准，计算经过的低 32 位 tick。扣减时按有符号 32 位扩展；下一等待时间限制在 0..0x7FFFFFFF。比较期限按原来的 32 tick 对齐与最短期限分支生成。允许的比较频道为 7/13/14/15，还受占用 mask 限制；只有合法且可用频道才写比较寄存器和元数据。

`0E096AC4` 在移除成功后才检查 stop 回调和等待线程。模型遇到真实回调或等待线程边界会保留此前已经发生的摘链和 RTC 修改，不能把负值当作“完全未执行”。

## 断开与 ACK 的调用顺序

`23025C2C` 先停止定时器 230015B0，再读取 reason 字节 23006B7B，进入 `23022D88`。后者清连接标志、写 16 位 reason，按状态停止高速时钟，清 TIMER 订阅，多次停止定时器 23001540，并执行 mode2/mode1/mode4 的无线清理。包含清 READY/END/DISABLED、TASK_DISABLE、订阅、计时器停止/清零及连接状态。mode4 清 START 订阅偏移 **0x108**，不是 0x10C。

通知函数 `23025ED0` 的原指令本来就是空返回，这里没有把未知通知假装成空函数。`23025EB4` 仅在消息 class3 且回调非空时调用；已识别的 23025C2D 被真实恢复。回调完成后才清 23006B68。

mode1/2 IRQ 新接口在原调用点接入回调：先弹发送队列，再执行 ACK 回调，随后 IRQ 继续请求 SWI、写 state18 并清 CRC 事件。因此即使断开函数先写 state0，返回到这一 IRQ 后仍会被写成 state18；384 组整入口对照保留了这种原有顺序，而非凭函数名称假设“断开后必为0”。旧 `rr_mouse_radio_irq` 接口继续保留非空回调边界；新增 `rr_mouse_radio_irq_lifecycle` 提供已恢复的组合。

## 明确边界

- RAM 指针域和有效链表是调用前提；没有验证任意损坏链表。
- 未识别的 ACK 回调、实际 timer stop 回调、等待线程唤醒和系统调度仍未恢复。
- RTC 固定快照若忙条件持续，返回显式边界；没有模拟时间自动流动。
- 原函数与模型的返回值不同：abort 的 −22/0 是原返回值；C API 的其他负值仅用于表达模型边界。部分边界发生在原有修改之后。
- 未执行任何实机写操作、无线收发或接收器测量。官方 1.20 镜像与实机版本号匹配，不代表已比对实机全部字节。

## 原始入口字节

完整固件 c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48-256：`c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48`。RAM 地址对应镜像偏移 `VA−23020000+79C`；Flash 地址对应 `VA−0E06C000`。

|地址|镜像偏移|入口16字节|作用|
|---|---|---|---|
|0xe096594|0x2a594|`f8b5eff31186202383f31288bff36f8f`|abort timer|
|0xe09643c|0x2a43c|`10b40c4b5a68036882420ad04bb1d3e9`|unlink delta queue|
|0xe096ac4|0x2aac4|`10b50446fff764fda8b9636a0bb12046`|stop timer|
|0x23028b70|0x930c|`00b583b0684601f005f80749009b0a68`|elapsed ticks|
|0x23028b9c|0x9338|`30b5431c85b028d020eae070c5176d01`|program next tick|
|0x230298e4|0xa080|`00b590f808c0bcf1070f33d0bcf10d0f`|read counter|
|0x23029adc|0xa278|`2de9f04101264ef2800c017a9df81870`|compare channel|
|0x23029b84|0xa320|`00220023f0b5c0e90023eff311852023`|compare API|
|0x23022d88|0x3524|`70b500240546144b82b0224621462046`|disconnect|
|0x23025c2c|0x63c8|`08b5044806f0bafb034bd87bbde80840`|disconnect ACK|
|0x23025eb4|0x6650|`4388032b00d0704710b5034c236813b1`|ACK callback dispatch|
|0x230235ec|0x3d88|`38b50c4d002228460b49fef7cbfa0024`|mode1 teardown|
|0x23024590|0x4d2c|`38b50c4d002228460b49fdf7f9fa0024`|mode2 teardown|
|0x23025838|0x5fd4|`38b5104d002228460f49fcf7a5f90024`|mode4 teardown|
|0x23025ed0|0x666c|`704700bf47f6122c40f2e732002130b5`|empty notification|
