# 接收器完整业务入口 2302455C 集成

已新增 `receiver_business_flow.c/h`，将六类接收入口接到实际业务消费及最终统计，**1152组原始入口差分通过**：class0..5各192组、peer0/1均覆盖。其中1148组一直运行到2302455C返回；4组停在真实USB驱动0E0622BC入口，随后用明确的外部结果独立验证真实续段。不能把这4条续段称为USB驱动已经执行。

每组比较全部65536字节RAM、E000E208的NVIC存储字、driver设备指针及pending边界。原记录 `receiver-business-flow-original.jsonl`、验证器 `verify_receiver_business_flow.py`、结果 `receiver-business-flow-comparison.json`；证据索引 `receiver-business-flow-exact.json`。模拟器从官方1.20原始2302455C入口开始，没有在旧dispatch/reassembly/management/consumer边界停下，也没有用成功桩替换它们。

## 集成顺序

class0直接使用已验证的`rr_control_consume`，包括控制状态、NVIC和该选定peer的统计。

class1..5依次执行`rr_business_dispatch → rr_business_rx`。重组产生management事件时运行`rr_dbc_management`，其返回0再交`rr_dbc_consume`；普通deliver直接进consumer。真实USB队列、class1合并缓存、A4管理链及队列purge、B1状态表更新、class5存储均继续执行。随后更新业务统计并执行`dispatch_finish`，清上下文8C..8F、递增成功/总处理计数。

原函数在非class0数据分支把下游peer固定传0，即使入口选peer1：重组消费者与其统计按peer0处理，而结束清理仍作用于选定peer上下文。more片和重组失配也会在返回后更新统计；duplicate或过短分支遵循原dispatch单独行为，不额外调用consumer。统计地址使用已经独立核验的4字节步长实现。

分派产生的状态先写回RAM，再执行下游；结束前重新读取上下文，而不是把旧副本整体覆回。这样A4清理peer0业务队列等下游状态不会被结束步骤丢失。

## 持久缓冲旧尾部修正

按授权修改`business_rx.c`：普通接收器事件把持久bank的完整128字节复制到payload，**逻辑event.length保持不变**。鼠标completed仍按长度复制；class2/4解密用局部零填充payload的规则不变。

原因来自原指令数据流：普通接收器传给消费者的是bank地址，不是按length裁剪的新缓冲。class3 B1消费者无论length多短，仍读bytes5/6/7。此前事件只复制total、其余清零，会改变完整链行为。

|原指令case|逻辑长度|此前bank的bytes5..7|最终230071B4..B6|
|---|---:|---|---|
|600|0|83 51 47|83 51 47|
|601|1|91 C3 31|91 C3 31|
|696|0|7D 04 A4|7D 04 A4|
|697|1|97 DF A0|97 DF A0|

这四例从真实接收入口运行到最终返回，证明旧尾部确实影响业务状态，不能当作无关padding删掉。长度0情形中首字节B1自身也来自原bank未被新片覆盖的内容。没有把它修成“更安全”的新协议行为。

回归结果：既有RX原指令1280组通过；既有C组件pipeline662组通过。后二者是保留原测试范围的回归，不能重复计为本轮新增1152原入口测试。

## 真实USB待续边界

非正常模式的消费链可能到达0E0622BC。此时集成接口返回1并保存`active/selected_peer/metadata/device`；此时还没有运行后续统计、上下文清零和最终计数。接口返回值是分析模型的边界状态，不是原void函数的返回值。

`rr_receiver_business_resume`要求调用者明确提供driver结果；执行已经恢复的consumer后续，再更新统计、完成分派。4个测试使用真实执行产生的调用栈，在driver边界记录中间RAM，然后明确给出外部结果，继续执行原续段到2302455C返回；与C的resume结果全RAM一致。driver本体未执行、未声称成功。真实driver内的RTOS与设备间接调用仍是未恢复项。

## 覆盖边界

用例含无效有符号packet length0/80/FF、六类、重复业务序号、运动累计代次、两peer、碎片more/最后片/索引失配、class2/4解密、USB关闭/满/回绕/坏索引、管理及厂商消息、旧尾部读取和结束统计。

适用范围沿用组件：重组bank总长<=128，class2/4完成长度8/16；超出范围的-1是恢复接口未覆盖标志，不是原固件拒绝或回滚保证。未实现driver0E0622BC本体、射频收发、真实USB传输完成及中断并发时序；无硬件操作。
