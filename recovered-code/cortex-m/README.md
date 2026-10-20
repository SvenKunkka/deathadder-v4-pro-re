# 鼠标 1.20 原生上下文切换片段

[mouse_context_switch.S](mouse_context_switch.S) 恢复 Cortex-M33 Thumb 的 CPU 请求、选择线程、PendSV 和 PSPLIM 设置。`make` 使用本机已有 GNU Arm 工具输出 ELF 和二进制；[链接布局](mouse_context_switch.ld)将片段固定到官方鼠标 1.20 的原地址。

与官方镜像比较的 200 字节完全一致。中间 304 字节仅为保持偏移的填充，不是已恢复代码；该输出没有完整向量表、启动、HAL 或其他程序，不能当作完整固件使用。

[行为与验证范围](../../analysis/mouse-context-switch-exact.md)。原指令模拟验证到 PendSV 末尾 `BX LR` 前；异常入栈/出栈、FPU/安全态和真实硬件时序未验证。C 对照模型位于 [portable](../portable/mouse_context_switch.c)。
