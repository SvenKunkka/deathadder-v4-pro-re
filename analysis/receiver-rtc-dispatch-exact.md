# 接收器 RTC 与线程超时恢复（官方 1.20）

已恢复 RTC 事件分派、clock announce、delta timeout 到期推进、线程超时唤醒、时间片到期标志、重新排队与 tick 结束时选择线程。新增6,144组原固件指令对照通过，累计执行1,059,238条原指令。对照完整128 KiB RAM、4 KiB RTC快照、优先级状态与回调入口参数。

|原地址|恢复行为|
|---|---|
|0E069898|按已分配/活动/使能通道读取并清除RTC事件，调用通道回调|
|0E0683A0|到达deadline后更新23002840基准，以差值低32位传递tick；不采用鼠标端右移5位换算|
|0E06E7FC|推进delta链表，累计23002C78，摘除到期节点并调用回调；重新安排下一比较值|
|0E06DAF4|线程超时退出等待，按标志判断是否加入就绪队列|
|0E06E4C8/E4EC/E55C|时间片标志、重设及tick结束处理|
|0E06D9CC/DA0C/DCA8|选择线程、就绪插入和当前线程重新排队|

[恢复实现](../recovered-code/portable/receiver_rtc_dispatch.c) · [接口](../recovered-code/portable/receiver_rtc_dispatch.h)

## 原指令覆盖与明确边界

三类入口各2,048组：timeout announce、clock callback、RTC dispatcher。4,114组完整返回；1,635组停在实际应用timer expiry入口0E06EB00；380组停在测试显式注入的未知timeout地址0E06C000；15组停在RTC回调0E05BDE0。后两类输入不证明这些回调已在实机注册；所有边界均在执行该回调前保留真实副作用与参数，没有替换为成功结果。

原指令执行验证了支持的线程到期与时间片回调；应用timer/work回调和RTC周期回调的内部逻辑尚未接入。输入采用特权串行CPU、有效有限链表及静止RTC快照，当前CPU索引为0；不是全系统异常、并发或设备时钟仿真。

## 连续组件验证

128组实际锁等待 → 已恢复CPU请求/PendSV主体 → 显式RTC事件 → clock announce → 原线程timeout语义通过。真实恢复代码使用同一份RAM进行登记、摘链与重新就绪，测试没有代写这些链表效果。每组结束时，锁所有者保持不变，等待线程为就绪状态、结果仍为−11；未声称它已恢复执行或获得锁。

事件、时钟值、使能寄存器读回及异常处理入口是明确的外部测试输入。CPU部分停在硬件异常返回之前。此128组组件测试不增加原指令输入总数。

[原指令比较](receiver-rtc-dispatch-comparison.json) · [连续结果](receiver-rtc-continuous-comparison.json) · [源文件与字节证据](receiver-rtc-dispatch-exact.json)

全部52个C单元已严格主机编译及链接。当前共享库为 `portable/build/librr_recovered52.dylib`；先前51单元库保留原路径，供既有证据哈希复核。完整固件、真实线程续跑及无线空口验证仍未完成。
