# 接收器四个应用定时器回调恢复（官方 1.20）

四个静态注册回调已恢复为 C，并接入 RTC → clock → timeout → 通用 timer → 用户回调链。新增 **6,144 组原指令输入对照通过**，共 3,024,378 步原指令；完整返回 5,719 组，其余在真实 CPU/复位入口或注入的未知 stop 回调前停止。未执行设备写入或复位。

[实现](../recovered-code/portable/receiver_application_timers.c) · [接口](../recovered-code/portable/receiver_application_timers.h) · [原字节与来源](receiver-application-timers-exact.json)

|回调|恢复行为|
|---|---|
|230255D0|登记 100,000 tick 的停止定时器，初始化无线并恢复相关线程、发出信号量|
|230255F8|登记 400,000 tick 的启动定时器，停止无线；连接存在时清状态并生成断连通知|
|23025640|两个计数比值取低 8 位；按周期登记 class3 的 AC 报文，并生成 `05 FE 72` 统计 USB 报告|
|230256E8|按阈值更新状态码，处理断连倒计时和 timer-stop，投递配置事件4；连接看门计数归零时停在复位入口|

具体周期单位保留为固件 tick，未由这些测试换算实际射频时间。各统计字段的产品业务名称尚不能仅凭地址确定。

直接回调对照 4,096 组，完整 RTC 调用链 2,048 组，均比较 128 KiB RAM、八个 4 KiB 外设窗口、8 字节设备 ID、优先级和入口边界；组合入口额外检查 pending 参数。旧通用 timer 的 8,192 组原指令输入及 128 轮断连连续路径回归通过，回归未重复计入总数。

[直接结果](receiver-application-timers-comparison.json) · [RTC组合结果](receiver-rtc-application-timers-comparison.json) · [旧行为回归](receiver-timer-user-handlers-regression.json) · [旧连续路径](receiver-timer-user-handlers-continuous-regression.json)

连续组件共输入 193 次 RTC 事件，完成 32 次启动和 32 次停止、64 次统计回调（16 条统计 USB 报告）、64 次状态回调及配置事件收取，最后核对一次复位入口边界。事件4的 32 字节旧栈尾部显式提供，保留原内容；没有把这些字节伪造成零，也没有恢复完整 CPU 栈生成过程。[连续结果](receiver-application-timers-continuous-comparison.json)

新组合验证脚本曾误分配 2 KiB 外设窗口，造成主机越界。已保存错误批次，修正为 4 KiB 后重新执行全部组合输入；错误批次不计数。独立 sanitizer 尝试未产生结果，不宣称通过。[执行说明](receiver-application-timers-execution-notes.json)

原通用 timer 的 C/h 已保存于[基线归档](receiver-timer-v1-before-appcallbacks/manifest.json)。其旧接口边界不变，新增可选用户回调处理器；更早 RTC 基线另行保留。累计 **54 个 C 单元、75 份数据集、167,168 组原指令输入**。当前主机共享库为 `recovered-code/portable/build/librr_recovered54.dylib`，不代表可烧录 MCU 工程。

[原静态 timer 表](receiver-application-timer-map.json)中的五个已知用户回调现均有恢复实现；该旧表“仅1A30已接入”的进度描述已由本报告更新。未知动态回调、延迟工作、RTC其余回调、完整启动、跨核来源、硬件异常返回与真实空口验证仍未完成。用户暂时无接收器，因此此阶段不包含两端实机验证。
