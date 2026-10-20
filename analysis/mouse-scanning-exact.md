# 鼠标无线扫描、超时与重启链恢复（1.20）

状态：新增`mouse_scanning.c/.h`，6,144组原始Thumb指令对比通过。它恢复扫描相关软件路径，尚不证明完整无线固件或真实射频互通。

## 恢复范围

|原始入口|恢复行为|
|---|---|
|23022620 work3858|按27BB/297C门控处理扫描请求；配置RADIO mode2和定时器，启动扫描|
|23022CF0|重置总扫描次数1000、进入state19，更新clear订阅与IRQ40，启动timer1540，duration32/period32|
|2302253C|16位停留计数；首周期启用接收；超过7后关闭RADIO并轮换四项发现频道|
|23022310 timer1540|state19/20扫描；state22/23握手重试；等待倒数/重试阈值触发reset；总超时后重新配置发现模式、初始化peer0 TX队列并提交work3858|
|230218EC及依赖|发现模式包配置、地址、CRC、RADIO/NVIC最终写入与应用字段更新|
|组合timer expiry|从0E096950执行周期重插、status更新、真实扫描回调及原等待者尾段|
|组合work thread|从0E09504C取出work3858并执行扫描回调、原flush/cancel清理，直到下一循环或真实RTOS边界|

发现频道表原字节给出的索引为37、38、22、39，频率寄存器值为2、26、50、80。停留、频道索引、握手等待和重试计数按原16位回绕处理；总扫描计数按32位回绕。work3858强制重扫路径会向未对齐的2A1A写入4字节，未简化为16位字段。扫描起始函数不自动启动TIMER020任务，接收阶段的定时回调才会写入该任务。

总超时路径执行两次timer1540 stop，再执行完整已恢复的disconnect（内部还有原有stop调用），随后重设发现模式、peer0队列并提交扫描工作。没有把这些重复调用折叠为一条假定等价操作。发现配置的局部参数只读取已由原调用方设置的地址和mode字段，本路径不依赖未初始化栈尾。

组合入口先调用保留的旧API，到达其真实未知回调边界后执行扫描回调和尾部；不会重入已产生副作用的前缀。旧timer/work API及原验证记录保持不变，调用方必须显式选择新增组合入口。

## 原指令验证

共6×1,024组：直接work3858、直接扫描timer回调、直接频道推进、直接扫描启动、完整timer1540 expiry、实际work3858线程分派。共执行1,300,855条原指令，比较全部64KiB RAM、4KiB RADIO、1536B TIMER020、4KiB RTC、16B辅助寄存器、4KiB NVIC/SCB、8B时钟寄存器、BASEPRI及有效待处理入口参数。

- 5,116组完整函数返回。
- 439组工作线程到达下一循环头，不能计作线程结束。
- 589组真实边界：4 CPU切换、17 drain wake、438 yield、130 pend。

没有成功返回空桩。NVIC/MMIO比较证明最终寄存器快照，不证明真实中断递送、寄存器别名硬件语义或写入间隔。原回调r0与恢复API的状态码不是同一契约；API返回0表示软件路径完成。

## 连续组件验证

四个起始频道各运行两轮总扫描超时，共8,000次显式应用定时回调、8次真实工作线程组件分派。每轮验证四频道顺序、1000次总超时、活动timer取消、发现模式重设、work入队、线程取出、扫描重新启动以及工作标志清理。

这是C组件组合，不新增原指令输入数。时钟快照由测试提供；没有自动RTC到期、真实中断、接收器或无线报文。

## 文件与复验

- [字节来源、摘要与完整比较](mouse-scanning-exact.json)
- [原指令差分结果](mouse-scanning-comparison.json)
- [连续超时重启结果](mouse-scanning-continuous-comparison.json)

从报告根目录执行`rtk proxy python3 analysis/verify_mouse_scanning.py`，再执行`rtk proxy python3 analysis/test_mouse_scanning_continuous.py`。Ghidra捕获脚本为`ghidra-scripts/EmulateMouseScanning.java`，使用既有只读mouse120工程、Java25及共享原生ArmCpuState的BASEPRI模型。

## 仍未完成

RTC事件23029A30→announce0E09668C尚未接入，真实CPU切换及worker等待/让出/排空路径仍有边界；timer-stop的未知回调与等待路径也仍有限制。接收器顶层初始化和调度、USB/跨核/持久化及真实射频时序尚未完成。
