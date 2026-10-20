# 鼠标定时器到期与工作回调恢复（1.20）

状态：在声明的软件输入域内，原始Thumb指令与重建C逐字节对比通过。新增2个C单元、2份数据集、6,144组输入；不是完整RTOS或无线实测。

## 已恢复执行链

`mouse_timer_expiry.c`恢复`0e096950`：已重新挂链的timer自然提前返回；周期为0或UINT64_MAX时不重启，其他周期按原signed64规则归一化，再经实际`0e096474`重新插入timeout队列。随后status+0x30按32位回绕自增，恢复原BASEPRI再执行用户回调；回调完成后重新加锁，处理timer等待队列并ready。等待者摘链本身不额外取消其timeout，这是原入口行为。

已实现用户回调`23025f64`：清除连接状态`23006b7e`的**16位**，调用真实work67c0提交。实现工作回调`23025df0→23020e7c`的连接/断连两个分支，包括可选timer1b48启动625/周期32或停止、辅助寄存器写入及应用状态字节/半字。断连分支清除76c4和769e均为半字写入，保留相邻字节。未知timer回调`23022310`保持真实入口边界，不伪造返回。

`mouse_work_thread.c`从真正的工作线程入口`0e09504c`取出工作项，更新队列头尾和执行标志，调用已恢复的`23025df1`，再执行结束清理。flush及cancel路径实际调用原信号量逻辑：空队列计数/上限处理，或移除等待线程、取消其活动timeout、清零返回槽、插入ready队列和更新时间片。cancel链头、中间和尾节点修改都保留原副作用。

工作线程是无限循环；API执行到下一轮循环头便交还控制，返回0只表示一个循环段结束。缺少工作时的drain wake/pend、结束后的yield和未知工作回调仍停在真实被调用入口。该API不能通过重新进入来恢复中途暂停的栈。

## 原指令对比

|数据集|输入|执行终点|
|---|---:|---|
|mouse-timer-expiry-original.jsonl|4,096|3,959函数返回；118停在23022310；19停在CPU切换0e089d4c|
|mouse-work-thread-original.jsonl|2,048|800下一轮循环头；794 yield；260 pend；34 drain wake；160未知work3858回调|

前一集分为4×1,024：空用户回调timer到期、已知/未知用户回调timer到期、直接1578用户回调、直接连接状态work回调。后一集执行真实工作线程入口，覆盖队列为空/非空、单/多个工作项、flush、cancel链匹配及未匹配、信号量满/未满及等待者、活动等待timeout与时间片。

每组比较全部64KiB RAM、4KiB RTC、16B辅助寄存器、BASEPRI及被调用入口/有效r0。worker yield没有参数，双方的arg0都规范化为0；这不是对无用r0值相等的声明。模拟共执行1,222,623条原指令；只是执行步数，不代表硬件周期。编译采用C11、Wall/Wextra/Werror/pedantic。

## 证据与复验

- [原字节、来源摘要和比较结果](mouse-expiry-work-exact.json)
- [定时器到期比较](mouse-timer-expiry-comparison.json)
- [工作线程比较](mouse-work-thread-comparison.json)
- [此前静态调用链](mouse-work-expiry-map.md)

从报告根目录执行`rtk proxy python3 analysis/verify_mouse_timer_expiry.py`和`rtk proxy python3 analysis/verify_mouse_work_thread.py`。Ghidra原指令捕获脚本为`ghidra-scripts/EmulateMouseTimerExpiry.java`和`EmulateMouseWorkThread.java`。固件及RAM映射先核对原始SHA-256；使用既有只读工程、Java25、AdaptedEmulator，共享原生ArmCpuState读取BASEPRI。ISB无时序效果，IPSR由测试明确设置，没有函数成功空桩。

## 仍未完成

RTC事件分派`23029a30`及announce`0e09668c`尚未接入；timer1540用户回调`23022310`、work3858扫描回调`23022620`尚未恢复。工作线程drain wake/pend/yield与真正CPU切换、完整线程创建/异常返回仍未完成。其他调用方仍须显式接入扩展入口；已恢复函数不会自动替换旧API边界。无接收器、无空口采样，不能证明无线时序或双端互通。
