# 工作线程等待、让出执行与延迟工作到期

新增 [mouse_worker_runtime.c](../recovered-code/portable/mouse_worker_runtime.c) 与 [接口](../recovered-code/portable/mouse_worker_runtime.h)，保留此前模块和它们的验证边界。完整固件目标仍未完成。

|原始入口|本轮恢复|
|---|---|
|`0e096220`|唤醒等待队列首个线程，写入结果/数据，摘等待链，取消活动 timeout，ready 排序与时间片更新|
|`0e09600c`|当前线程从 ready 摘下并按优先级重新插入，选择下一个线程和重设时间片，停在真实 CPU 请求入口|
|`0e09628c → 0e095cf8 → 0e095924`|当前线程移出 ready，标记挂起，插入目标等待队列；有限 timeout 注册线程到期回调，永久等待不注册|
|`0e095254`|清工作项延迟标记，按保存的队列调用实际入队及唤醒逻辑|
|`0e09504c` 工作线程|基础组合执行连接状态回调；扩展组合还能执行扫描回调。drain 会逐一唤醒全部等待者，然后进入 pend；普通回调后的 yield 也执行至 CPU 请求|

`rr_mouse_work_thread_runtime` 保留基础接口缺少无线寄存器窗口时的扫描回调边界；`rr_mouse_work_thread_scanning_runtime` 使用完整硬件快照执行已恢复扫描回调。两者到下一循环头返回 0，仅代表本轮线程片段结束。

## 原指令与连续测试

[原始记录](mouse-worker-runtime-original.jsonl) · [逐项比较](mouse-worker-runtime-comparison.json) · [原入口字节与源码摘要](mouse-worker-runtime-exact.json)。六类入口各 1,024 组，共 **6,144 组 / 1,192,039 条原指令步**，RAM、RTC、AUX、RADIO、TIMER、NVIC、clock、优先级及边界参数全部一致：

- 2,048 组完整函数返回：wake 与 delayed-work expiry。
- 753 组到达工作线程下一循环头，不算完整线程退出。
- 3,291 组到达 `0e089d4c` CPU 切换请求入口；原函数及 C 均停在调用前。
- 52 组基础 API 到达扫描回调入口；支持该回调的扩展组合另以 1,024 组验证，未把基础接口边界当作全局未识别函数。

首次 5,120 组验证随后扩充为本 6,144 组，合计只计本数据集一次。

[连续组件](mouse-worker-continuous-comparison.json)在三种优先级下执行 **192 轮等待 → 延迟工作入队并唤醒 → 工作回调**。测试在已到达的真实 CPU 边界显式交接 current-thread 输入，共 384 次；因此它验证队列与组件状态连续性，不证明真实异常调度或 CPU 上下文保存/恢复。延迟回调到达也由环境显式提供。

## 注册关系与下一边界

四个原延迟工作 schedule/reschedule 入口 `0e095478/0e0954e0/0e09554c/0e0955c4` 会将 `0e095255` 注册到 timeout；相应 literal 字节及原始指令导出已绑定摘要。这里恢复了到期消费者，尚未把四个生产入口一并实现。

先前 RTC 测试用 `23028c54` 作为未知函数指针验证参数保留。当前原函数确认它是位图分配辅助函数，不能据此将它列为真实待恢复 RTC 用户回调。`23025f78` 则调用既有断连主体，仍需将其 timer 组合路径接通。

原 `0e089d4c` 会写当前线程保存字段、请求 PendSV、降低 BASEPRI；向量表偏移 `0x38` 指向 `0e089dcc`。本轮只定位并保留这两处边界，没有执行 PendSV、异常返回、并发或真实线程切换。pend 的切换后输出参数尾段也未假造执行。

复验：`verify_mouse_worker_runtime.py`、`test_mouse_worker_continuous.py`；[本轮完整性](phase-worker-runtime-integrity.json)。全部是主机内存模型；没有设备写入或无线实测。
