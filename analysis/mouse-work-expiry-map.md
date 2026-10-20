# 鼠标工作回调与RTC到期链：静态证据索引

后续执行恢复与验证见[定时器到期和工作线程报告](mouse-expiry-work-exact.md)。本文保留扩展前的静态索引。

状态：STATIC_INDEX_ONLY。新增原指令执行案例为0。本索引来自1.20固件字节、初始化数据和调用点，不证明工作线程、定时器或射频已经运行。

系统工作队列由`0e095018`经`0e0953e0`创建，工作线程入口为`0e09504c`；`0e0950b4`从工作项+4取出函数指针并调用。工作项3858注册回调`23022621`，工作项67c0注册回调`23025df1`。前者的回调尾部转到`23022cf0`扫描启动，并启动timer1540（duration=32、period=32）。

timer1578初始化的timeout回调为`0e096951`，用户回调为`23025f65`。用户回调清除`23006b7e`的**半字**，随后提交work67c0。该工作的回调调用`23020e7c`，参数为r0=1、r1=(该半字==1)。若延期执行前状态未变化，走r1=0分支；不能直接用已有的连接成功r1=1实现替代，也不能称为直接重连。

RTC IRQ109向量进入通用IRQ入口`0e089fe4`，表项指定参数`23029a31`和handler`23028ced`，再进入`23029a30`。RTC槽回调指向`23028c09`，后续进入timeout announce `0e09668c`。它摘除到期timeout并调用timeout+8；timer expiry `0e096950`可先重插周期timer，再调用timer+0x20的用户回调，随后处理等待线程。这是静态调用链，实际异常返回、时钟、回调变化和并发均未验证。

## 入口字节

|入口|识别用途|原始16字节|
|---|---|---|
|`0xe095018`|sysworkq_init|`10b5094b84b002ac93e803004ff48052`|
|`0xe0953e0`|work_queue_create|`f0b50026044689b0c0f89060c0f89460`|
|`0xe09504c`|work_thread_loop|`2de9f04f20254ff0ff384ff0ff390446`|
|`0xe0952a0`|work_init|`00234160c0e902330360704770b582b0`|
|`0x23022d68`|work3858_register|`08b50449044809f0fffb0122034b1a70`|
|`0x23025d1c`|business_workers_register|`30b589b0fdf722f80020002100240a25`|
|`0x23022620`|work3858_handler|`10b51d4b93f827404cbb1c4a117901b9`|
|`0x23022cf0`|mode2_scan_start_tail|`30b54ff47a74002102201325154b164a`|
|`0x23025df0`|work67c0_handler|`034b0120598a012918bf0021fbf73eb8`|
|`0x23020e7c`|application_link_state_handler|`194b012910b5198010d000230121174a`|
|`0xe089fe4`|generic_irq_entry|`08b572b60b4b5a6972b962b6eff30583`|
|`0x23028cec`|irq_callback_thunk|`004700bf2de9f041114f4b09fb5c1646`|
|`0x23029a30`|rtc_event_dispatch|`4ef2800cf0b5274b83b0d3e901232cea`|
|`0x23028c08`|clock_announce_callback|`70b514461d4682b0684600f0b7ffdde9`|
|`0xe09668c`|timeout_announce|`2de9f84f0346eff311884ff0200989f3`|
|`0xe09643c`|timeout_unlink|`10b40c4b5a68036882420ad04bb1d3e9`|
|`0xe096950`|timer_expiry|`f8b5eff31186202383f31288bff36f8f`|
|`0xe0967f0`|current_ticks|`10b5eff31184202383f31288bff36f8f`|
|`0x23025f64`|timer1578_user_expiry|`0022024b02485a8206f0a0ba6c6b0023`|
|`0x23025f78`|timer15b0_user_expiry|`014bd87bfcf704bf6c6b002338b54468`|
|`0x23022310`|timer1540_user_expiry|`70b58ab000bf424cd4f88c30172b0fd8`|
|`0x2302b70c`|optional_timer1b48_start|`0c4b1b7833b110b50b4c82b0237813b1`|
|`0x23025d90`|separate_message_thread|`10b50a4ca0b04ff0ff3201a94ff0ff33`|

## 继续恢复范围

- actual work_thread_loop0e09504c dispatch/posthandler/wait/yield
- RTC event dispatch23029a30 and announce23028c08/0e09668c
- timer expiry0e096950 periodic reinsert/status/usercallback/waiter path
- work3858 handler23022620→22cf0 linkage
- 1578→67c0→23020e7c state0 plus conditional1b48 start and MMIO effects
- PRIMASK/IPSR/exception-return and context-switch execution
- dynamic callback changes/races not established by static initialized pointer evidence

完整调用点、初始化数据、来源摘要见[JSON证据](mouse-work-expiry-map.json)。本轮完整性脚本复核原始字节与所有引用来源的SHA-256。
