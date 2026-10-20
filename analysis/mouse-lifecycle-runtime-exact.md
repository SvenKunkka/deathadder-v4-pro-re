# 鼠标断连、ACK 与 timer stop 的实际接入

恢复 [mouse_lifecycle_runtime.c](../recovered-code/portable/mouse_lifecycle_runtime.c) / [接口](../recovered-code/portable/mouse_lifecycle_runtime.h)，三个原入口为直接断连 `23022D88`、ACK 断连 `23025C2C` 和 class3 ACK 回调 `23025EB4`。

新入口接入 timer stop 的真实等待线程摘链、就绪和调度路径。直接断连保留原因半字、连接状态、时钟订阅、三种无线模式清理和重复停止 timer1540 的次序；ACK 先停 timer15B0，再读取原因字节；class3 回调指针只在下层完整返回后清零。真实 CPU 请求和未知 stop 回调发生时立即返回边界，保留原来的此前写入，未伪造其后清理或回调成功。

## 原指令验证

[比对结果](mouse-lifecycle-runtime-comparison.json)：三个完整入口各 1,024 组，共 3,072 组、1,260,296 条原始指令。2,816 组完整返回，42 组停在 CPU 请求入口，214 组停在人工未知 stop 回调入口。所有 RAM、RTC、RADIO、TIMER、AUX、NVIC、CLOCK 快照以及 BASEPRI 和边界参数一致。人工回调地址是测试边界标识，不是实际注册证据。

覆盖活动/非活动定时器、0/1/2 等待线程、线程自身 timeout、优先级与时间片、class 拒绝、空 ACK 回调、已知 ACK 回调以及早期退出后指针保留。测试无自主时钟和中断，没有执行真实设备通信。

## 实际停止回调注册检查

[原字节与调用位置](mouse-stop-registration-evidence.json)证实：静态 timer1540、1578、15B0 的 stop 指针初值均为零。导出交叉引用中的两个 timer-init thunk 直接调用位置也传入零：timer1B80 显式由零寄存器传参；timer1B48 使用标志字节作为 r2，且只在该字节为零的分支调用初始化。后者被反编译器省略了第三参数，已用原汇编确认。

该结论限于这三份初始化数据和两个直接调用位置，不能排除后续写指针或间接初始化。尚未识别实际非零 stop 回调，不能把人工样本地址当作产品行为。

## 剩余范围

旧接口保持其冻结行为。IRQ、扫描和 RTC 适配仍需接入新 runtime 接口；CPU/未知回调边界后的调用栈续接尚未恢复，不能从头重调用当作续接。完整通信固件构建、跨核/USB、接收器顶层与真实 RF 验证仍未完成。本轮未写入设备。
