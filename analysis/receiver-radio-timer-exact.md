# 接收器 1.20：mode4完整正常定时器调度与断连边界

后续扩展：[信号量与断连通知](receiver-rtos-lifecycle-exact.md)已恢复无活动timeout等已声明域的等待线程交接/就绪队列和通知提交。旧接口仍保留本文的信号量入口边界；扩展接口单独验证，不能混淆范围。

新增`recovered-code/portable/receiver_radio_timer.c/.h`，提供`rr_receiver_timer_mode4`。恢复mode4的CC0、CC2与CC3..7选择分支，并复用已验证CC1；旧`receiver_radio_irq`接口与源码不变。**正常定时器路径已验证，断连路径到真实RTOS信号量入口仍为部分完成**，不能称完整无线栈。

本报告更新前一份IRQ报告中“CC0/CC2尚未恢复”的范围：它们在此新增模块已恢复；断连后续RTOS及工作线程仍未恢复。

## 验证

- 原入口`23021BBC`：2304组PASS，2286组完整返回，18组准确停在真实`0E06D0D0`入口、r0=`23001C54`。共129178条原Thumb指令。无函数成功桩、无CPU userop补丁。
- 无事件、CC0..CC7每类256组。包括事件优先级、全slot、全频道选择模式0..4、计数0/1/2047/2048/65535/65534、98/99/100重试阈值、32位200阈值与回绕、频道掩码更新、周期统计阈值。
- 全量比对64KiB数据RAM、RADIO4KiB、TIMER2KiB、辅助外设2KiB、NVIC存储以及边界入口/参数。初始化硬件值是输入，不模拟硬件自动触发。
- 可重跑`python3 analysis/verify_receiver_radio_timer.py`；结果`receiver-radio-timer-comparison.json`；原指令脚本`ghidra-scripts/EmulateReceiverRadioTimer.java`，记录`receiver-radio-timer-original.jsonl`。

固件SHA256为`f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`，测试前校验完整flash及RAM代码映射一致。

## CC0：帧周期、频道图切换、统计

当global state<2时原入口立即返回。mode4优先检查CC0，再CC1、CC2直至CC7，每次只消耗第一个值恰为1的事件。

CC0清事件，slot=0，CC0=16000、CC1=2720、CC2=3200、CC4=0，并关闭RXEN订阅。随后`230247F4`检查325D待更新标志及33D6目标计数是否等于5376：相等时清标志，将待用5字节channel map30DE..E2复制到30D9..DD；selector mode2/3重建37频道直接/重映射表与启用数，并以BASE1高低16位异或得到identifier。

事件计数低11位为0时，将33DC的32位统计复制到33D8，清33DC，按33DA高16位与上报间隔341C比较，设置33E0（16位）。interval2/4/8/16/32/64阈值分别3994/1997/999/500/250/125；其他interval阈值8090。所有宽度来自指令，不沿用反编译中的模糊全局类型。

## CC2：时隙边界、下一频率与重试

|当前slot|CC1|CC2|CC4|主要动作|
|---|---:|---:|---:|---|
|0|不变|不变|不变|仅清CC2事件|
|1|4640|5280|4640|state11/12时关闭RXEN订阅|
|2|7040|8000|0|关闭TXEN订阅|
|3|10720|11200|0|关闭RXEN订阅|
|4|12640|13280|12640|state11/12时关闭RXEN订阅|
|5|15040|0|0|关闭TXEN，计数、跳频、超时/状态评估|

slot5对context0及context2分别处理：connection state>2时，+86事件计数与+88连续失败计数各按16位递增，+8C业务间隔计数按32位递增，不饱和。之后用context2事件计数和**旧**32CA调用频道选择，向3226写16位频率，再将32CA更新为计数bit1。

selector0/1：从534B+4×channel+5349[channel]取字节。selector2/3：以event counter和identifier执行三轮位排列、×17、加identifier，异或identifier；%37直接映射，禁用频道通过乘启用数量的高16位重映射。结果存30E3、3228并查固件表0E06FB84。其他selector返回0x0962。模型忠实使用现有表与计数，未添加“零频道掩码合法”等厂商校验假设。

context0 connection state>2且新的失败计数<100：+8C<200时state=3，否则state=4。新的失败计数>=100进入下面的断连路径；16位65535递增回0不触发此条件。接收IRQ在新确认序号时清失败计数，因此本轮也验证了收包与定时器的连续组合。

## 断连：已恢复动作和明确暂停点

原指令`23024C2A`先清RXEN/STOP/TXEN订阅，state0，清READY/END/DISABLED并TASK_DISABLE=1。真实`23021DFC`把协议mode改为2，SHORTS=80001、INTENCLR00=FFFFFFFF、INTENSET00=100，RADIO.MODE=4，并按`23020E84/23020D5C`写原调谐寄存器、PREFIX0和PCNF0/1。这里的MODE偏移是500、PCNF0偏移E20，已由原指令差分纠正并核验。

若两个业务context的radio state均<11，则清5349的16位、5380的32位，设置扫描context state5370=11。随后只清queue0的write/read索引353C/3542，**不是清空所有业务队列**。`230221A4`设置33EC=1，再进入真实RTOS semaphore give `0E06D0D0(r0=23001C54)`。

本模块到这里返回pending=1，记录真实入口及参数；**不执行或假装完成信号量更新/唤醒线程**。原入口之后还将通过`230254F8`提交断连消息（type2，payload包含peer0及context+0A的32位值），消息队列put/purge、系统调度和后续生命周期仍待恢复。该边界状态不是原函数的业务返回值，也没有注入成功结果。

## 连续组件集成

`analysis/test_receiver_radio_timer_integration.py`验证16个C事件序列场景：selector0..3 × 初始失败计数0/98 × 静默/持续有效包。共16408次定时事件、960次有效RX→SWI4→业务调用，8个场景触及真实语义的断连边界。

静默时准确在100−初始计数个周期到达断连；持续有效新序号在每周期重置失败计数，120周期后仍正常。每周期显式给出CC0/CC1/CC2序列，校验context2事件计数递增和失败计数，保留同一RAM状态。结果`receiver-radio-timer-integration.json`。这些是组件集成而非新增原指令样本；事件、CC7和接收成功均为明确环境输入，不声称完成PHY/DPPI或真实时钟。

## 接口与剩余范围

`rr_receiver_timer_mode4(ram,flash,hw,pending)`返回0（原流程返回）、1（真实RTOS入口pending）、−1（非mode4）。原入口是void，此状态值是离线模型接口。合法初始化频道表、队列和RAM仍为调用前提。

非mode4的定时调度、断连RTOS尾段/管理线程、硬件状态机、NVIC抢占和RF测量未在此恢复。所依赖旧CC1仍是相同已验证代码，未修改共享模块或旧报告。

## 原字节来源

RAM映射镜像偏移=VA−23020000+79C；入口字节用于审查定位，完整映像hash见上。

|地址|镜像偏移|入口16字节|作用|
|---|---|---|---|
|0x23021bbc|0x2358|`084b1a88012a06d99b88042b04d0012b`|TIMER vector dispatcher|
|0x23024980|0x511c|`f0b5b84b83b0d3f84021012a31d0d3f8`|mode4 event dispatcher|
|0x230247f4|0x4f90|`38b50f4c0f4d94f82d20b5f88e3f1ab1`|CC0 period bookkeeping|
|0x23021718|0x1eb4|`094a0a4bd289d3f8360093f83a10012a`|apply channel map|
|0x230210a0|0x183c|`002003462de9f041184f07f10508a7f1`|rebuild remap arrays|
|0x23021748|0x1ee4|`0021234b234a9b8eb2f8aa01012ba2f8`|period rate threshold|
|0x23024ace|0x526a|`00224ff46b51634b6648644dc0f80021`|CC2 slot5 counters|
|0x23021654|0x1df0|`08b5124bdb8943b1012b06d0022b12d0`|select next frequency|
|0x23021534|0x1cd0|`38b503461c4dec8fab87604000f024fb`|event-counter permutation/remap|
|0x23024c2a|0x53c6|`0024104b2246c3f804411149c3f80441`|disconnect prefix|
|0x23021dfc|0x2598|`70b5022200254ff480714ff0ff36174b`|switch protocol2 configuration|
|0x23020e84|0x1620|`022810b42ed0042827d0194bd3f8a028`|radio mode and tuning writes|
|0x23020d5c|0x14f8|`1a491b4b1b4ac1f8343e9378507892f8`|packet format configuration|
|0x230221a4|0x2940|`40f684710122034b01fb00331a710248`|mark disconnect then signal worker|
