# 可编译的通信恢复模块（1.20）

依据原始 Thumb 指令重新编写的 **69 个 C11 单元**，已严格编译并合并链接。累计 **219,264 组原指令输入差分通过**。尚不是完整无线固件工程；主机组件验证不能代替 Cortex-M 固件构建、板上运行或 RF 互通。

|文件|恢复范围|仍有边界|
|---|---|---|
|receiver_radio_test_engine.c/.h|射频测试收发/描述符/扫频/控制调用链接线|新依赖接口接入正常停止、初始化及默认日志；外设事件仍显式输入|
|receiver_radio_test_lifecycle.c/.h|正常无线停止、测试初始化、IRQ 优先级|真实 CPU 切换边界；无实际硬件时序|
|receiver_radio_test_log.c/.h|七个已知格式及默认日志输出回调|动态未知回调停入口；不是通用 printf|
|receiver_radio_test_timer.c/.h|TIMER 初始化/换算/比较/IRQ|未知回调停入口；无真实硬件时序|
|receiver_radio_test_gppi.c/.h|RF 同域事件连接/分配/解除/启停|跨域不支持；SET/CLR 快照无自动副作用|
|receiver_radio_test_control.c/.h|两组测试参数、计数、工作标记、六种描述符|停在真实无线停止/测试停止/测试引擎入口；未自动接入旧厂商模块|
|mouse_wireless_startup.c/.h|无线首次启动、线程与工作项建立、就绪/睡眠前转换|CPU请求时暂停；等待后续跑及配置来源仍未完成|
|mouse_initialization.c/.h|完整无线初始化、应用key包装、状态/队列/DPPI/RADIO配置|上游创建见wireless_startup；等待后续跑/模式切换未接通，外设为静态窗口|
|receiver_vendor_identity.c/.h|两条身份命令生产、路由/工作尾部、精确旧栈字节来源|仅首轮直接工作回调；配置消费为显式交接，CPU切换后续跑仍有边界|
|receiver_vendor_flow.c/.h|厂商测试/统计命令、工作提交与线程调用链接线|真实 CPU/USB/事件等待；身份入口由新 identity 模块扩展，LED/更新仍有边界|
|receiver_vendor_commands.c/.h|厂商消息校验、命令分发、配置字段操作、两条peer转发|旧接口保留入口；新 vendor_flow 接入测试/统计及 worker；鼠标字典尚未恢复|
|receiver_worker_runtime.c/.h|工作取出、USB回调接线、flush/cancel、drain/wake/pend/yield|停在真实CPU/未知回调/USB入口；下一循环头返回不是线程退出|
|receiver_usb_reports.c/.h|三组报告队列取出、缓冲与成功/失败分支、工作回调包装|真实USB驱动停入口，结果hook显式提供；工作线程接线见worker_runtime|
|receiver_work_queue.c/.h|工作入队/取消/延迟/重排/到期及统一RTC接线|工作线程及USB接线见worker_runtime；CPU续跑仍有边界|
|receiver_periodic_service.c/.h|RTC通道分配、周期服务启用与刷新、期限编码、比较登记、统一已知回调入口|动态外设/原子竞争/全启动未验证|
|receiver_application_timers.c/.h|四个应用timer的无线启停、统计/状态、倒计时、配置事件及RTC组合|未知回调/复位/CPU边界；旧栈尾部及外设事件显式输入|
|receiver_timer_expiry.c/.h|通用timer到期/周期重设/断连回调/单waiter就绪，接入RTC|其余用户回调仍停入口，实际外设事件及并发未验证|
|receiver_rtc_dispatch.c/.h|RTC事件/clock announce/delta超时推进/线程与时间片到期|应用timer/work与未知RTC回调保留入口边界；硬件事件显式输入|
|receiver_context_switch.c/.h|CPU请求/线程选择/PendSV软件主体/PSPLIM|异常入口显式提供，停在硬件异常返回前|
|receiver_mutex.c/.h|互斥锁/递归/优先级继承/等待与交接/显式续段|停在CPU请求前，不生成实际线程切换；有限链表及特权域|
|receiver_storage_startup.c/.h|设备就绪检查、layout查询、两区几何建立与挂载|设备驱动先期初始化、锁调度、全系统启动及物理硬件仍有边界|
|receiver_storage_mount.c/.h|上电挂载、页选择/版本校验/异常回收恢复，调用扫描/写入模块|实际锁调度及物理持久化未验证；启动包装见startup模块|
|receiver_storage_scan.c/.h|选定页的记录/数据游标扫描|有限遍历域，页选择由挂载模块负责|
|receiver_storage_write.c/.h|对齐写入、数据/记录追加、页初始化/切换/回收、顶层记录写入与配置组合|已挂载上下文为前提；互斥锁外部回调；不证明物理Flash或并发|
|receiver_storage_read.c/.h|完整记录读取/CRC8/跨页/历史读取、2MiB映射驱动软件体、配置读取组合|调用者提供上下文，现可由mount模块建立；映射区是内存快照，无硬件持久化证明|
|receiver_settings.c/.h|两条持久配置的加载/CRC/默认值/身份回退/写回管理|可组合read/write/mount模块；真实硬件持久化及并发未验证|
|handshake.c/.h|接收器六种握手中的发送与转换|末端通知使用扩展入口|
|handshake_notification.c/.h|事件5队列、满时purge、slot与接收地址动作|无等待线程串行上下文；调度未恢复|
|mouse_handshake.c/.h|鼠标回复、身份条件、state16 TX完成|state17通过独立lifecycle入口处理|
|mouse_lifecycle.c/.h|state17模式初始化及连接成功工作回调|旧入口保留活动timer边界；扩展见mouse_timer_lifecycle|
|business_keys.c/.h|低4位选16项key、安装、0..32B包装|连接调用时机尚未统一恢复；不是认证证明|
|business_cipher.c/.h|1..8个32位字的XXTEA正逆变换|包装域外未验证；尾部非整字字节由包装保留|
|business_tx.c/.h|双端环队列、入队/peek/pop、预处理和分片|声明长度/类别域；中断串行，无实际并发|
|business_rx.c/.h|双端重组、解密、motion与activity；保留旧缓冲尾部|底层入口停在真实消费者/工作项调用边界|
|business_dispatch.c/.h|接收器mode4 class1..5序号去重与累计运动差分|通过receiver_business_flow串接class0和统计|
|business_control.c/.h|class0消费、控制生产、间隔设置、统计|自适应上报见mouse_adaptive_control；完整调用时序及全模式控制未完成|
|mouse_adaptive_control.c/.h|样本/极值/均值、间隔门控、0x2B报告与IRQ发布|真实IRQ时序和指标物理含义未验证|
|mouse_business_consumer.c/.h|AC/A3/B1管理、5A厂商交接、回复发送|活动timer/重启/传感器重初始化有明确边界|
|dongle_business_consumer.c/.h|USB内存队列、motion缓存、状态及厂商交接|实际USB驱动需外部结果；不是主机收到USB报告|
|mouse_business_flow.c/.h|mode1/2/4完整业务入口、重组、工作快速返回、统计|旧入口保持快速返回域；扩展入队见mouse_work_queue，消费者仍异步|
|receiver_business_flow.c/.h|六类业务完整入口、重组/消费者/统计/结束处理|真实USB驱动边界显式暂停，续段使用明确外部结果|
|mouse_radio_irq.c/.h|mode1/2无线中断、ACK释放、失败保留、换频门控及ACK hook|旧API保留非空回调边界；新组合见mouse_timer_lifecycle|
|receiver_radio_irq.c/.h|mode4无线中断、TIMER CC1路径、显式SWI业务交接|CC0/CC2扩展见receiver_radio_timer；其他模式扩展见legacy模块；PHY/DPPI未恢复|
|mouse_timer_lifecycle.c/.h|活动timer摘链/RTC重设、已识别ACK断开及mode1/2 IRQ组合|stop回调、等待线程/调度、未知ACK回调仍有边界|
|receiver_radio_timer.c/.h|mode4 CC0/CC1/CC2正常调度、频道更新、失败超时|旧接口停在信号量；RTOS扩展另见receiver_rtos_lifecycle；mode1/2扩展见receiver_legacy_timer|
|mouse_mode4_radio.c/.h|mode4 RADIO及选定TIMER/action、full接口接入TX|扩展lifecycle接入rate/plan/已知ACK；旧API保留原边界|
|mouse_mode4_tx.c/.h|真实空闲TX选择、聚合/缓存重发、普通队列/特殊帧|无线硬件时序、并发队列未模拟|
|receiver_legacy_business.c/.h|mode1/2业务适配、去重/motion、peer与统计尾段|实际USB与畸形域；RADIO/TIMER扩展另见下|
|receiver_rtos_lifecycle.c/.h|信号量、等待者移出/ready排序、消息直交/purge、断连通知|原API保留边界；timed扩展另见下，context switch/24B旧栈仍明确保留|
|mouse_mode4_lifecycle.c/.h|pending rate、37频道mask提交与跳频、已知ACK生命周期、超时清理|旧API保留work/timer-start边界；新扩展见mouse_work_queue，未知回调未恢复|
|receiver_timeout.c/.h|delta timeout取消/插入、RTC compare、活动等待者及时间片续接|未来到期回调、CPU context switch和自主时钟未恢复|
|receiver_legacy_radio.c/.h|mode1/2无线IRQ、握手与连接模式切换、通知队列及显式SWI交接|TIMER扩展见receiver_legacy_timer；真实USB/IRQ调度、通知栈残留仍有限制|

|mouse_timer_start.c/.h|绝对/相对timeout插入、timer重启、RTC重设|到期扩展见mouse_timer_expiry；自主时间推进未恢复|
|mouse_work_queue.c/.h|工作项入队、等待者唤醒、ready排序、时间片及mode4超时续接|旧API不自动执行未来回调；线程扩展见mouse_work_thread|
|receiver_legacy_timer.c/.h|mode1/2 TIMER时槽、扫描/握手/ACK选择、断连通知|顶层状态门控在API外；CPU切换、PHY及通知栈尾仍显式|

|mouse_timer_expiry.c/.h|周期timer到期、已知1578用户回调、等待者ready及连接状态work回调|未知回调/真实CPU切换；RTC分派扩展见mouse_rtc_dispatch，自主外设未恢复|
|mouse_work_thread.c/.h|真实工作线程取出/执行已知回调、flush/cancel信号量与等待者唤醒|下一循环头是段结束；drain/pend/yield及未知回调仍有边界|

|receiver_initialization.c/.h|完整初始化、无线配置、配置事件1/8/9接入key|旧栈PHY字节显式输入；固定RTC快照；队列等待和其他分支未接入|
|mouse_lifecycle_runtime.c/.h|直接断连/ACK/class3确认接入真实timer stop等待路径|CPU/未知stop回调边界后尚无调用栈续接；旧IRQ/RTC适配仍待接入|
|mouse_timer_stop_runtime.c/.h|timer stop 单等待者唤醒、调度及回调后续段|未知停止回调和 CPU 请求保留边界；旧上层尚未接入|
|mouse_deferred_work.c/.h|延迟启动/重排、RTC到期入队和timer断连回调组合|未知回调/CPU请求和timer stop边界；自主事件未验证|
|mouse_context_switch.c/.h|CPU请求/选择/PendSV保存恢复/PSPLIM，含寄存器与MSP临时区|原指令停在异常返回BX LR前；真实异常/并发未验证|
|mouse_worker_runtime.c/.h|drain唤醒、pend/yield前置状态、延迟到期入队、扫描worker组合|CPU请求/PendSV与切换后恢复未执行；基础接口仍保留扫描边界|
|mouse_rtc_dispatch.c/.h|RTC事件、时钟公告、到期队列、线程/时间片回调及扫描组合|未知回调、异常进入/返回、实际CPU/自主外设仍有边界|
|mouse_scanning.c/.h|扫描工作项、四频道轮换、握手重试、总超时重启；timer/work组合入口|真实RTC/CPU/IRQ和旧timer-stop边界仍保留|

接口中的负值及暂停状态须按各头文件解释；分析边界码不是原固件的拒绝行为。部分接口预检不修改状态，部分整合入口可能已产生真实副作用，不能统一假定失败回滚。寄存器和指针使用内存模型，不访问物理设备。

## 构建

从本目录执行：

```sh
rtk proxy make
```

输出 `build/librr_recovered.a`，本次还验证了全部43单元合并的 `build/librr_recovered.dylib`。采用 C11、Wall/Wextra/Werror/pedantic。构建对象是主机库，没有 MCU 启动文件、链接布局或完整 HAL，不能直接烧录。

## 验证

60份原指令数据集共 **125,824 组输入**，不重复计入同一输入的后续续段：

|范围|原指令输入数|
|---|---:|
|握手、通知、基础cipher|1,632|
|TX队列/分片、RX重组、去重、终态/成功回调|3,216|
|key安装及包装|1,056|
|class0控制和统计|896|
|鼠标消费者|512|
|接收器消费者、队列、状态、驱动后续段|2,736|
|鼠标完整业务入口|1,600|
|接收器完整业务入口|1,152|
|自适应控制及0x2B上报|1,536|
|鼠标mode1/2无线中断与SWI交接|2,944|
|接收器mode4无线中断/CC1/SWI交接|1,536|
|鼠标活动timer及ACK生命周期，含mode1/2 IRQ组合|2,304|
|接收器mode4完整正常定时分支及断连边界|2,304|
|鼠标mode4 IRQ/选定TIMER/action与SWI交接|3,072|
|鼠标mode4真实TX选择，含特殊帧|4,352|
|接收器mode1/2业务适配|3,456|
|接收器RTOS与type2通知入口|1,536|
|接收器完整TIMER断连路径，显式24B栈残留输入|256|
|鼠标mode4速率/频道/ACK及真实超时边界|2,560|
|接收器直接timeout取消与启动|2,048|
|接收器活动timeout/时间片RTOS续接|1,536|
|接收器活动timeout完整TIMER断连路径|256|
|接收器mode1/2无线IRQ、握手、通知与SWI交接|2,688|
|鼠标timeout/timer启动|4,096|
|鼠标工作队列直接入口|2,048|
|鼠标mode4超时经真实work/timer-start|512|
|接收器mode1/2 TIMER|3,584|
|接收器队列标记255回归|768|
|鼠标timer到期与应用回调|4,096|
|鼠标真实工作线程循环段|2,048|
|鼠标扫描直接入口与timer/work组合|6,144|
|鼠标RTC分派/clock announce/delta timeout|6,144|
|工作线程调度前置与延迟工作到期|6,144|
|CPU请求与PendSV软件主体|2,048|
|延迟工作生产者|4,096|
|RTC延迟/断连与timer组合|4,096|
|timer stop完整入口及独立回调后续段|3,072|
|直接断连/ACK/class3完整入口|3,072|
|接收器初始化/无线配置/出队后分派|3,072|

上一阶段新增9,088组为8,529完整返回＋559真实边界（鼠标work/timer-start512、接收器context-switch35、USB12）。接收器12次USB外部结果续段不重复加计。

本轮定时器停止入口及独立回调后续段另增 3,072 组（2,048 + 1,024），不是重放同一输入的追加计数。

这不是125,824次完整设备通信：接收器消费者集包括2,663次完整返回、9次驱动入口停止、64次给定外部结果的驱动后指令片段；接收器业务入口集含1,148次完整返回和4次驱动入口停止，另验的4个续段不重复计数。早期鼠标整入口只验证work快速返回；本轮扩展已验证新工作入队，未来自动执行仍未证明。接收器新增定时集另含2,286组完整返回和18组真实信号量入口停止。鼠标新增mode4的256次交接也是明确指定调用顺序。新增legacy业务3,456组包含3,444返回及12真实USB边界，12外部结果续接不加计。新增RTOS1,536组包含1,418返回及118真实timeout/timeslice/context-switch边界；另256完整断连原指令路径的C投影显式接收原通知入口24B旧栈残留，未模拟其CPU栈生成。其他模块也保留各自入口到调用边界的范围。

另有独立的 **C组件集成**，不计入原指令输入数：

- 662组TX→队列→分派→重组测试：3,890片段、1,728次重复、320次乱序后重起；终点是消费者入口。
- 416条双向业务消息：1,536片段、928次重复、16个B1请求/回复闭环；覆盖已恢复消费者与接收器USB内存队列。鼠标延期消费者由测试明确调用，业务DMA数据由测试传递，没有真实IRQ、ACK、PHY或USB主机收包。

另296组自适应上报集成覆盖37个正常channel、两peer、两种报告及满队列副作用；192组接收器同状态IRQ→SWI→下一CC1测试覆盖排队ACK/同步回退/晚发取消，另48组回归区分NVIC旧值与本次真实写动作。均未计入原指令数。接收器定时器另有16个连续场景，执行16,408定时事件、960有效RX/业务及8次断连边界。

从报告根目录运行对应验证脚本：

```sh
rtk proxy python3 analysis/verify_portable_handshake.py
rtk proxy python3 analysis/verify_mouse_handshake_extended.py
rtk proxy python3 analysis/verify_handshake_notification.py
rtk proxy python3 analysis/verify_business_cipher_original.py
rtk proxy python3 analysis/verify_business_tx.py
rtk proxy python3 analysis/verify_business_rx_original.py
rtk proxy python3 analysis/verify_business_dispatch_original.py
rtk proxy python3 analysis/verify_mouse_lifecycle.py
rtk proxy python3 analysis/verify_business_keys.py
rtk proxy python3 analysis/verify_business_control.py
rtk proxy python3 analysis/verify_mouse_adaptive.py
rtk proxy python3 analysis/verify_adaptive_exchange.py
rtk proxy python3 analysis/verify_mouse_business_consumer.py
rtk proxy python3 analysis/verify_dongle_business_consumer.py
rtk proxy python3 analysis/verify_mouse_business_flow.py
rtk proxy python3 analysis/verify_receiver_business_flow.py
rtk proxy python3 analysis/verify_mouse_radio_irq.py
rtk proxy python3 analysis/verify_receiver_radio_irq.py
rtk proxy python3 analysis/test_receiver_radio_irq_integration.py
rtk proxy python3 analysis/verify_business_pipeline.py
rtk proxy python3 analysis/verify_business_exchange.py
rtk proxy python3 analysis/verify_mouse_timer_lifecycle.py
rtk proxy python3 analysis/verify_receiver_radio_timer.py
rtk proxy python3 analysis/test_receiver_radio_timer_integration.py
rtk proxy python3 analysis/verify_mouse_mode4.py
rtk proxy python3 analysis/test_mouse_mode4_integration.py
rtk proxy python3 analysis/verify_mouse_mode4_tx.py
rtk proxy python3 analysis/test_mouse_mode4_tx_integration.py
rtk proxy python3 analysis/verify_receiver_legacy_business.py
rtk proxy python3 analysis/verify_receiver_disconnect_lifecycle.py
rtk proxy python3 analysis/verify_mouse_mode4_runtime.py
rtk proxy python3 analysis/test_mouse_mode4_runtime_boundaries.py
rtk proxy python3 analysis/test_mouse_mode4_runtime_integration.py
rtk proxy python3 analysis/verify_receiver_timeout.py
rtk proxy python3 analysis/verify_receiver_disconnect_timed.py
rtk proxy python3 analysis/verify_receiver_legacy_radio.py
```

原指令执行先核验镜像和运行RAM映射。通知/lifecycle/鼠标整入口为缺失的BASEPRI读取接入模拟器内建setter的同一CPU状态；屏障、外设和IRQ不具备实机时序。TX的42组外部队列变更是显式测试输入。驱动边界没有用空函数模拟成功。

mode4 双端连续组件另验证8个场景、256周期：接收器真实下行队列/定时选包256次，鼠标成功IRQ336次、CRC失败64次，业务完成256次、重复拒绝80次。上行数据、事件和CRC由环境明确输入，该组没有使用鼠标TX生成器；后续真实TX扩展另见下。消费者保持延期，未模拟实际射频或系统抢占。见 [组件结果](../../analysis/mouse-mode4-integration.json)。这些事件不计入原指令输入数。

真实TX扩展另验证8场景256周期：恢复的鼠标函数生成256上行、接收器选出256下行，192次成功ACK弹队列、64次失败保留、56次跨周期实际重发。[结果](../../analysis/mouse-mode4-tx-integration.json)。射频事件/CRC仍显式输入，硬件时序未模拟。

runtime扩展另在256周期应用256次pending rate、提交256次频道mask、执行256次selector2/3跳频，并保留56次跨周期重发。[结果](../../analysis/mouse-mode4-runtime-integration.json)。这些是组件事件，不计入原指令数量。

## 阅读入口

- [mode4速率/频道/ACK](../../analysis/mouse-mode4-runtime-exact.md) · [接收器timeout/时间片](../../analysis/receiver-timeout-exact.md) · [接收器mode1/2无线IRQ](../../analysis/receiver-legacy-radio-exact.md)

- [真实TX选择](../../analysis/mouse-mode4-tx-exact.md) · [mode1/2业务适配](../../analysis/receiver-legacy-business-exact.md) · [RTOS/断连通知](../../analysis/receiver-rtos-lifecycle-exact.md)

- [活动timer及ACK断开](../../analysis/mouse-timer-lifecycle-exact.md) · [接收器定时器](../../analysis/receiver-radio-timer-exact.md) · [鼠标mode4](../../analysis/mouse-mode4-exact.md)

- [鼠标无线中断](../../analysis/mouse-radio-irq-exact.md) · [接收器无线中断](../../analysis/receiver-radio-irq-exact.md)
- [自适应控制及两端上报](../../analysis/mouse-adaptive-exact.md)
- [key及控制](../../analysis/business-keys-control-exact.md)
- [鼠标消费者](../../analysis/mouse-business-consumer-exact.md) · [接收器消费者](../../analysis/dongle-business-consumer-exact.md)
- [鼠标业务整入口](../../analysis/mouse-business-flow-exact.md) · [接收器业务整入口](../../analysis/receiver-business-flow-exact.md)
- [发送精确证据](../../analysis/business-tx-exact.md) · [接收与去重](../../analysis/business-rx-dispatch-exact.md)
- [终态与连接回调](../../analysis/mouse-lifecycle-exact.md)
- [全部数据集、当前源码及构建摘要](../../analysis/recovered-code-validation-summary.json)
- [双向业务集成结果](../../analysis/business-exchange-comparison.json)

完整目标仍需其余模式的无线IRQ与业务层接线、剩余定时分支及模式接线、连接初始化及key安装时机、厂商交接后全部子命令、class0上报调用时机、全模式ACK/重试/重连、实际USB驱动、活动RTOS调度、DPPI/时钟和真实空口验证。

新增IRQ验证中，鼠标2,944组含2,688次独立子入口和256次显式IRQ返回后SWI交接；接收器1,536组含768次RADIO入口、576次TIMER CC1真实选中路径、192次IRQ返回后SWI交接。MMIO是输入快照和写入结果，不会自动产生时间、射频、DMA或中断事件。

## 上一轮工作队列与启动验证

本轮新增11,008组：10,987完整返回＋21真实CPU切换边界。鼠标timer-start另有1,024次连续操作和6个主机接口契约检查；接收器TIMER→RADIO→SWI另有24场景/288周期，均不计入原指令输入数。

- [鼠标定时器启动](../../analysis/mouse-timer-start-exact.md)
- [鼠标工作队列及mode4续接](../../analysis/mouse-work-queue-exact.md)
- [接收器时槽与255标记副作用](../../analysis/receiver-legacy-timer-exact.md)
- [此前静态工作回调与RTC到期链](../../analysis/mouse-work-expiry-map.md)
- [本轮产物完整性](../../analysis/phase-work-timer-integrity.json)

复验入口：`analysis/verify_mouse_timer_start.py`、`analysis/verify_mouse_work_queue.py`、`analysis/verify_mouse_mode4_rtos.py`、`analysis/verify_receiver_legacy_timer.py`、`analysis/verify_receiver_legacy_sentinel.py`；连续组件测试为`analysis/test_mouse_timer_start_integration.py`及`analysis/test_receiver_legacy_continuous.py`。所有测试只操作主机内存模型。

## 上一轮到期回调与工作线程验证

新增6,144组分为3,959完整函数返回、800下一工作循环头和1,385真实调用入口边界。800循环段不算线程结束。工作线程已实际调用连接状态回调并执行flush/cancel信号量逻辑；未由主机自动推进时间或调度线程。

[恢复与范围](../../analysis/mouse-expiry-work-exact.md) · [完整性校验](../../analysis/phase-expiry-work-integrity.json)。复验：`analysis/verify_mouse_timer_expiry.py`与`analysis/verify_mouse_work_thread.py`。通用worker会在未知回调、drain、pend、yield处保留当前状态和入口，不能通过重入假装恢复原栈。

## 上一轮扫描链验证

[扫描恢复与验证](../../analysis/mouse-scanning-exact.md)覆盖直接扫描work/timer、推进、启动及完整timer/work组合，共6,144组：5,116函数返回、439下一循环头、589真实调度入口边界。连续C组件另有4个起始频道、8轮总超时重启和8,000次显式应用定时回调，不计入原指令数。

复验：`analysis/verify_mouse_scanning.py`及`analysis/test_mouse_scanning_continuous.py`。新增`rr_mouse_timer_expiry_scanning`与`rr_mouse_work_thread_scanning`在旧API实际暂停点执行扫描处理和后续尾段；旧API仍保留原边界。[本轮完整性记录](../../analysis/phase-scanning-integrity.json)。

## 上一轮 RTC 分派验证

[恢复与证据](../../analysis/mouse-rtc-dispatch-exact.md)：6,144 原指令输入，5,468 完整返回，676 真实未恢复回调入口。连续组件以 8,000 个显式 RTC 事件间接调用扫描回调，完成 8 轮超时重启；不加计原指令输入数。

复验：`analysis/verify_mouse_rtc_dispatch.py`、`analysis/test_mouse_rtc_continuous.py`；[完整性记录](../../analysis/phase-rtc-integrity.json)。未知回调保留 pending ABI，不能用重新进入原函数代替实际续栈。

## 上一轮工作线程调度前置验证

[恢复与证据](../../analysis/mouse-worker-runtime-exact.md)：6,144 原指令输入，2,048 完整返回、753 下一循环头、3,291 CPU请求边界、52基础接口扫描边界。扩展API可实际调用扫描回调。192轮连续等待/延迟入队/唤醒/工作回调组件通过；384次外部上下文交接是测试输入，不是CPU验证。

复验：`analysis/verify_mouse_worker_runtime.py`、`analysis/test_mouse_worker_continuous.py`；[完整性结果](../../analysis/phase-worker-runtime-integrity.json)。

## 上一轮 CPU/PendSV 验证

[报告](../../analysis/mouse-context-switch-exact.md)：2,048 原指令输入，1,536 正常返回、512 到异常返回指令前。四种初态的 256 请求/PendSV 连续组件通过，硬件异常入栈/出栈和真实线程执行仍未验证。

另交付 [原生汇编](../cortex-m/README.md)，所选 200 字节与原固件完全一致；片段输出包含未恢复的占位填充，不是完整固件。复验：`analysis/verify_mouse_context_switch.py`、`analysis/test_mouse_context_continuous.py`；[完整性结果](../../analysis/phase-context-switch-integrity.json)。

## 本轮延迟工作及 RTC 组合验证

[报告](../../analysis/mouse-deferred-work-exact.md)：8,192 新增原输入，8,175 完整返回、17 明确边界。RTC 可选处理器复用同一主循环，旧入口行为经原 6,144 组和连续扫描回归保持一致；[原版归档](../../analysis/rtc-v1-before-deferred/manifest.json)保留修改前证据。

128轮连续链由RTC间接执行延迟到期入队，含64次活动重排；CPU交接与时钟事件仍是测试输入。复验：`analysis/verify_mouse_delayed_work.py`、`analysis/verify_mouse_rtc_deferred.py`、`analysis/test_mouse_deferred_continuous.py`。[完整性](../../analysis/phase-deferred-work-integrity.json)。

本轮新增 `mouse_timer_stop_runtime`：活动定时器停止后的单线程唤醒及调度、未知 stop 回调边界和回调后续段。3,072 组原指令输入通过；其中 1,024 组为显式回调后状态续段，不等于回调已恢复。详见 [停止路径证据](../../analysis/mouse-timer-stop-exact.md)。

最新断连扩展与实际 stop 注册范围见[证据](../../analysis/mouse-lifecycle-runtime-exact.md)。三个完整入口 3,072 组原输入通过，其中 2,816 返回、256 明确边界；不是 RF 实测。

接收器完整初始化及配置事件的恢复、随机状态与旧栈参数说明见[证据](../../analysis/receiver-initialization-exact.md)。3,072 组原指令比对通过；配置分派的下一循环头不等于线程返回。

最新接收器配置控制扩展见[报告](../../analysis/receiver-config-control-exact.md)：4/10/40/41/43/44事件及timer/线程操作新增5,120组原指令比对通过。返回1保留CPU或未知stop回调入口，未恢复嵌套栈续接。

最新消息队列与配置线程组合见[报告](../../analysis/receiver-queue-runtime-exact.md)：新增4,096组原指令通过；从真实message_get开始执行配置循环。另128轮/768条连续配置消息、64次活动等待取消通过，256次CPU交接为显式输入。

最新通知管理线程、连接生产者和断连到期回调见[报告](../../analysis/receiver-notification-runtime-exact.md)：6,144组原指令通过；另128轮连接/断连队列链验证通过。输出接入USB报告环队列与无线B1业务队列，未执行实际传输或自主RTC调度。

最新配置消息生产者、身份初始化入口及模式入口见[报告](../../analysis/receiver-config-producer-exact.md)：10,240组原指令通过。已核对官方配置队列10槽，区别于通知队列5槽；64轮/960条配置消息串接通过。模式43停在真实LED入口，不伪造返回。

最新配置加载与写回管理见[报告](../../analysis/receiver-settings-exact.md)：2,304组原指令输入与64轮连续组件通过。`load/flush`在底层存储入口返回pending；由调用者提供读取效果和原返回值后再`resume`。默认恢复保留B记录中22字节，特殊ID使用RTC混入PRNG；无接收器、无实际flash或RF验证。

最新存储读取与映射驱动恢复见[报告](../../analysis/receiver-storage-read-exact.md)：5,888新增原指令输入通过；1,792组执行原始映射驱动不替换调用/返回。`rr_receiver_settings_read_continue`把待处理的配置读取接到实际记录解析，直至下一记录写入边界。64轮快照→配置→无线初始化组件通过；挂载、记录写入/回收和实际Flash仍待完成。

最新记录写入与回收见[报告](../../analysis/receiver-storage-write-exact.md)：4,608新增原指令输入、192轮重复写入/读回/初始化组件通过。`rr_receiver_settings_write_continue`接入真实记录管理算法，映射驱动产生写入结果；真实mutex仍由调用者提供。官方镜像设备参数为写块16/擦除值FF，页布局512×4096；这是镜像配置证据，不是实机读取。


## 新增：选定存储页的游标恢复

[扫描恢复证据](../../analysis/receiver-storage-scan-exact.md)：新增 1,024 组原指令比较通过，192 周期内 384 次找回写入位置。当前累计 47 个 C 单元、66 份数据集、139,648 组原指令输入；完整 mount、真实互斥锁和无线实机验证仍未完成。


## 新增：上电存储挂载

[挂载恢复证据](../../analysis/receiver-storage-mount-exact.md)：新增 1,088 组原指令对比通过；从空白存储开始完成 386 次上下文清空后的挂载和配置读回。当前累计 48 个 C 单元、67 份数据集、140,736 组原指令输入。真实互斥锁/CPU、启动包装、跨核和无线实机验证仍未完成。


## 新增：存储启动调用链

[启动恢复证据](../../analysis/receiver-storage-startup-exact.md)：新增1,536组原指令对比通过，193次存储启动及配置读回通过；当前49个C单元、68份数据集、142,272组输入。上层九个初始化调用及未完成部分已列入启动主链图；完整目标未完成。


## 新增：实际互斥锁路径

[锁恢复证据](../../analysis/receiver-mutex-exact.md)：新增2,368组原指令对比通过，包括128组运行实际锁函数的存储启动；连续验证1,924次锁操作。当前50个C单元、70份数据集、144,640组输入。CPU切换与完整系统运行仍未完成。


## 新增：接收器 CPU 切换主体

[恢复及验证证据](../../analysis/receiver-context-switch-exact.md)：新增2,048组原指令差分通过；原生汇编所选200字节与固件一致。256段连续切换及392个锁调度边界组件接线通过，硬件异常返回和真实线程续跑尚未实现。当前51个C单元、71份数据集、146,688组输入；完整无线固件及实机互通仍未完成。


## 新增：接收器 RTC 与线程超时

[恢复及验证证据](../../analysis/receiver-rtc-dispatch-exact.md)：新增6,144组原指令输入通过，4,114完整返回、2,030回调入口边界；128组锁等待至RTC超时重新就绪组件通过。累计52个C单元、72份数据集、152,832组输入。应用timer/work回调、硬件异常返回、完整启动与空口仍未闭合。


## 新增：接收器应用定时器到期

[恢复及证据](../../analysis/receiver-timer-expiry-exact.md)：新增8,192组原指令对照，6,434返回、1,758未知回调入口；原RTC6,144组回归通过。连续128轮连接/断连通知经RTC触发真实断连回调并产生USB队列报告。累计53个C单元、73份数据集、161,024组原输入；完整固件与实机通信仍未完成。

## 应用 timer 回调接线（54 单元版本）

新增四个静态注册用户回调与可选handler，保留原timer API边界。6,144组新原指令对照、8,192组旧回归、128轮旧断连及193次新RTC连续事件检查通过。共享构建为 `build/librr_recovered54.dylib`。

[详细证据与限制](../../analysis/receiver-application-timers-exact.md)。五个已知静态timer用户回调均已接入；全系统启动/动态回调/实际射频仍不完整。

## 周期服务与统一 RTC 入口（55单元版本）

[本轮说明与验证](../../analysis/receiver-periodic-service-exact.md)。新库为 `build/librr_recovered55.dylib`；旧库保留证据绑定。此前54单元接口未改变，新增统一入口包括周期服务及五个已知应用timer回调。

## 工作队列与延迟到期（56单元版本）

[本轮证据](../../analysis/receiver-work-queue-exact.md)。当前共享构建 `build/librr_recovered56.dylib`。已有55单元源码未改，新增统一RTC入口包括周期、应用timer和延迟work到期；不冒充线程执行。

### 阶段 60

[测试控制证据](../../analysis/receiver-radio-test-exact.md)：8 个入口、2,048 组原指令、65,342 步对照通过。当前共享库 `build/librr_recovered60.dylib`。旧 59 个 C/H 保持不变，保留此前快照。新增 API 返回 1 时是执行边界，不能据此继续假定原调用返回。

### 阶段 61

[射频引擎和调用链证据](../../analysis/receiver-radio-engine-exact.md)：底层 4,224 组与连接后的控制流程 2,048 组原指令对照全部通过。当前共享库 `build/librr_recovered63.dylib`。此前 60 个 C/H 保持不变；新 `rr_receiver_radio_test_control_flow` 负责已验证的跨模块调用及返回后续段。

### 阶段 62

[停止、初始化及日志证据](../../analysis/receiver-radio-lifecycle-exact.md)：新增 7,552 组原指令、5,251,707 步对照通过。当前共享库 `build/librr_recovered65.dylib`。新增 `rr_receiver_radio_test_dependencies` 可传给 `*_with_dependencies` 接口；上下文为可选 `uint32_t` 异常编号指针，空指针表示线程模式。旧接口语义保留且 6,272 组回归通过。CPU 切换、未知日志回调和未提供的无线事件仍是明确边界。

### 阶段 63

[厂商命令及工作线程接线](../../analysis/receiver-vendor-flow-exact.md)：新增6,144组原指令、4,729,891步全部通过；658组执行至工作线程下一循环头。该阶段共享库 `build/librr_recovered66.dylib`。`rr_receiver_vendor_flow` 接入真实测试包装/提交/统计；`rr_receiver_vendor_work_step` 接入厂商回调及完成后的原线程尾部。旧worker接口3,072组回归通过，修改前源码已冻结。

## 身份命令扩展（phase64）

[身份恢复证据](../../analysis/receiver-vendor-identity-exact.md)：3,584组新增原指令对比全部通过，含512次显式配置消费；累计88份数据集。该阶段共享库为 `build/librr_recovered67.dylib`。`receiver_vendor_identity` 的512字节栈输入取自所选根入口SP下方；不要将它误当成消息尾或后续任意工作循环的栈。旧厂商接口保留原入口边界，新接口完成身份消息生产及其收尾。

## 鼠标完整初始化扩展（phase65）

[完整初始化证据](../../analysis/mouse-initialization-exact.md)：3,840组原指令、43,086,518步全部通过；新增 `rr_mouse_initialize` 及 `rr_mouse_application_initialize` 等六个API。两端实际C初始化后416条业务消息通过，连接状态及数据交接显式提供。当前共享库 `build/librr_recovered68.dylib`，累计89份数据集、215,552组原指令输入；完整启动和RF实机互通未完成。
