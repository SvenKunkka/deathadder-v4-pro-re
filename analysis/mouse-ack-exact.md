# 鼠标1.20 mode1/2：ACK、序号和重发的精确范围

交付 `mouse_ack_model.py`、`test_mouse_ack_model.py`；8项测试全部通过。它是已证实分支的独立状态模型，不是完整固件仿真器，不含设备I/O。原始汇编、地址与文件SHA保存在`mouse-ack-exact.json`。以最终RAM导出为依据，重新读取原始Thumb指令。

## 关键结论

在观察的mode1/2 ISR成功路径中，RX状态、DISABLED和CRCOK决定队列释放；没有先比较回包序号与发送序号。另一个SWI负责下行payload按类别去重，发生在队列释放之后。两件事不能混为“匹配了上行ACK序号”。这是对已审阅静态路径的描述，不是安全漏洞结论，也不排除其他接收硬件或上游门控。

## 明确入口与条件

`23021704`汇编tail dispatch：业务mode2→`23022FBC`；mode1→`230236AC`。全局状态0/1/2/5另有清理、握手或测试路径，因此本模型不混入那些分支。

- 两者先清事件；若DISABLED!=1则返回。
- mode2在TX0x19仅清TXEN订阅；RX0x1A才处理响应。
- mode1也只有RX0x1A进入响应处理。
- mode2在`2302303A–40`检查CRCOK；mode1在`2302373A–40`检查。成功到队列释放的完整控制流没有读取packet+1作序号匹配。

## 头字段与两个序号

|位置/函数|精确操作|范围|
|---|---|---|
|packet+1，`2302168C`|`(low | seq<<4 | flag<<7) & 255`|调用函数没有预先mask参数；不能只凭helper给所有bit命名|
|packet+2，`23021698`|`(seq | class<<3) & 255`|队列构造负责传有效类别/序号|
|`230216A0`|`value & 7`|packet+2低3bit序号|
|`230216A8`|`(value>>3)&7`|packet+2 bits3..5类别|
|`23021680`/`23021688`|bit6 / 右移7|握手校验用，不是ISR ACK匹配|

`23002A1E`为成功响应后推进的发送周期序号；加1后等于8就变1。ISR未将回包packet+1的序号与它比较。各payload类别另有1..7序号，在SWI用`23002A3A[class]`记录最近接收值。

## 成功、失败与队列释放

mode2成功（`23023060–DC`）：复制16个DMA字节到`23002A96`；清源buffer长度；标记`23002A22=1`；推进周期序号；清no_response_count与当前bank失败数；当前TX队列id `23002A1A<=5`时调用`2302145C(0,id)`；触发SWI4；回IDLE0x18。

mode1成功（`2302376C–238D2`）：同类操作，另清24B聚合cache `23002670..23002687`和`23002A26`。若成功前bank失败数>2，仍会推进频道索引（`230237B6`，`2302382C`），随后清失败数。mode2成功没有这一条推进。

队列释放函数`2302145C`：读指针加1，以byte截断，等于该队列capacity才wrap0；没有检查当前队列是否为空。ISR传的是当前TX队列id，不是回包payload class。id>=6不释放（包括0xFF缓存/合成包路径）。

失败：不推进发送周期序号，不释放当前队列；清`23002A26`，置`230029D0=2`，回IDLE。mode1还按rate_selector/slot_phase调用`230238F0`或置failure_due。模型要求显式给出global_state和event_counter，缺失就返回未知提示，不伪造时序。

## SWI4下行payload去重

向量绑定`23022508`，tail dispatch mode1→`230245D8`，mode2→`23023634`。先用LDRSB检查length>0，再拆packet+2。

- class0走诊断/RSSI分支，不交付普通payload。
- class!=0：仅当seq与`last_rx_seq[class]`不同才更新记录并调用`23025E04(0,class,packet+3,length-2,0)`。
- 重复下行payload不会撤销ISR已经发生的上行队列释放。
- 长度处理是signed8 `(length-2)`后转unsigned16；本模型保留此行为。异常值的模型结果不是实机可达性/漏洞证明，真实RF长度受PCNF及其他路径约束。

## 重发、聚合与失败换频

`23024078`会保留待发packet/聚合cache；class1分支先将队列内容并入cache，再立即`2302145C(0,1)`。因此“所有队列只在ACK后释放”也不成立：class1可先出队、保存在重发cache中。mode1成功清cache；失败不清聚合数据。其按钮/滚轮/坐标语义仍未与上游类型独立核对。

`230238F0`精确计数门控：require_due!=0且failure_due=0则原样返回；global_state3时rate_selector1/2/4/8可计数，16/32/64分别在event_counter模2/4/8为0才计数；global_state4要求arg0=1。其它不计数并清due。允许时bank计数以16bit加1，>3才推进频率byte索引；索引等于frequency_count才wrap，计数清零。这是换频阈值，不是统一丢包/重传次数上限。

## 状态模型与测试范围

模型覆盖：头构造/解析、mode1/2 DISABLED成功/失败的队列/序号/cache核心副作用、SWI去重、失败门控及频率索引。省略计时捕获、外设清除全过程、上层callback、class0统计、完整TX选择/聚合、全部timer slot和mode2组包；这些不能由此模型宣称完成。

测试独立读取官方RAM字节：解析UBFX/AND立即数并穷举256个输入；核对header构造机器码与反汇编shift；核对队列5、序号8、成功换频2、失败换频3等原始CMP立即数以及IRQ向量。另用独立事件夹具验证不匹配下行序号仍释放TX队列、重复payload过滤、无DISABLED不执行、队列边界、mode1/2成功差异、失败门控周期。不是完整ARM执行对照或空口动态验证。

运行：在analysis目录执行 `python3 -m unittest -v test_mouse_ack_model.py`。模型可直接执行显示一个事件示例。
