# 接收器握手末端：原指令执行与 C 扩展

新增 `portable/handshake_notification.c/.h` 的 `rr_dongle_handshake_step`，在既有接收器握手入口上补上 pending 非零的完成分支：构造事件5、入队、必要时purge后重试、清slot标志、按另一slot状态清RXADDRESSES bit0、完成状态推进。普通路径复用既有恢复模块。

## 验证

`EmulateHandshakeNotification.java` 从原始 `230223F0` 入口执行，并实际进入 `23025580`、原RTOS queue-put/purge代码及 `23020BD4`，没有把这些目标函数替换成宿主回调。原镜像SHA、完整Flash及运行RAM复制在执行前逐字节核验。

**96组原指令/C差分通过**，包括pending为零14组、非零82组；队列初始数量0..5、写指针回绕、两slot状态、原栈随机尾字节及接收地址掩码。14组覆盖队列满后purge再入队。比对全部224字节slot、40字节队列对象、180字节环形缓冲、RXADDRESSES及返回值。消息尾部20字节由明确的先前栈内容输入，与原指令复制结果一致，没有补造为0。

### 模拟器支持的范围

Ghidra 12.1.3原本有 `setBasePriority`，缺 `getBasePriority`。最终脚本通过局部反射找到该模拟器ARM库的同一 `ArmCpuState`，为缺失的读操作返回其实际BASEPRI。初始值覆盖0、0x20、0x80，函数结束均恢复原值；没有使用与真实setter脱离的影子变量。另补IPSR=60，作为RADIO IRQ语境的给定输入。

早期日志含缺失userop、旧callback接口和影子BASEPRI实验，不能用作最终验证。当前正式日志为 `handshake-notification-verified-v4.log`，输出为 `handshake-notification-original.jsonl`。Ghidra保留的ISB TODO警告说明没有模拟指令屏障的并发/缓存效果；这里是串行、无缓存演化的内存模型。

## 明确的代码边界

当前队列上下文没有等待线程。若出现等待线程，恢复模块返回 -2 标示尚未实现，不冒充固件行为；该路径涉及直接复制到等待线程、唤醒和RTOS调度，仍需恢复。队列操作之间的中断/线程交错也未模拟。原固件的put与purge不是整体原子事务，不能由本模型得出任意并发情况下的等价性。

无设备I/O、刷写或保护绕过。此处验证的是所列软件路径，不是实机射频时序。复验：`rtk proxy python3 analysis/verify_handshake_notification.py`。
