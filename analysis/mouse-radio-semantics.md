# DeathAdder V4 Pro 1.20 鼠标无线核语义

依据 `mouse-radio-1.20-final`（1122 个函数，包含 OS/库，不能称为 1122 个无线函数）、已验证的 RAM 映射和 Nordic SVD。下面是静态恢复与分析命名，不是原始源码，也未证明每条分支在当前实机运行。JSON 保存镜像 SHA、调用关系、表数据及 GNU Thumb 汇编交叉验证。仅写此报告和同名 JSON，未改 Ghidra 项目或写设备。

## 1. 正常链路与 RF 测试明确分开

正常初始化链：`23021150 → 230259A4 → 23022E28 → 230218EC`。`23022E28` 同时初始化 DPPI/TIMER，传入 BASE1 与 MODE=4。此链与 `0E07A5B0` 测试配置不同。

`230218EC` 初始值：TXADDRESS=1，RXADDRESSES=0x0A，PREFIX0=0xC3C2C1E7，PREFIX1=0xC7C6C5C4，BASE0=0xEB8A542C，BASE1=配置值；MODE=4；TXPOWER 原始值0x18；PCNF0=0x01000005、PCNF1=0x0303001F；CRCCNF=0x102、CRCPOLY=0x11021、CRCINIT=0xFFFF。静态置信度高。

SVD 解码：LENGTH 字段5 bits；S0/S1长度0；16-bit preamble；最大payload31，静态长度0；base长度3字节加prefix；LENGTH/PAYLOAD等字段 MSB-first；whitening启用；CRC长度2字节、跳过地址。没有在此函数发现 DATAWHITEIV 的赋值，因此不以此给出 whitening seed。

`23021A04` 恢复初始 packet profile；`23021A7C` 用另一个 profile，并把 PREFIX0 改为配置地址的按位取反。业务流可改变 PCNF，因此上述只是初始化轮廓。

速率函数 `23021AF8(2)` 写MODE=4，`23021AF8(4)` 写MODE=9。握手选中mode=2→`23023544` 或mode=1→`230244CC` 均用前者；mode=4→`23025778` 用后者。SVD分别解释为 BLE 2M PHY 与 Nordic4M BT0.6 PHY；这不证明完整协议是标准BLE。私有 tuning 寄存器尚未命名。

测试函数 `0E07A5B0` 使用 ABABABAB/CCCCCCCC、可变CRC等模式；`0E07A688` 选择 `230039B0` 测试buffer并填充F0/CC/其他模式。不可混入正常地址或payload定义。

## 2. IRQ、定时和状态

直接检查官方镜像向量：`0E06C0F0 = 23021705`，按16个内核向量计算为IRQ44，匹配RADIO；`0E06C0E0 = 2302243D` 对应IRQ40 TIMER020。Thumb bit已保留。RAM函数 `23021704` 为无线事件处理，`2302243C` 为计时阶段调度入口。静态绑定高置信度；未读实时VTOR。

`23021800`：COMPARE0..5发布到DPPI0..5，ADDRESS发布到6，CHENSET=0x7F。`23022E28`：TIMER PRESCALER=5、BITMODE=2。计时compare数值不能直接当成毫秒、微秒或USB回报率，需另外验证时钟。

`23023AB8` 与 `23021704` 联合表明 `23002A04` 的0x18/0x19/0x1A分别具有空闲/TX/RX角色。某些TX后由定时器开启RX，PACKETPTR指向`23002630`。IRQ检查CRCOK，复制回包到`23002A96`附近，清计数并推进1..7循环序号。无CRCOK进入失败路径。具体状态命名为推断，寄存器/赋值/分支是静态事实。

下面补充 ISR 状态/寄存器证据，与主任务 `interrupt-map.json` 的 SVD 向量匹配一致：

|入口/状态|触发与动作|后继|
|---|---|---|
|RADIO `23021704`，全局mode=2|EVENTS_DISABLED置位后清除并调用`230227B8(5)`|握手状态0x14/0x16/0x17处理；5是内部事件值，不是IRQ编号|
|RADIO，业务RX状态0x1A|禁用RX订阅；检查CRCOK，复制响应、清计数或记录失败|业务状态回到0x18；同时清CRCOK/CRCERROR事件|
|TIMER020 `2302243C`|比较事件驱动调度，调用`23023AB8(1/3/6/8)`等；正常周期推进`23023A10`|更新频道、TX/RX阶段；事件码是私有软件参数|
|`23023AB8`，0x18|检查队列/待发条件，设SUBSCRIBE_TXEN/START和FREQUENCY，调用`23024078`写PACKETPTR|0x19 TX|
|`23023AB8`，0x19且要求响应|事件6使SUBSCRIBE_RXEN生效，SHORTS增加END_DISABLE，PACKETPTR=0x23002630|0x1A RX|
|`23023AB8`，无响应窗口或到期|TASKS_DISABLE，清订阅|0x18 idle|

这些是明确出现的模式条件分支；4 Mbps 模式还在TIMER ISR中有另外的阶段/缓存分支，未将上述2 Mbps路径直接推广为所有模式。RX成功不自动证明对每个payload做了正确序号校验。

## 3. 握手与配对候选

`2302253C` 扫描索引 `[37,38,22,39]`，经 `230221E0` 查40字节频率表，得到FREQUENCY寄存器偏移 `[2,26,50,80]`，对应2402/2426/2450/2480 MHz。扫描4位置循环；计数超过7换位置。表常量地址分别为`0E098A3C`、`0E098A14`。

`230227B8` 在CRCOK且头字节bit7/bit6均为0后处理buffer `23002A56`；length字节必须0x0B，消息号在offset+3：

|阶段变量23002A4A|接收|响应|已观察内容|
|---|---|---|---|
|0|0x11|0x12|检查能力掩码；条件性读取新的BASE1；同步计数等|
|1|0x13|0x14|选取业务模式低4bit、频道算法mode与频道索引|
|4|0x15|0x16|导入两组4频点，或37频道mask；结束后进入业务wrapper|

新地址仅在`2300298C != 0`路径采用，经`23021C40`更新BASE1及~BASE1。故可称连接协商/配对候选，不能把所有该流程都称为首次配对，或声称已经证明持久化；`23025F44`在此镜像反编译为空函数。

## 4. 帧组包与响应处理

`230215AC`管理队列：队列element+4写payload_len+2，element+6写类别左移3与循环1..7序号，payload拷到element+7。`230214E0`返回element+4，成为后续DMA包起点。因此DMA内存布局可恢复为：offset0=长度，offset1=标志/序号字段，offset2=类别/序号字段，offset3起=payload。线上位序还受PCNF影响，不是逐字节照搬内存。

`2302168C(a,b,c) = c | (b << 4) | (a << 7)`；`23021698(a,b) = b | (a << 3)`。调用方保证哪些bit有效尚需逐路径核对。`23024078`选队列、维护待发缓存并写PACKETPTR。类别1聚合分支将包offset3按位OR、offset4相加、offset5..6及7..8按big-endian16解码后相加再编码；这很像按钮/滚轮/X/Y累计，但未与输入报告独立对照，所以字段名称仍为候选。

无业务数据时 `23024078`可创建length5、payload类型0x17的保活/同步候选帧，并写计数。`23021704`成功分支可释放队列项、更新响应与循环序号。只用CRCOK不足以证明完整ACK关联/防重放或认证，尚未完整恢复回包各字段的语义。

`230238F0`对当前bank失败计数递增，超过3后推进频道索引并wrap；成功路径清零。`23024408`判断队列与待处理状态；`23024078`保留/重用缓存及聚合数据。这支持存在重试与失败后换频，但“3”是频道推进阈值，不能说全系统只重传3次。

## 5. 可复原的频道选择算法

正常调度链 `2302243C → 23023A10 → 2302218C`。汇编修正了反编译遗漏的参数：r0为递增后的16-bit event_counter，r1为 `(counter >> 1) & 1`。

- channel mode0/1：读取协商的两组4个频率值，按bank与失败推进索引选用。
- channel mode2/3：`23021D6C`读取37-bit启用mask，建立有效频道映射表，并令seed=`low16(BASE1) XOR high16(BASE1)`；`23021DE0`计算伪随机选择。

算法按汇编等价表达为：

```text
x = counter XOR seed
重复3轮：
    x = permute(x)
    x = (17*x + seed) & 0xffff
x = x XOR seed
channel = x % 37
若channel未启用：
    channel = enabled_channels[(x * enabled_count) >> 16]
frequency_offset = frequency_table[channel]
```

`230222E0`的真实表位于`0E098A04`：`[0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]`。它实现每个byte的bit reversal；反编译把相邻随机ASCII串连带呈现，不能把字符串当算法密钥。上述流程结构类似BLE CSA#2；没有据此宣称Razer链路符合完整BLE。

40项频率表：前37项为`[4,6,8,10,12,14,16,18,20,22,24,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78]`，末3项`[2,26,80]`。注意索引22=50。已静态恢复算法/表，但未知当前实机协商后的mode、BASE1、mask、counter，因此没有生成其正在使用的实际跳频序列。

## 6. 完成边界

高置信度的是寄存器常量、字节表、IRQ向量、直接调用和经过汇编确认的频道算法；状态角色、ACK/聚合语义是证据支持的分析命名。最终导出中无线直接核心未见bad-instruction；`23028CEC/23028CF0`仍为间接跳转回调警告，动态函数指针的调用关系未全解析。1122个反编译函数不等于完整无线源码已恢复。尚未获得空口抓包、实际配对状态/密钥、完整ACK字段匹配、全部重试上限及精确时钟时序；不声称已证明加密启用或禁用。
