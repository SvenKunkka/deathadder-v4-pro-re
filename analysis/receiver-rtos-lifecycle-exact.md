# 接收器1.20：信号量、等待线程交接与断连通知

新增 `receiver_rtos_lifecycle.c/.h`，把原来停在信号量入口的mode4断连路径延伸到真实信号量/就绪队列操作及type2消息提交。没有执行设备代码或USB/RF动作。恢复范围包括串行内存语义；不等于完整RTOS线程调度器。

## 原指令验证

- 1,536个独立原入口输入：semaphore give、queue put、purge、type2 notification各384。完整返回1,418组；118组准确停在原调用入口，并比对此前所有副作用。其中活动timeout取消60组、时间片新建27组、线程态真正切换31组。
- 比较128KiB完整RAM（包括23015760消息环）、原queue put返回值、CPU优先级、实际暂停PC及r0。不同初始BASEPRI和IPSR作为输入；getter连接模拟器内建setter的同一CPU状态。无成功函数桩。
- 另256个从完整TIMER ISR `23021BBC` 开始的断连输入，执行原计数/配置回退、实际信号量give、等待线程就绪、通知queue put/purge，均完整返回。包括无等待/有等待者、队列空/部分/满和指针回绕。
- **这256组的通知尾部24B由原执行抵达230254F8时观察到的旧栈字节显式提供给C。** C恢复的是这些字节被复制的行为；没有恢复CPU寄存器压栈导致的残留生成过程。这属于有明确隐含栈输入的状态投影，不能宣传为独立重建全部ABI/栈行为。

独立入口执行322,614条原指令；完整TIMER路径执行168,370条。脚本为 `verify_receiver_rtos_lifecycle.py` 和 `verify_receiver_disconnect_lifecycle.py`，后者复用前者编译的真实模块。比较结果和输入来源分别保存在同名comparison JSON；两组输入不重叠。

## 信号量与等待线程

`0E06D0D0`首先锁定BASEPRI，再通过`0E06DF70`取等待者。没有等待者时，count仅在count!=limit时加1；它并非通用的饱和小于判断，count已经超过limit时仍递增，32位按原指令回绕。

有等待者时，先从等待链表移除，清前后指针、等待标志bit1及wait-queue指针，然后取消该线程timeout。未活动timeout的真实函数自然返回−22；若timeout活动，则本模块准确停在`0E06E768`调用前，保留已经完成的摘链副作用。

无活动timeout时，线程返回槽+8C写0，检查线程flags和timeout。满足就绪条件时置bit7，并按**有符号8位优先级**稳定插入ready链表：同优先级排在已有项后。之后按当前线程flags、候选timeout和当前16位priority/preemption字段选择下一线程。候选变化时执行已有时间片的取消检查并清时间片标志；需要新时间片时在`0E06E648`前保留边界。

`0E06E078`仅在原优先级为0、IPSR=0且next!=current时进入实际切换入口`0E0611CC`。原汇编先把IPSR读入r0，因此切换边界r0为0，**不是反编译器显示的queue/锁对象参数**；差分发现并纠正了这一点。中断上下文里的就绪队列变更已执行，但自动异常返回后的调度未模拟。

## 消息直交、环缓冲和purge

`0E06CBDC`在count<capacity时先取等待线程；有等待者则把完整36B直接复制到其接收目标，再写返回槽和就绪队列，环缓冲不入队。没有等待者才复制到write指针、推进36字节、到end时回start并增加count。满队列且timeout=0时原返回−35。

`0E06CD54`依次移除所有等待者，给返回槽写−35，执行就绪处理，随后count=0、read=write。遇到实际未恢复的timeout/时间片/切换入口会保留此前副作用；不是预检回滚。

断连生产者`230254F8`初始化type=2、peer/word共12B，消息却复制36B；**尾部是24B旧栈，不是之前type5通知的20B**。若put失败，purge后重试。接口保留调用者给定的旧栈字节，未擅自补零。

## 接到mode4断连

`rr_receiver_timer_mode4_lifecycle`先执行既有 `rr_receiver_timer_mode4`。它原本在`0E06D0D0(23001C54)`前暂停；扩展接口继续实际信号量逻辑，再构造peer0及context+0A的32位word，提交type2通知。

旧接口和2,304组原定时器边界测试保持不变，新接口有新的CPU上下文及24B栈尾参数。数据RAM须有128KiB容量，不能沿用旧接口只分配64KiB的调用缓冲。消息对象仍是已确认的36B×5布局。

## 明确边界

- 活动timeout取消、时间片新建、真实线程态context switch均为实际入口暂停；尚未恢复这些动作及其后继续运行。
- 任意损坏链表、域外地址和任意队列布局不是等价域。模型−1是宿主域错误，1是暂停；并非设备错误码。
- CPU模型仅处理串行priority/IPSR输入，不模拟抢占、PendSV或中断自动返回。
- 已提交断连消息不证明管理线程已消费；其业务后续仍待接线。未进行真实接收器或RF验证。
- 原入口数据与固件SHA、源码摘要可由JSON复验。官方1.20载荷与鼠标版本号匹配，不等于接收器实机dump。

## 原字节入口

|地址|镜像偏移|入口16B|作用|
|---|---|---|---|
|0xe06d0d0|0x190d0|`38b50446eff31185402383f31288bff3`|semaphore give|
|0xe06df70|0x19f70|`f8b5eff31185402383f31288bff36f8f`|waiter dequeue|
|0xe06dd24|0x19d24|`10b5eff31184402383f31288bff36f8f`|ready critical section|
|0xe06da0c|0x19a0c|`90f90d30427b002b03dbd30601d18369`|priority ready insertion|
|0xe06d9cc|0x199cc|`38b50e4d2b4653f8184f9c4214d09cb1`|next thread selection|
|0xe06e4ec|0x1a4ec|`70b5144b144e1d7c044605eb450306eb`|timeslice reset|
|0xe06e078|0x1a078|`49b9eff3058030b9054b5a699b689a42`|unlock or context switch|
|0xe06cbdc|0x18bdc|`2de9f04104460d46964682b000f10807`|message put|
|0xe06cd54|0x18d54|`f8b5044600f10806eff31187402383f3`|message purge|
|0x230254f8|0x5c94|`0221024610b58ab000680191516802ab`|disconnect type2 producer|
|0x23024c2a|0x53c6|`0024104b2246c3f804411149c3f80441`|mode4 disconnect prefix|
|0x230221a4|0x2940|`40f684710122034b01fb00331a710248`|disconnect flag and semaphore|
