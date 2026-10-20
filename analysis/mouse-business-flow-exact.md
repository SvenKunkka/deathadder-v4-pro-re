# 鼠标业务接收集成：1.20

新增 `recovered-code/portable/mouse_business_flow.c/.h`，入口 `rr_mouse_business_flow(ram,event)` 对应原 `23022508`。复用 `business_control.c` 的 class0 及 `business_rx.c` 的六类缓冲投影，链接时还需 `business_tx.c`、`business_cipher.c`。没有修改这些依赖或消费者模块。

1600 组整个原入口 Thumb 指令执行，与 C 的全部 65536 字节 RAM 对照通过；另外 7 组域外预检保持 RAM 和 event 不变。消费者 `23025e38` 仍为独立延期调用，本模块没有同步执行它。结果只证明下述输入域中的静态代码行为，不证明完整 RTOS 调度、空口或设备行为。

## 完整调用次序

`23022508` 读 u16[23002798]：mode1→230245d8，mode2→23023634，mode4→23025890，其余直接返回。三者都先把 byte[23002a96] 作为有符号8位长度测试，只有1..127继续。

头 byte[23002a98]：class=(head&0x3f)>>3，sequence=head&7；高两位不参与这两个字段。

class0 走 control 模块：mode4 的28复制4字节到230026be；29写BE16值到23002972、置230027c5=1并写230026c2。原代码没有进一步按长度验证这些读，因此长度1/2也读已有尾部。三种mode的class0仅在230029e0非零时统计 metadata=byte[230029e5]；不更新业务去重序号、不重组、不清23002a10，也不置230029d0。

非零class先比较23002a3a+class的旧sequence；相同直接返回。不同先写新sequence，再调用23025e04(0,class,23002a99,(uint8)(len-2),metadata)，mode4 metadata=230029e5，mode1/2 metadata=0。23025e04调用230259ec，然后更新统计；无论重组成功、分片继续还是索引不匹配，返回后都清u32[23002a10]、写byte[230029d0]=2。

## 重组与旧尾部

230259ec读取首字节，index=byte&31，bit7表示还有后续片，bit5/6被忽略。class缓冲基址23006850+class*128，预期index在23006b50+class，累计长度在23006b58+class。

index=0重启，在缓冲起点复制size-1字节，长度写为该值的低8位，expected=1；不会清整个旧缓冲。非零index与expected不符时只清该类expected/length并返回，完全不复制，且不会提交work。匹配时从旧length追加size-1字节，再递增expected并以低8位存长度。

bit7清零的终片把该类累计长度写2300779c、class写2300779b，仅复制累计长度字节到230067d0；目标剩余旧尾部保留。随后清该类expected/length，再尾调用work-submit(230067a0)。零字节完成也保留旧消费者缓冲内容，更新class/length并尝试work。

复用RX接口的支持域是class1..5、复制总长≤128。原分派可计算出class6/7，原重组也没有六类检查；它们会落到数组之外并可能重叠其他全局，不将这种行为假装成正常第七/八类。新序号class6/7返回宿主边界-2；重复序号仍自然返回。没有把接口的128字节界限说成固件检查。

## 长度异常与顺序

mode代码先sxtb(len-2)再uxth，23025e04再次uxtb。因此 len1 的实际size=255，复制254字节；len2 的size=0，32位size-1=0xffffffff。支持域外预检返回-2且不改变投影。注意非零分片index不匹配发生在复制之前，故len1/2的该分支无需大复制、可以精确恢复，并已与原指令对照。

正常len3..127对应0..124字节payload；测试覆盖首片、续片、索引不匹配、总长128、零长度完成和保留旧尾部。

## 真实work提交边界

23025d1c注册work230067a0的回调为Thumb地址23025e39（函数23025e38）。230259ec尾调用2302c4b0→0e0952ec→0e09518c，原指令实际执行，没有把函数改成空函数。

work.flags位于230067ac。0e09518c先测试bit1：置位返回-16；否则bit2置位返回0。这两个自然fast-return均不追加队列、不修改work对象。优先次序意味着flags=6返回-16。调用方忽略返回值，仍更新统计及接收标志。event.work_requested表示尝试提交，不能解释为新任务成功入队；event.work_return记录该自然返回值。已有bit2的队列项仍可能由真实RTOS之后执行，但该时序不在本模型内。

flags&6==0且完成终片需要进入真实RTOS队列/唤醒分支，目前返回宿主边界-3且不修改RAM/event；非终片或索引不匹配不要求这个条件。测试包含这些分支的flags=0。宿主负值是预检状态，不是固件的函数返回值。

## 统计

先count=(u16[23006b8a]+1) mod65536。如果count>30000，清整个u32[23006b88]；否则低16位累加metadata并截断，高16位写count。count从65535溢出为0时不触发大于30000分支，低位仍累加。非零class每次新sequence都统计，包括重组失败；mode1/2只加count，mode4还累加metadata。class0的同类统计受230029e0控制。

## 验证与限制

`EmulateMouseBusinessFlow.java`校验原固件及RAM映射后，从23022508运行到返回哨兵；1536组基本覆盖加64组mode4 class0短长度，共1600组。比较全64KiB RAM，检查BASEPRI恢复。Ghidra缺少getBasePriority实现，沿用已有CPU状态桥接，读写同一ArmCpuState；ISB为Ghidra的惰性实现并在日志明示。没有修改目标Thumb指令或打桩RTOS函数，没有模拟并发/射频事件。

输入分组：不支持mode128；非正有符号长度128；重复序号128；class0基础128；首片非终128；首片终片128；续片非终128；续片终片128；索引不匹配128；len1/2索引不匹配128；class6/7重复序号128；零payload续片到总长128的128；mode4 class0补充64。

运行 `rtk proxy python3 outputs/razer-radio-re/analysis/verify_mouse_business_flow.py` 可复核C差分。`mouse-business-flow-comparison.json`保存结果/依赖hash，`mouse-business-flow-evidence.json`保存原固件hash及10段原指令范围、偏移、bytes与SHA256；`mouse-business-flow-instructions.txt`保存GNU Thumb反汇编。真实RTOS入队、调度及支持域外重组尚未恢复，消费者必须由独立调用方按真实延期语义处理。
