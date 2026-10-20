# 接收器mode1/2：静态续接索引

对象为接收器无线核1.20：SHA256 `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`。本轮仅复用`analysis/dongle-radio-1.20-final`及`analysis/runtime-images/dongle-ram-gnu-disassembly.txt`；**没有新增portable代码、没有运行模拟、没有新增通过用例**。以下是静态证据与后续工作边界。

注意：最终反编译器把多个尾跳转处理函数内联进`23020a00.c /23021bbc.c /23021be4.c`，因此部分真实主入口没有单独的`.c`文件；真实入口由GNU指令确认，不能从“没有文件”推断不存在函数。配套JSON保存精确调用site、地址、原字节和GNU行号。

## 入口接线

|中断入口|分支条件|mode1真实处理入口|mode2真实处理入口|
|---|---|---|---|
|RADIO `23020A00`|3230==5先转另一路；否则3234选择|`23023498`|`23022A50`|
|TIMER `23021BBC`|3230<2立即返回；3234选择|`23023C60`|`23022ED4`|
|SWI4 `23021BE4`|3234选择；r0=u16[71A4]|`23023968`|`23022D90`|

`23021C24(peer)`把peer写71A4，然后对E000E208写10000000请求SWI4。3230==5的RADIO路由经230271C0转0E05D099，不在mode1/2本索引内。这里mode仅指固件字段值，不擅自将其等同蓝牙/速率名称。

公共context地址=230033E8+peer×F84；connection state为+00(u32)，radio state为+80(u32)，事件计数+86(u16)，连续失败+88(u16)，业务间隔+8C(u32)，两个频道统计+90/+92(u16)，已选队列+96(u16)，序号+9A/+9B(u8)，回复标志+9C/+9D(u8)，接收记录+114(16B)。mode1的RADIO使用u16[23006274]选context；mode2用u16[230032D0]，SWI4使用71A4，三者不能混为同一变量。

## RADIO mode1：23023498

先依次清TXREADY/RXREADY/ADDRESS中值为1的事件；只在END==1且globalstate>1执行数据处理。选中context的state12且CRCOK==1、DMA3050首字节非零时，清CRCOK并把DMA的16字节原样复制到context+114，再清DMA长度，+9F=1。**此处没有mode4的附加和校验或长度减1。**

header[1]的bit7分别写+9C/+9D，bits4..6为确认序号。新序号清失败和频道统计；仅当已选队列+96非零才递增发送序号（8回1）、调用2302073C pop并记录上一队列。最后+96=0，写+9B并请求SWI4。这个非零sentinel与mode4“队列<6、重置255”不同，不可直接套用mode4事件函数。低4位由230209C8提取，写本context当前频道统计与共享context2频道统计。

CRC/长度失败时清DMA长度，按341C==1或slot<2设置+ A2(348A)失败标志，否则调用23023708(1)。成功/失败均回state11。原state13在END触发DISABLE。DISABLED==1时：state13的频道统计>2可推进5349[channel]候选（5384==0才推进，达到5353时回0），清对应统计并保持state13；最终23020C30清CRCOK/CRCERROR。

`23023708`还包含按connection state3/4、341C间隔及事件计数低位门控的失败累加，统计>3时推进候选。该门控与DISABLED里的>2不是同一个阈值，后续应分别做原指令边界测试。

## RADIO mode2：23022A50

清TXREADY/RXREADY、非零END；真正状态分派位于DISABLED==1，且globalstate>1。此入口未出现mode1的ADDRESS清除步骤。

|radio state|DISABLED路径|
|---|---|
|8|回7|
|9|CRCOK时230223F0(peer,context+D4)握手处理；返回<2回7、返回2触发DISABLE→10；CRC失败回7|
|10|清TXEN/RXEN/DISABLE订阅，触发DISABLE，调用23021DBC应用协商协议，再2302546C提交type1连接通知|
|11|保持11|
|12|CRCOK时复制3050的16B记录并清DMA首字节，确认序号/队列pop/SWI4逻辑；随后回11|
|13|保持13|

state12的CRCOK路径**没有独立非零长度门槛，也没有mode4长度减1/和校验**；SWI4稍后有signed-byte长度>0判断。确认队列仍使用非零sentinel。无匹配状态不凭空修改state；出口清CRC事件。

握手230223F0：0x12→0x13、0x14→0x15、0x16→完成；23022360构造发起/续传包。23021DBC把3236协商值复制3234，按1/2/4分别设置radio/timer，state11和connection state3、清相关计数，IRQ掩码不同：mode1=148、mode2=100、mode4=144。协商转移和通知队列是mode2 IRQ必须跨过的真实链，不能用成功桩省略。

## TIMER mode2：23022ED4

事件按CC0→CC1→CC2→CC3..7优先选择，每次仅处理第一个值为1的事件。

- CC0：CC0=16000，关TXEN/RXEN订阅，CC1=4160、CC2=4640；23022888(peer0,event1)，slot=0。
- CC1：先关DISABLE订阅。slot0通过230226C8准备下一上下文后变1；slot1通过230226C8(2)后变2并构造应答；slot2通过230226C8(0)后回0。state9回7和握手子状态清理按原分支发生。
- CC2 slot1：关订阅，CC1=8800、CC2=9600，23022888(peer1,event1)。slot2：关TXEN，CC1=14720、CC2=0；对context0/1/2计数、选择下一频率3222，更新频道bit，然后分别23022E48(0)、23022E48(1)。其他slot无该计数尾段。
- CC3..7只清对应事件。

230226C8根据connection state<2、==2、>2选择发现/握手/已连接路径，写BASE1、FREQUENCY、地址掩码、DMA指针和DPPI订阅。state==2使用固件0E06FBAC的4项频道索引，并以事件计数奇偶决定TX/RX；23022888维护radio state7/8/9与握手超时计数。普通数据state11在event1设置DMA3050、清长度并转12。

应答选择：先考虑context0回复与队列，再context1；队列peek为230207EC，无队列构造class0 opcode1F同步记录，编码两个候选频道索引；共享header由2302098C组合，两端回复标志与选中peer/队列标志进入不同bit。复制16B到3070，PACKETPTR=23003070。不能按mode4的单peer header/事件计数同步记录实现。

23022E48对每个业务peer：失败>99时DISABLE，connection state=0、radio state=11，再23021DFC回退配置、230221A4信号量、230254F8 type2通知；未超时则业务间隔<200为state3，否则4。

## TIMER mode1：23023C60

关键分支为u16[341C]==1，其他间隔走另一时隙表；这不是mode4的六阶段。

|路径|CC0设置(CC1,CC2,CC3)|CC1的slot推进|CC2末尾|
|---|---|---|---|
|341C==1|(2880,3840,11200)|0→1→2→3→4→0|slot4：CC1=15040、CC2=0；计数/跳频/超时|
|其他|(3680,4640,2560)|0→1→2→3→0|slot3：CC1=15040、CC2=0；计数/跳频/超时|

CC0还CC0=16000、slot=0并通过230233B0(event1)推进接收。CC2细分时间表见原23021BBC.c中的mode1分支及GNU23023C60..23F64：341C==1的中间对为(2880,3840)、(5600,6560)、(8320,9280)、(11840,12640)；其他为(3680,4640,0)、(7040,8000,0)、(11680,12640,10560)。CC3负责接收超时/STOP检查，不能与CC4..7一样直接清除后结束。

辅助函数：230232D0配置各slot订阅、FREQUENCY/BASE1/地址；23023268把当前context选择6274设0或2并取消订阅；230233B0按action1/2/4/5处理state11/12、PACKETPTR与STOP，长度(首字节−1)<12是超时分支的重要条件。23023BCC检查context2 state13，按event/间隔/回复标志调用230237E0排队应答，失败时取消TX并DISABLE；230237E0依六队列优先peek或构建候选索引同步包。

周期末23023B5C(2)计数并跳频，+8C在200处饱和（与mode4的32位持续递增不同）；23023AE4执行peer0失败阈值100与断连链。跳频时先更新32CA再选择频率3222，其顺序也不同于mode4先用旧32CA计算3226。

## SWI4接到现有业务层：可复用和不可复用

两种mode都检查context+114为signed byte>0；class=(byte+116 &63)>>3、seq=byte+116 &7。不能把非法短帧自动“修好”：mode2对len−2的signed转换以及class1临时栈复制仍需后续精确测试，当前仅记录原预置条件。

**mode2 23022D90**：class0只调用2302552C(peer,metadata)，不执行mode4 class0 opcode2B逻辑。数据类重复序号直接返回；新序号保存后按len−2送230254A0，class1额外前置0分片头并改长度len−1。保留原peer，metadata=context+69；随后清该peer的32位业务间隔+8C。

**mode1 23023968**：class0只处理opcode17（BE16值写业务间隔）及2C（待用间隔/目标事件计数），再调用统计函数。重复class1在reply==1时清共享motion缓存，并清业务间隔；其他重复类直接返回。新class1以motion缓存计算X/Y/wheel差分，重组7B前置0记录；新其他类用len−2，非正长度不下传。调用230254A0时数据分支peer参数固定0，metadata仍取原选中peer+69，最后清原选中peer业务间隔。未见mode4的accumulated/epoch分支与dispatch_finish全计数行为，因此现有`rr_receiver_business_flow`不可原样用于两mode。

共同下游为：

`230254A0 → 23025004 → [23020128解密 /23024C88管理] → 23020250 → 230268B0`，再更新peer统计。已有`business_rx`、`business_cipher`、`dongle_business_consumer`和`rr_dongle_business_stats`是复用候选；需要新的mode1/2输入适配与尾段，不能只换mode字段。230254A0/2302552C实际统计步长为4字节（GNU lsl#2），反编译器某些表达显示*2是类型缩放，不应再次照抄。

## 外部调用和下一阶段边界

|真实入口|上游|仍需处理的含义|
|---|---|---|
|0E06CBDC /0E06CD54|2302546C连接、230254F8断连、23025580配对通知|实际消息队列put，失败则purge重试；保留消息长度与栈尾数据|
|0E06D0D0|230221A4|真实信号量更新/唤醒线程，不能当作只改标志|
|0E0622BC|共享业务消费者USB路径|实际USB驱动边界，沿用明确pending/continuation|
|0E06F35C/0E06F3AA|memcpy/memset thunk|普通软件内存函数，可实际执行，不应打成功桩|

建议续接单位：mode1 RADIO、mode2 RADIO/握手转移、mode1/2 SWI适配、mode1 TIMER、mode2 TIMER各自建立原指令差分；已有底层库只在参数和副作用契约匹配时复用。无需重新提取固件或重建Ghidra项目。当前所有结论是静态映射，尚未证明mode1/2全链执行等价。

## 精确入口证据

|地址|GNU行|镜像偏移|入口16原字节|作用|
|---|---:|---|---|---|
|0x23020a00|1004|0x119c|`094b1a88052a07d09b88042b08d0012b`|RADIO vector route|
|0x23022a50|4079|0x31ec|`8e4bd3f80422012a04bf0022c3f80422`|mode2 RADIO handler|
|0x23023498|5016|0x3c34|`2de9f84f944bd3f80422012a04bf0022`|mode1 RADIO handler|
|0x23021bbc|2690|0x2358|`084b1a88012a06d99b88042b04d0012b`|TIMER vector route|
|0x23022ed4|4468|0x3670|`2de9f047c74b82b0d3f8401101293bd0`|mode2 TIMER handler|
|0x23023c60|5726|0x43fc|`38b500bfbf4bd3f84021012a4dd0d3f8`|mode1 TIMER handler|
|0x23021be4|2707|0x2380|`0d4b9b88042b04d0012b0cd0022b0ed0`|SWI4 vector route|
|0x23022d90|4355|0x352c|`2de9f04740f6847400fb04f4294f84b0`|mode2 business dispatcher|
|0x23023968|5452|0x4104|`40f684732de9f04f00fb03f3594f85b0`|mode1 business dispatcher|
|0x23021c24|2734|0x23c0|`4ff080520249034b0880c3f808217047`|write selected peer and pend SWI4|
|0x230223f0|3479|0x2b8c|`2de9f04f40f6847700fb07f7ac4c0546`|receiver handshake response state machine|
|0x23022360|3424|0x2afc|`70b5014640f6847500220b2301fb05f5`|handshake offer builder|
|0x23021dbc|2883|0x2558|`10b50e4a0446d388042b938004d0012b`|apply negotiated protocol and timers|
|0x2302546c|7969|0x5c08|`0121024610b58ab000680191516802ab`|connection message type1|
|0x230254f8|8027|0x5c94|`0221024610b58ab000680191516802ab`|disconnect message type2|
|0x23025580|8084|0x5d1c|`0246052110b58ab00068019151689268`|pairing message type5|
|0x230226c8|3744|0x2e64|`f8b540f6847500fb05f5654e04467259`|mode2 radio subscriptions and address/frequency|
|0x23022888|3911|0x3024|`2de9f84340f684736a4d044603fb0053`|mode2 timer radio state helper|
|0x23022e48|4417|0x35e4|`2de9f04140f6847400fb04f41d4f82b0`|mode2 peer timeout|
|0x23023268|4785|0x3a04|`154a164b928eb3f8a030012a13d063b1`|mode1 selected context and subscription stop|
|0x230232d0|4833|0x3a6c|`38b5314b9b8e012b06d1304ab2f8a030`|mode1 slot subscriptions|
|0x230233b0|4918|0x3b4c|`38b5344cd4f880200b2a09d00c2a06d1`|mode1 RX state action|
|0x23023708|5228|0x3ea4|`324b10b193f8a22042b11a68032a06d0`|mode1 failure/channel candidate update|
|0x230237e0|5315|0x3f7c|`70b50025aeb231460020fcf7ffff0135`|mode1 queued ACK builder|
|0x23023b5c|5626|0x42f8|`40f6847210b500fb02f2154b99581344`|mode1 end-cycle counting and frequency|
|0x230254a0|7993|0x5c3c|`38b5bdf81050dbb20446c9b2c0b2fff7`|shared RX and peer-aware stats|
|0x2302552c|8051|0x5cc8|`09b3ff291fd010b4114b041d53f82420`|shared peer-aware stats only|
|0x23025004|7540|0x57a0|`2de9f04f1578dff8c4918db08df80f30`|shared fragment reassembly|
|0x23020128|117|0x8c4|`70b505460c7888b068460e4622462946`|shared cipher wrapper|
|0x23024c88|7167|0x5424|`0b78ab2b0ad0ac2b03d0a42b08d00020`|shared management consumer|
|0x23020250|240|0x9ec|`70b5564b8446b3f802e00c46bef1010f`|shared business consumer|
|0x230268b0|10106|0x704c|`f8b5184b1d789db1174b184f1e5c184b`|shared USB queue|
|0x23021dfc|2907|0x2598|`70b5022200254ff480714ff0ff36174b`|fallback protocol2 configuration|
|0x230221a4|3245|0x2940|`40f684710122034b01fb00331a710248`|disconnect flag and RTOS semaphore|
|0x23020c30|1224|0x13cc|`0022034bc3f82c22c3f83022704700bf`|clear CRC events|
|0x2302073c|751|0xed8|`40f68472084b02fb0033194491f86021`|queue pop|
|0x230207ec|816|0xf88|`40f68473114a10b503fb002353fa81fc`|queue peek|
|0x23023ae4|5581|0x4280|`30b51a4c83b02368022b0ad9b4f88830`|mode1 peer0 timeout/disconnect|
|0x23023bcc|5667|0x4368|`38b5204c04f58053d3f8883f0d2b00d0`|mode1 ACK scheduler and context gate|
