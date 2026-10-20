# 接收器工作入队、延迟和取消恢复（官方1.20）

恢复工作入队、显式/默认队列包装、四种延迟登记与重排入口、延迟到期、取消及两种初始化，共11类入口。新增 **3,328组原指令输入通过**（424,276步）：3,326组完整返回，2组停在真实CPU请求入口。额外2,048组已有应用timer输入经过新统一RTC入口回归通过，不重复计数。

[实现](../recovered-code/portable/receiver_work_queue.c) · [接口](../recovered-code/portable/receiver_work_queue.h) · [原字节和来源](receiver-work-queue-exact.json)

已恢复行为包括正在运行、已排队、正在取消、延迟等待等状态位的处理；队列拒绝结果、所有者选择、链表追加、等待者摘链、活动timeout撤销和重新就绪；立即提交、延迟登记、活动重排，以及取消头/中/尾节点。默认队列地址为 `23002B18`，USB专用工作队列初始化使用 `23002170`。

延迟到期入口 `0E06D3A4` 清除等待标记并调用真实入队链。新入口 `rr_receiver_rtc_work_dispatch` 将它接入RTC→clock→timeout链，并保留此前周期服务和五个应用timer回调。未知回调和CPU/复位条件仍保留入口边界。此前55个C单元没有修改。

[2,816组入口对照](receiver-work-queue-comparison.json) · [512组完整RTC链对照](receiver-work-rtc-comparison.json) · [2,048组应用回归](receiver-work-app-regression.json)

连续组件验证64轮登记和活动重排，经过64次实际延迟到期入队，再用原取消API移除队列项；另64次RTC事件执行应用timer和周期服务，合计128次显式RTC事件。每轮检查队列头尾、标记、下次比较时间及回调次数。[连续结果](receiver-work-continuous-comparison.json)

这里仅证明软件模拟中的到期入队与取消，**不证明工作线程已执行该任务或USB已发送**。线程入口 `0E06D19C`、线程创建包装 `0E06D530`、USB工作回调 `23026D28` 及其驱动调用仍需恢复。静态初始化已见 `23026E70` 将USB任务 `23002220` 绑定至 `23026D29`；`230204C0` 将任务 `23002C94` 绑定至 `230205F9`，后者关联另一条状态处理链，不能据此断言所有动态任务已穷尽。

累计 **56个C单元、78份数据集、172,288组原指令输入**。严格主机编译链接通过，当前共享库为 `recovered-code/portable/build/librr_recovered56.dylib`。完整启动、工作执行/线程续跑、跨核来源和真实RF互通仍未完成；无接收器，无设备写入。
