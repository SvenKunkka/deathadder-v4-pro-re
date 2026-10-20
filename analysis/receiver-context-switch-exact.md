# 接收器 CPU 切换恢复（官方 1.20）

已恢复请求切换、选择线程、PendSV 软件主体与 PSPLIM 设置，新增 2,048 组原指令差分通过。比较所有通用寄存器、SP/LR/PC、PSP/PSPLIM/BASEPRI、五项标志、128 KiB RAM、4 KiB SCB 快照与32字节临时栈。1,536组正常返回，512组停在异常返回 BX LR 前。

|原地址|恢复行为|
|---|---|
|0E0611CC|保存原优先级，设置等待结果 −11，请求 PendSV；无中断模型下返回 −11|
|0E061204|BASEPRI_MAX=0x40；当前线程取自 2300717C，写入 23007170；更新 TLS 23006930，并恢复线程优先级|
|0E06124C|保存旧线程 r4–r11 与 PSP，选择线程，恢复新线程上下文及 PSPLIM|
|0E0613A4|从线程 +0x74 设置 PSPLIM|

[C 实现](../recovered-code/portable/receiver_context_switch.c)与[接口](../recovered-code/portable/receiver_context_switch.h)已纳入全部51个C单元的严格主机编译和链接。

[原生汇编](../recovered-code/cortex-m/receiver/receiver_context_switch.S)重新汇编后，所选200字节与官方固件完全一致。中间280字节占位填充不计入恢复；固定地址片段并非完整固件映像。

[连续组件测试](receiver-context-continuous-comparison.json)完成4个初态、256段请求和256段PendSV；[互斥锁接线](receiver-mutex-context-comparison.json)复用392个已有原指令样本的真实调度边界，恢复C锁代码的输出直接进入请求/切换主体，不替换选中线程或队列状态。两类组件测试不增加原指令输入计数。

运行中的寄存器、PSP及异常处理入口由测试明确给定；请求在静止中断模型下运行，随后显式调用处理器主体。没有执行硬件异常入栈、EXC_RETURN出栈、线程实际续跑、并发或空口通信。不能由该结果声称锁已在真实线程间完成唤醒，也不能声称完整无线源码已经恢复。

[原指令对照结果](receiver-context-switch-comparison.json) · [汇编字节比对](receiver-context-native-comparison.json) · [绑定证据](receiver-context-switch-exact.json)
