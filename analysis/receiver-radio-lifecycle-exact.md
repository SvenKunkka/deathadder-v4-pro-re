# 接收器 RF 测试模式停止、初始化和日志续接

2026-10-19，阶段 62。依据官方 1.20 接收器无线核原始指令恢复。本轮新增 7,552 组原指令输入、5,251,707 条 Thumb 指令对照全部通过；其中 6,838 组完整返回。此前 6,272 组引擎与控制流程回归通过，不重复计入新增输入。累计 65 个 C11 单元、86 份数据集、201,984 组原指令输入。

这些是限定入口和输入语境下的离线等价验证。尚未形成完整可启动固件，也没有接收器实机或空口验证。

## 实际补齐的行为

- `23021F04`：关闭已分配的 DPPI 通道、屏蔽无线 IRQ、停止正常无线 TIMER020、清除订阅及无线状态。
- `23021F88`：真实线程挂起软件逻辑、两组 peer 无线停止、随后执行停止尾段；遇到真实 CPU 切换入口 `E0611CC` 保留边界。
- `23021D9C/23021DB0`：正常无线暂停及状态复位包装。
- `E05D1AC`：构造 1 MHz 测试 TIMER021 配置，安装 `E05CD04` 回调，设置 IRQ 优先级，分配 GPPI 句柄；保留初始化错误后仍尝试后续初始化的原行为，以及 GPPI 失败的 -14 返回值。
- `E0612F0`：IRQ 优先级写入，包括负 IRQ 编号的系统优先级路径。
- `E05D634`：本模块使用的七个固定格式字符串、实际默认无输出回调及格式化返回字符数；未知动态输出回调保留入口。
- 新 `*_with_dependencies` 接口把上述实现接入测试引擎及测试控制流；旧接口保留原边界语义，旧源码快照保存在 [历史文件](receiver-test-engine-v1-before-lifecycle/manifest.json)。

正常无线 TIMER020 基址为 `53028000`，测试 TIMER021 为 `53029000`，两者分别建模，不能混用。原代码会清零或覆盖的状态均按实际顺序保留。

## 日志为何可以继续执行

固件初始化数据把 RAM `23000494` 指向 Thumb 函数 `E05D625`，实际入口 `E05D624` 为返回零的无输出函数。原 `E05D634` 经真实 formatter `E06EEA8` 调用此函数；本次原指令执行没有替换日志调用结果。

3,328 组直接日志样本覆盖七个精确 ROM 格式，3,072 次完整返回和 256 次改写回调后的真实入口边界。两个 `%hhi` 格式分别覆盖全部 256 个低字节；`%d` 覆盖 1,284 个不同输入。仅声明这七个格式的实现，不声明通用 printf 已恢复。配置被改为其他奇数 Thumb 指针时，代码停在真实目标入口；空或偶数指针不在已支持范围。

## 原指令验证

|数据集|输入|原指令步数|完整返回|剩余边界|
|---|---:|---:|---:|---|
|[停止、初始化、引擎及控制链](receiver-radio-lifecycle-comparison.json)|4,224|1,936,240|3,766|377 次硬件事件等待、12 次 CPU 切换、69 次动态日志回调|
|[直接日志](receiver-radio-log-comparison.json)|3,328|3,315,467|3,072|256 次动态输出回调|
|[旧引擎回归](receiver-radio-engine-phase62-regression-comparison.json)|4,224|719,989|沿用阶段 61 范围|不新增计数|
|[旧控制流程回归](receiver-radio-flow-phase62-regression-comparison.json)|2,048|309,776|沿用阶段 61 范围|不新增计数|

逐字节比较 128 KiB RAM、七个 4 KiB 外设寄存器快照（直接日志为六个），同时比较 BASEPRI、具有定义的返回值、实际边界参数及显式事件次数。CPU 局部栈不计入投影状态。

887 次 RADIO EVENTS_DISABLED 是测试明确提供的输入；未提供时停止于原轮询 PC。没有把写 TASKS_DISABLE 自动当作硬件已完成。模拟器内存屏障按顺序执行模型处理，不证明并发或总线顺序。GPPI 仍限定同描述符 RF 域，不把跨域分配或寄存器 SET/CLR 自动效果当作已实现。

## 可复用文件

- [生命周期实现](../recovered-code/portable/receiver_radio_test_lifecycle.c) 与 [接口](../recovered-code/portable/receiver_radio_test_lifecycle.h)
- [日志实现](../recovered-code/portable/receiver_radio_test_log.c)
- [测试引擎及可选依赖接口](../recovered-code/portable/receiver_radio_test_engine.h)
- [完整证据与哈希](receiver-radio-lifecycle-exact.json)
- [原指令模拟脚本](../ghidra-scripts/EmulateReceiverRadioTestLifecycle.java) 与 [差分验证脚本](verify_receiver_radio_test_lifecycle.py)
- [当前构建说明](../recovered-code/portable/README.md)

下一步仍包括把厂商命令/工作线程的真实调用接入这些接口、鼠标侧完整命令处理、实际 CPU 切换后的栈续接、跨核及真实空口时序。鼠标厂商入口的新静态定位见 [命令发现报告](mouse-vendor-discovery.md)；该报告不计入本轮执行验证数量。
