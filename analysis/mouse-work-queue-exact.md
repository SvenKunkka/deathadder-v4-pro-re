# 鼠标工作队列与完整 mode4 超时尾段（1.20）

新增 `mouse_work_queue.c/.h`，恢复工作项实际入队、唤醒等待线程、活动超时取消、ready 排序和时间片注册，并把它们接到 mode4 超时入口。新增 **2,560 组原指令差分通过**：2,547 完整返回，13 组停在真实线程切换入口。与 [timer start模块](mouse-timer-start-exact.md)组合后，原来的工作提交和定时器启动边界不再阻止已验证的 mode4 超时流程返回。

## 恢复范围

|原地址|行为|
|---|---|
|`0E0952EC`|系统工作队列提交包装；默认队列 `23002498`，BASEPRI阈值20；成功后重新调度判断|
|`0E09518C`|根据work状态、显式队列、已有owner和队列运行状态决定拒绝/无操作/入队；更新单链表及owner|
|`0E096220`|从工作队列等待链移出首线程，清等待状态，取消其活动timeout，插入ready队列|
|`0E0958BC`|按有符号8位线程优先级稳定插入ready链，保留相同优先级顺序|
|`0E09587C`、`0E096318`|选择候选线程，取消旧时间片并按线程状态重新注册 `0E0962F5`|
|`0E095ECC`|恢复优先级；在原优先级0、线程模式且候选与current不同的情况下，进入真实 `0E089D4C` 切换边界|
|`2302516C→23022F5C→23025ED4`|mode4超时的无线清理、work提交、状态写入及 `23001578` 定时器启动|

工作项前16字节是next/handler/owner/flags；队列的work头尾在+90/+94、等待链在+98/+9C，队列状态在+A8。flags bit1返回−16；bit2已经排队返回0；bit0运行中的工作改用原owner，成功返回2；其他成功返回1。没有可用owner返回−22，未运行队列返回−19。helper失败或已经排队会把调用方的queue_ref清零。

与当前线程相同且处于线程模式时，队列状态许可条件不同于其他线程或中断模式。代码保留这一区别，不把所有flags组合简单归为“忙”。挂入work单链表后再唤醒等待者；只有唤醒路径完成才给work置已排队位并写owner。等待者和timer的先前副作用不会因为后面的边界而回滚。

ready链位于 `23007668/2300766C`；current、fallback、next在 `23007654/58/64`。时间片对象为 `230025E0+CPU索引×24`。活动timeout调用已有鼠标abort，时间片启动调用新 `rr_mouse_timeout_start`，保留鼠标elapsed右移5位、优先级20及原地址布局，未调用接收器实现冒充兼容。

## 验证结果

|数据集|原指令输入|结果|
|---|---:|---|
|[工作队列](mouse-work-queue-original.jsonl)|2,048|helper和系统包装各1,024；2,035返回、13真实CPU切换边界。返回值包含−22、−19、−16、0、1、2；完整RAM/RTC及CPU优先级一致|
|[mode4完整超时](mouse-mode4-rtos-original.jsonl)|512|全部从TIMER入口执行到返回；512次真实work调用、512次真实timer-start；完整RAM/RADIO/TIMER/SPIM/clock/NVIC/RTC一致|

直接工作队列数据中，150组修改ready链、64组注册时间片、58组修改RTC。完整mode4数据中，138组新增工作入队、56组注册时间片，512组均注册目标timer。其他样本包含原有已排队、运行和拒绝状态；调用方按原逻辑忽略work返回值后继续启动timer，不能把512次调用都说成512次新增工作。

原代码执行前检查整个Flash和79C→23020000映射以及镜像SHA256。缺失的BASEPRI读取绑定同一模拟器CPU状态，IPSR为明确输入；没有替换目标函数或用成功桩省略队列/超时器。完整512组明确使用中断模式，直接2,048组另外验证真实线程模式切换边界。原始寄存器与内存记录及原字节入口摘要见 [完整证据](mouse-work-queue-exact.json)。

## 新接口与保留边界

`rr_mouse_work_submit_to_queue` 对应原helper，`rr_mouse_work_submit` 对应系统包装。`rr_mouse_mode4_timer_rtos` 从既有生命周期的真实暂停位置继续执行work和timer-start，旧API继续保持原合同。扩展不会重新调用整条IRQ来伪装续接。

CPU模型显式保存priority、exception_number及实际pending entry/arg0；真正切换仍停在 `0E089D4C` 入口，arg0=0。RTC busy等下层边界保留已完成的链表/状态写入；这些模型状态码不是原固件错误返回。

**工作项入队不代表其handler已执行；到期入口注册不代表未来IRQ或周期回调已执行。** 工作线程消费循环、真实CPU栈切换、timer到期、并发调度与空口仍需后续恢复。没有设备写入或实机无线验证。

复现入口为 `verify_mouse_work_queue.py`、`verify_mouse_mode4_rtos.py`；后者也重新验证前者。当前使用已安装的Java25执行Ghidra12.1.3；最初Java21与缓存class版本不匹配的启动失败单独保留，不计入任何原指令样本。
