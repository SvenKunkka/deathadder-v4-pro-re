# 接收器周期服务与 RTC 通道恢复（官方1.20）

恢复启动入口 `0E05BE20`、首次登记 `0E05BE4C`、周期回调 `0E05BDE0` 及其完整软件辅助链。新增 **1,792组原指令对照通过**（237,496步）：1,789组完整返回，3组在测试注入的未知RTC回调前停止。比较完整128 KiB RAM和两个4 KiB外设窗口、返回值、优先级及未知回调的五个参数。

[代码](../recovered-code/portable/receiver_periodic_service.c) · [接口](../recovered-code/portable/receiver_periodic_service.h) · [原字节和来源](receiver-periodic-service-exact.json)

已恢复的具体行为：

- 通道分配从可用位图中取最高有效位，上层最多允许3次成功；失败返回 `-12`。初始化即使分配失败，也保留原固件后续寄存器写入，未自行修正行为。
- 初始化写入基址 `53014000` 的寄存器；周期回调将 `6E524635` 写入偏移 `600`，读取当前RTC并安排100,000 tick之后的回调。这里不声称已验证外设实际复位或看门行为。
- 完整恢复相对/负编码期限转换、通道有效性与占用检查、回调槽登记、比较值设置及中断使能状态恢复。比较高字按原代码保留20位。
- 新增 `rr_receiver_rtc_known_callbacks`，在同一个RTC分派过程中执行周期服务与此前五个已恢复应用timer回调；未知回调继续保留入口边界。旧接口没有修改。

[新增原指令对照](receiver-periodic-service-comparison.json) · [应用回调2,048组回归](receiver-known-callbacks-regression.json)

连续验证从通道分配和首次登记开始，经128次显式RTC事件，同时运行128次周期服务和128次应用timer回调，逐次检查寄存器值、事件清除、回调身份、状态计数及下次比较时间。[连续组件结果](receiver-periodic-service-continuous-comparison.json)。系统时钟通道和空调度器上下文显式初始化，时钟/事件/使能读回由测试提供；不代表完整开机或真实硬件中断。

累计 **55个C单元、76份数据集、168,960组原指令输入**；旧回归和连续组件不重复计数。当前主机库 `recovered-code/portable/build/librr_recovered55.dylib`。尚需恢复其余启动入口、延迟工作、跨核来源、线程续跑与真实空口互通。没有接收器，不影响本阶段静态与软件模拟工作，但不能验证两端实机通信。
