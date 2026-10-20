# 鼠标定时器停止与等待线程恢复

官方鼠标 1.20 无线镜像，原入口 `0E096AC4`、回调后续段 `0E096AD6`。

恢复代码：[mouse_timer_stop_runtime.c](../recovered-code/portable/mouse_timer_stop_runtime.c)，接口与续段约束见 [头文件](../recovered-code/portable/mouse_timer_stop_runtime.h)。

停止先执行真实 timeout 摘链。仅当原 abort 返回 0 时读取 stop 回调。非零回调停在其真实入口并保留参数；未伪造回调成功。回调返回后的独立接口读取当时的 timer 等待队列，只移出首个等待者，清 pending 位和等待对象，调用就绪调度，按原 BASEPRI/IPSR/next/current 条件请求 CPU 切换。

不同于 semaphore give，此处既不清等待者的 `+8C` 结果字段，也不取消其 `+18` timeout。原指令记录中 1,228 次移出等待者后结果字段保持，176 次移出后自身 timeout 仍保留。

## 验证

[比对结果](mouse-timer-stop-comparison.json) 和 [原字节/覆盖证据](mouse-timer-stop-exact.json)：3,072 组输入、551,425 条原指令通过 RAM/RTC/RADIO/TIMER/AUX/NVIC/CLOCK 及优先级/边界参数比对。

- 2,048 组从完整 stop 入口：1,214 返回、15 个 CPU 请求边界、819 个人工未知回调边界。
- 1,024 组从回调后续段：1,002 返回、22 个 CPU 请求边界。它们由测试提供回调后状态和 ABI 栈，不证明回调已执行。
- 样本覆盖活动/非活动 timer、0/1/2 个等待者、等待线程自身活动 timeout、就绪优先级与时间片、BASEPRI 和异常上下文。

人工回调地址 `23028C54` 实为 allocator，只用作未执行的未知回调标识；不是固件中的 stop 回调注册证据。停止和恢复接口均未写入设备。旧上层模块保留冻结的边界接口；后续须按真实调用链接入新接口，并补充实际注册的回调。完整固件、异常返回和 RF 行为仍未完成。
