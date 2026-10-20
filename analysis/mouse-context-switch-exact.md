# 鼠标 CPU 切换请求与 PendSV 软件主体

本轮同时交付 [C 模型](../recovered-code/portable/mouse_context_switch.c)、[接口](../recovered-code/portable/mouse_context_switch.h)和 [原生 Thumb 汇编](../recovered-code/cortex-m/mouse_context_switch.S)。原生源码按已核验的鼠标 1.20 地址绑定构建；它仍是完整工程中的片段。

|原入口|已恢复的软件行为|
|---|---|
|`0e089d4c`|保存当前线程优先级于 `+88`，结果置 `-11`，写 ICSR 请求 PendSV，BASEPRI 清零，再读取当前线程结果。C 的独立入口明确假设期间没有异步中断|
|`0e089d84`|将 `7664` 选中线程写入 `7654`，写 ICSR 清请求位，更新 `6d30` 线程局部指针，读取并清除目标线程保存优先级，恢复 BASEPRI|
|`0e089dcc`|保存当前线程 r4–r11 与 PSP 至 `+30…+50`，执行选择，恢复目标线程寄存器/PSP，设置 PSPLIM；C 和原指令比较停在末尾 `BX LR` 前|
|`0e089f3c`|从线程 `+74` 取栈下限，写 PSPLIM|

线程切换前后 MSP 的真实临时写入也保留：请求写 `SP-4`，选择函数写 `SP-8/SP-4`，PendSV 最后将新线程指针和 EXC_RETURN 写入同一两处。C 接口显式接收 `[MSP-32,MSP)`，避免将临时栈痕迹遗漏为未比较内存。

## 机器码与原指令验证

[原生构建结果](mouse-context-native-comparison.json)：GNU Arm assembler/linker 构建成功，**200 字节**与官方镜像逐字节相同，包括四个函数的所选代码段、跳转、常量和 `BX LR` 本身。片段中间为保留原偏移而填充的 304 字节没有恢复，明确排除比对；该片段不能作为完整可烧录镜像。

[原指令输入](mouse-context-switch-original.jsonl)与 [C 比对](mouse-context-switch-comparison.json)：四类各 512 组，共 **2,048 组 / 42,496 条原指令步**。其中 1,536 组正常返回，512 组 PendSV 停在 `0e089e06` 的异常返回指令前。全部 r0–r12、SP/LR/PC、PSP/PSPLIM/BASEPRI、CY/ZR/NG/OV/Q、64 KiB RAM、4 KiB SCB 和 32 字节 MSP 临时区一致。覆盖切到其他线程及选中自己两种情况。

PSP 使用 Ghidra 内建 getter/setter 的同一 CPU 状态；BASEPRI 读取接到内建 setter 的状态。Ghidra 缺少 PSPLIM 操作，因此只为原 `MSR PSPLIM` 提供寄存器赋值，不模拟越界保护和异常。没有改写目标指令或模拟被调函数成功返回。

[连续组件](mouse-context-continuous-comparison.json)另以四种初态运行 256 次切换请求和 256 段 PendSV 主体，核对保存/恢复寄存器、栈指针、TLS、优先级与 ICSR 写值。中间线程执行和 handler 入口由测试明确提供，不证明异常栈帧产生或真实并发运行；不计入新增原指令输入数。

## 边界与复现

硬件异常入栈、EXC_RETURN 解码与出栈、FPU/安全态、抢占时序，以及 pend/worker 切换后的真实恢复执行，仍未验证。原生汇编包含异常返回指令，机器码一致不等于硬件执行已验证。ICSR 使用写快照，不把写入值当作真实寄存器读回。

`verify_mouse_context_switch.py` 编译 C、比对输入并构建/核验原生字节；`test_mouse_context_continuous.py` 运行连续组件。[本轮完整性](phase-context-switch-integrity.json)。完整无线固件目标仍未完成，未进行设备写入。
