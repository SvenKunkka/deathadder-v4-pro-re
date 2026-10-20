# 接收器应用定时器到期恢复（官方 1.20）

恢复通用timer到期入口0E06EB00，并将真实注册的断连回调230255B8接入RTC链。新增8,192组原指令对照通过，原指令累计5,960,893步；原有6,144组RTC行为及128组锁超时连续路径回归通过。

[实现](../recovered-code/portable/receiver_timer_expiry.c) · [接口](../recovered-code/portable/receiver_timer_expiry.h) · [RTC扩展](../recovered-code/portable/receiver_rtc_dispatch.h)

## 已恢复行为

- 保留仍在timeout队列时的早退；根据64位period处理不重设、正周期、负编码与溢出分支。遵循原代码在特定分支二次读取ticks的顺序；比较域使用稳定RTC快照。
- 重新登记原expiry回调0E06EB01，增加状态计数；调用已核验的断连回调，更新连接状态并生成USB报告队列内容。
- 用户回调完成后处理一个等待线程，保留摘链、结果清零及就绪条件。未知用户回调在入口停止，不伪造成功或续栈。
- RTC增加可选timeout处理器。旧公开接口仍使用原边界；新timers接口沿真实的dispatcher、clock announce、delta announce调用通用timer及已知用户回调。

## 验证范围

通用timer、timeout announce、clock callback、RTC dispatcher四类各2,048组。完整返回6,434组；697组停在注入的未知用户回调23024FD8，1,042组停在注入的未知timeout入口0E06C000，19组停在RTC回调0E05BDE0。这些输入不证明未知回调在实机被注册。比较完整128 KiB RAM、4 KiB RTC快照、优先级与pending ABI。

[原指令结果](receiver-timer-expiry-comparison.json) · [旧RTC回归](receiver-rtc-handlers-regression.json) · [旧锁超时回归](receiver-rtc-handlers-continuous-regression.json)

连续128轮完成256条连接/断连通知消息、128次真实timer到期、128条断连USB报告入队。由通知消费者注册2,000,000 tick定时器，显式RTC事件经过完整恢复代码触发断连回调；逐轮检查状态、报告内容和队列位置。[连续验证](receiver-timer-expiry-continuous-comparison.json)。USB读取端、时钟值、事件与使能读回明确由测试提供，没有实际USB发送或空口收发。

长批次在case6032出现Ghidra解码错误；同一case单独重跑成功且与最终记录一致。保留此前完整记录，剩余输入分批执行，最终ID为0..8191连续且初始RAM快照无重复。诊断重跑及旧回归未再次计入新增输入。[执行记录](receiver-timer-expiry-execution-notes.json)。

## 版本与剩余范围

RTC原版C/h、结果和库已按哈希保存在[基线归档](receiver-rtc-v1-before-timers/manifest.json)。当前校验明确区分历史来源与本轮源码；旧原指令数据集不变。全部53个C单元严格主机编译链接，当前共享库为`recovered-code/portable/build/librr_recovered53.dylib`。

五个应用timer的静态注册地址已记录于[初始化表](receiver-application-timer-map.json)。目前只接入1A30的断连用户回调；1A68、1AA0、1AD8、1B10的用户回调仍需恢复。硬件异常返回、其他work/RTC回调、完整启动、跨核及真实RF验证尚未完成，因此仍不是完整可烧录无线固件。
