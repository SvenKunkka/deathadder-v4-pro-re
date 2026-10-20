# 鼠标 RTC 事件分派、时钟公告与到期队列

本阶段恢复 `mouse_rtc_dispatch.c/.h`，以官方 1.20 鼠标无线核原始指令为依据。目标完整无线固件仍未完成。

|原入口|恢复行为|
|---|---|
|`23029a30`|按 allocation/active bitmap 收集并先清除 RTC 事件，随后结合中断使能，遍历四个实时回调槽|
|`23028c08`|检查当前 RTC 是否达到 compare deadline，按 32 个 RTC 计数单位换算 tick，推进基准并公告|
|`0e09668c`|扣减 delta timeout 队列、摘下已到期节点、解锁调用回调、重新加锁并读取最新队列，最后重设 compare|
|`0e0959a4`|线程 timeout 清理等待链及挂起标记、ready 排序与时间片更新|
|`0e0962f4` / `0e096318` / `0e096388`|到期标记、时间片取消/重设、当前线程重新排序及调度选择|

复用了已验证的 timer-expiry 与扫描组合，因此 RTC 可一路调用真实 timer1540 扫描回调。到期用户回调运行后会重新读取队列和剩余 tick；回调中重启或停止定时器产生的改变不会被旧快照覆盖。源码中特别保留低 32 位 delta 符号扩展、回调前后的 BASEPRI 顺序及实时槽读取。

## 验证

[Ghidra 原指令记录](mouse-rtc-dispatch-original.jsonl)、[逐项比较](mouse-rtc-dispatch-comparison.json)、[源码与入口字节摘要](mouse-rtc-dispatch-exact.json)。三个入口各 2,048 组，共 **6,144 组 / 2,031,745 条原指令步**。全 RAM、RTC/RADIO/TIMER/AUX/NVIC/clock 快照和优先级一致；完整返回 **5,468** 组，其余 **676** 组在真实未恢复入口停止：

|真实边界|输入数|保留内容|
|---|---:|---|
|`0e095254` 未知 timeout 回调|626|入口与 r0|
|`23025f78` 未知 timer 用户回调|28|入口与 r0|
|`23028c54` 未知 RTC 回调|22|入口、r0–r3、首个栈参数|

上述未知回调指针由差分夹具显式设置，用于验证间接调用边界和参数保留；它们不证明原固件会在真实运行中注册这些回调。已知 timer/thread/timeslice 回调则沿原调用执行。

本数据集没有实际 CPU context-switch 停止实例，不据此声称其已恢复。原执行没有成功桩；首次 Java 编译失败的日志单独保留，没有计入案例。

[连续组件测试](mouse-rtc-continuous-comparison.json)使用四个初始扫描频道，各运行两轮总超时重启：测试根据恢复代码写出的 compare 提供 **8,000 个 RTC 事件**，由 RTC 分派间接产生 8,000 次扫描回调，完成 8 次工作线程重启。测试显式提供时钟、事件及 INTENSET 读回，不直接调用扫描回调；这些不是新增原指令输入，不是实机射频验证。

## 接口与边界

[源码](../recovered-code/portable/mouse_rtc_dispatch.c) · [头文件](../recovered-code/portable/mouse_rtc_dispatch.h)。三个入口统一接收内存窗口、CPU 状态和 pending 结构；返回 0 表示函数返回，1 表示真实未恢复调用入口，负数为分析模型边界。既有写入保留，不能重新进入顶层函数伪造栈续接。

未知回调、异常入栈/返回、CPU 切换、自主外设与 IRQ 调度仍未恢复。后续应补 worker drain/pend/yield、接收器顶层初始化与管理消费者、跨核及持久化等；缺少接收器使真实无线互通仍无法验证。

复验：`verify_mouse_rtc_dispatch.py` 编译并比对全部输入，随后 `test_mouse_rtc_continuous.py` 运行串行连续组件。严格总构建及哈希校验见 [本轮完整性结果](phase-rtc-integrity.json)。

## 当前源码修订 2

RTC 主循环现支持可选回调处理器，原入口传入空处理器，既有行为保持不变。旧 6,144 组原指令记录和 8 轮扫描重启已重新比对通过，未增加原指令输入统计；[回归结果](mouse-rtc-hooks-regression.json)保留前后计数及输出一致性。修改前的源码、结果与动态库见 [归档清单](rtc-v1-before-deferred/manifest.json)。新回调组合另见 [延迟工作及断连扩展](mouse-deferred-work-exact.md)。
