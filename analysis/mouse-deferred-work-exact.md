# 延迟工作生产、RTC 到期入队与 timer 断连回调

新增 [mouse_deferred_work.c](../recovered-code/portable/mouse_deferred_work.c) / [接口](../recovered-code/portable/mouse_deferred_work.h)，将已恢复的队列、timer、RTC 与断连函数组合起来。完整无线工程仍未完成。

|原入口/路径|已恢复行为|
|---|---|
|`0e095478` / `0e0954e0`|显式队列 / 默认工作队列的延迟启动：状态位拒绝门控、零延迟直接入队、非零延迟保存队列并注册 timeout|
|`0e09554c` / `0e0955c4`|延迟重排：先清延迟标记、取消已存在 timeout，再按零延迟或非零延迟处理；保留其他状态位与原返回值|
|RTC → announce → `0e095254`|由真实到期队列清除延迟标记、执行入队、唤醒等待线程，然后继续原 announce 剩余 tick 和 compare 更新|
|timer expiry → `23025f78`|读取 `6b7b` 单字节原因，调用实际断连主体；返回后继续原 timer 等待者处理，不重入已修改的前缀|

RTC 共用主循环新增可选处理器；旧接口传空处理器，继续保留旧行为。新扩展支持已知 timer、扫描、线程、时间片、延迟工作与该断连用户回调。未知回调仍保留入口和参数。没有以成功桩或重复进入顶层函数替代续接。

## 原指令验证

[延迟生产者比较](mouse-delayed-work-comparison.json)：四入口各 1,024 组，**4,096 组完整返回**，共 378,598 原指令步。覆盖工作状态位、已活动 timeout、目的队列、立即/相对/绝对/永久时间编码和返回值。

[RTC 与 timer 比较](mouse-rtc-deferred-comparison.json)：announce、clock、RTC、直接 timer 四入口各 1,024 组，**4,096 组**，共 2,631,849 原指令步。其中 **4,079 完整返回、5 个 CPU 请求入口、12 个人工未知 RTC 回调入口**。人工未知指针为位图分配辅助函数，仅验证暂停 ABI，不代表真实注册。全 RAM、RTC、AUX、RADIO、TIMER、NVIC、clock 和优先级一致。

新增合计 **8,192 组输入、8,175 完整返回、17 个明确边界**。旧 RTC 的 6,144 组与 8 轮扫描重启回归通过，结果保持一致，未重复加计。见 [回归记录](mouse-rtc-hooks-regression.json) 和 [修改前归档](rtc-v1-before-deferred/manifest.json)。

## 连续链与限制

[连续组件](mouse-deferred-continuous-comparison.json)覆盖四个 RTC compare 通道，共 **128 轮**，含 **64 次活动重排**。测试依次执行线程等待、原延迟生产者、显式 RTC compare 事件、到期后真实入队/唤醒、工作回调；没有直接调用延迟到期回调。验证了跨低 32 位 RTC 回绕的情形。

时钟、事件、INTENSET 读回和 256 次上下文交接由环境显式提供；不能证明硬件异常、真实并发、无线互通或完整启动。timer stop 用户回调/等待路径仍沿旧接口保留边界。一次 Java 测试夹具编译失败已修复并保留日志，没有计入案例。

复验：`verify_mouse_delayed_work.py`、`verify_mouse_rtc_deferred.py`、`test_mouse_deferred_continuous.py`；[源码/入口摘要](mouse-deferred-work-exact.json)、[本轮完整性](phase-deferred-work-integrity.json)。
