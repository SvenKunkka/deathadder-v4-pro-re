# 鼠标无线启动、线程创建及等待

2026-10-20，3,712组原始指令输入与恢复C逐项比较通过，执行5,672,640条原指令。2,465组完整返回，1,247组停在真实CPU请求E089D4C入口。没有接收器、设备写入或实际射频验证。

代码：[mouse_wireless_startup.c](../recovered-code/portable/mouse_wireless_startup.c) / [接口](../recovered-code/portable/mouse_wireless_startup.h)。依据：[原始指令映射](mouse-wireless-startup-map.md)。验证：[差分结果](mouse-wireless-startup-comparison.json)、[源代码及数据绑定](mouse-wireless-startup-exact.json)。

|入口|输入数|完整返回|CPU请求|
|---|---:|---:|---:|
|21150无线启动|512|256|256|
|25D1C工作/线程建立|512|495|17|
|22D68扫描工作项|512|512|0|
|E0957A8创建线程|640|635|5|
|E095BF4启动线程|512|512|0|
|E0960A8按tick等待|512|0|512|
|E096164公开sleep|512|55|457|

每组比较完整128KiB数据RAM、RADIO/TIMER/NVIC/DPPI/clock/RTC六个4KiB窗口、最终BASEPRI、实际返回值或CPU请求及参数。另检查1,408次原始thread-create ABI参数、439个睡眠deadline寄存器。新增128个创建线程输入使用非零保留字段，确认TCB+6C字节清零没有覆盖+6D..6F；线程帧未写字段也保留原始内容。

原始栈+14的对齐空位没有被当成delay。first-use链在CPU切换前保留已经发生的工作和状态写入，不提前执行应用初始化或key安装；779A非零路径完整调用已有259A4恢复实现。

`rr_mouse_wireless_startup`返回1表示暂停在CPU请求，**再次调用不是续跑**。真实睡眠后E096110返回剩余tick、公开sleep换算及21182→259A4续接尚未在这个接口中实现。原始CPU寄存器/栈作为诊断记录保留；主机C只比较语义效果，未验证原生调用栈等同性。原始stack_before初始化576B，escaped_stack中超出其上界的诊断字节没有初始化，不纳入验证结论。

边界：特权、串行、有限链表；RTOS对象在低64KiB，创建栈在128KiB内。外设SET/CLR和屏障不生成真实硬件副作用。没有自动时间推进、IRQ、异常入栈/出栈、线程续跑或空口交互。原始指令数据为合成状态覆盖，不能解释为随机场景可靠性或硬件性能数据。

下一步应恢复真实等待后的续段，接入线程timeout到期/就绪与已有CPU上下文模型，随后追溯2869C模式入口及身份A001/速率A003配置来源。目标仍是完整通信代码，当前仅补齐首次启动的软件前段。
