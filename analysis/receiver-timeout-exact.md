# 接收器活动超时器及 RTOS 续接（1.20）

当前恢复 `receiver_timeout.c/.h`，并以可选 timeout ops 扩展 `receiver_rtos_lifecycle.c/.h`。旧 API 的调用边界和 ABI 保持，新增 `*_timed` 接口实际执行取消/启动逻辑。新增 **3,840 组原指令输入差分全部通过**；这不是完整 RTOS 或无线固件。

## 原始代码与恢复行为

|入口|含义与恢复要点|
|---|---|
|`0E06E768`、`0E06E610`|活动 timeout 从双向 delta 队列摘除；继承被删节点的 delta，清其前后指针。未活动返回原值 −22。移除队首后重新安排 RTC 比较值|
|`0E06E648`|注册回调；相对/绝对 64-bit timeout 转换，按有符号 64-bit delta 插入；更新后继 delta 和队首 RTC|
|`0E068568`|读取 RTC 与 `23002840` 基准之差，取低32位并按有符号数参与 timeout 计算；**接收器没有鼠标的右移5位换算**|
|`0E068584`|将剩余 ticks 转成绝对 deadline；due=0 改为1；比较值高字保留20位|
|`0E069760`、`0E0695C8`|实际支持的 channel7/13/14/15，分配掩码检查、比较中断、寄存器事件清除和内存中的 channel 元数据|
|`0E06E4EC`|切换候选线程时取消旧时间片，清 CPU 标记；按优先级和线程状态判断是否启动 `0E06E4C9` 回调|

timeout 使用原始位模式计算。`UINT64_MAX` 是直接返回；非负有符号 delay 走相对分支，值为 `INT64_MAX` 时加1溢出仍按原分支执行。其他负数走绝对分支，计算 `−2 − global_base − delay` 并将非正结果变为1。插入比较按有符号64位，算术本身保留模2^64行为。没有把极值输入统一改写成更“合理”的结果。

队列头/尾位于 `23000B48/23000B4C`。取消队首时，即使剩余为空也保留原代码读取 elapsed 的调用条件；`23007198` 冻结标记影响 elapsed 和启动时的重新安排。RTC 投影窗口为 `5F99C000` 的4KiB，RAM为 `23000000` 的128KiB。

## 原指令验证

|数据集|输入|实际范围|
|---|---:|---|
|[timeout原码](receiver-timeout-original.jsonl)|2,048|1,024取消＋1,024启动；全部完整返回，比较完整RAM/RTC及取消返回值；429组实际修改RTC|
|[RTOS timed原码](receiver-rtos-timed-original.jsonl)|1,536|信号量、消息直交、purge、type2通知各384；1,501完整返回，35组停在真实 `0E0611CC` 线程切换入口；488组写入时间片回调|
|[完整断连原码](receiver-disconnect-timed-original.jsonl)|256|从mode4 TIMER入口到活动timeout、线程ready、时间片、断连通知；全部完整返回，比较RAM/RADIO/TIMER/AUX/RTC|

[三组报告和原字节入口摘要](receiver-timeout-exact.json)；[直接差分](receiver-timeout-comparison.json)；[RTOS组合差分](receiver-rtos-timed-comparison.json)；[断连组合差分](receiver-disconnect-timed-comparison.json)。旧RTOS1,536及旧断连256在扩展后回归通过，不重复计入新增输入。

模拟前核验官方镜像 SHA-256、整个Flash映射和RAM复制字节。缺失的BASEPRI getter读取模拟器内建setter的同一CPU状态；原代码自然执行所有被调函数，没有函数成功桩。指令同步屏障是模拟器的无并发操作，IPSR是显式输入。原中断模式下函数退出恢复初始优先级；真实上下文切换前停下的样本保留当时优先级和全部先前副作用。

## 接口与边界

`rr_receiver_timeout_abort/start` 是直接入口；`rr_receiver_semaphore_give_timed`、`rr_receiver_message_put_timed`、`rr_receiver_message_purge_timed`、`rr_receiver_disconnect_notice_timed` 和 `rr_receiver_timer_mode4_lifecycle_timed` 接入真实取消/启动逻辑。函数指针及上下文显式传入，没有全局回调状态。

旧通知的24B未初始化栈尾在原始通知入口观察并作为C投影输入，仍没有重建CPU栈生成。这里恢复的是回调注册，不是未来到期回调的自动执行。RTC不会自主推进，外设事件、DMA、实际线程抢占和无线时序均未仿真。无接收器实机，未进行设备写入。

有效双向链表是模型输入条件，节点数上限和无效内存检查是主机保护；不是原固件错误返回。RTC高字busy时模型返回−4并保留之前写入，不伪造稳定时钟读成功。真正的线程切换、到期处理、管理线程消费尾段仍需继续恢复。

复现：从报告根目录执行 `rtk proxy python3 analysis/verify_receiver_timeout.py` 和 `rtk proxy python3 analysis/verify_receiver_disconnect_timed.py`；后者也运行1,536组RTOS timed比对。
