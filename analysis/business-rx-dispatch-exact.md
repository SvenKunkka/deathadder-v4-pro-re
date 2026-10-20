# 业务接收、去重与组件串接：1.20 原指令证据

本轮新增 `business_rx.c/h` 和 `business_dispatch.c/h`。数据来自已经核验映射的两端原始 Thumb 指令；不是重新编译反编译伪 C。

## 原指令比对范围

|入口|已验证范围|输入数|停止位置|
|---|---|---:|---|
|鼠标230259EC|六类重组、片号拒绝、首片重启、完成缓冲和标志|576|返回，或真实2302C4B0 work-submit入口之前|
|接收器23025004|六类重组、motion转换、class2/4解密和activity标志|704|返回，或23024C88管理处理/23020250消费者入口之前|
|接收器2302455C|mode4 class1..5每类序号去重、累计运动差分|640|返回，或真实230254A0入口之前|

合计1,920组原指令输入。此前1,152组RX基础用例又补128组定向加密输入，共1,280；后128组覆盖16个key表项、class2/4、全零/仅首字节/末字节/第二字节非零模式，以验证activity的清零、置一和保持。加密只是构造输入，预期输出来自原始接收器解密指令。CPU、函数和指令均未替换；目标副本先核验镜像SHA、完整Flash映射和运行RAM复制。

RX比较整个784字节重组bank、128字节完成缓冲、类别/长度、motion和activity，并检查传给真实后续入口的payload与长度。dispatch比较选定peer全部512字节上下文、共享motion6字节、两个16位计数及全部转交参数。初态包含非零旧缓冲和寄存器以外的RAM随机状态。

## 不能省略的行为

- 分片控制低5位为索引，bit7为more；bits6:5在本重组入口不参与索引。索引0重新开始；非零不匹配时只清进度/长度，不擦旧数据。最终完成后同样保留数据区。
- 设备函数没有本恢复接口的128字节容量检查；C返回-1表示本机模型的显式边界，不能解释为原设备会拒绝越界包。接收器class2/4完成长度8/16已覆盖，其余长度的原变换循环尚未纳入本接口。
- class1使用已有重组缓冲的前6字节，因此不足6字节的完成消息仍可能读取旧尾部。附加motion被合入USB基础格式；清除motion[0:3]与[4:8]，offset3保留。该细节已由原指令比对。
- class2输出8字节并按8字节是否全零更新activity；class4输出16字节，仅当第0字节为1时按bytes2..15更新activity。其余class4首字节保留旧activity。
- dispatch包长是**有符号8位**大于零才处理。新序号在业务片长检查前保存，因此长度1/2也会消耗该类序号；这些不转交但推进两个计数。重复包通常只推进总计数，class1还有共享motion/空闲计数的清理。
- 两个输入peer都已验证，转交给230254A0的peer参数仍是0。高位累计标志及epoch决定清零基线或做累计差分，不能把无线字节直接当作最终相对位移。

`rr_business_dispatch_finish`对应230245EC之后的计数/空闲状态处理。未转交的短包会自然执行这段并纳入原指令比较；转交报文的该后缀在本轮原指令记录中尚未执行，组件串接中在接收处理返回后调用它。没有把这一边界隐藏为完整ISR已验证。

## 组件串接验证

`verify_business_pipeline.py`把已分别验证的TX、环队列、dispatch、RX和cipher C模块串起来。662组消息、3,890个片段通过，另检查1,728次重复帧抑制与320次末片先到后重新起包。覆盖全部16个安装key值，class2/4零填充/截断及加解密往返，class1运动格式，class3/5消息和下行0..90字节checksum分片。

这662组是**C组件集成**，不计入原指令用例数。测试构造报文头，没有执行完整mode4聚合、ACK/重试、PHY调度、USB消费者、管理命令消费者或实物RF。测试验证了下行整消息checksum值，但尚未替代真实鼠标消费者的checksum/命令处理。

## 复现与下一步

- `analysis/verify_business_rx_original.py` → `business-rx-original-comparison.json`。
- `analysis/verify_business_dispatch_original.py` → `business-dispatch-original-comparison.json`。
- `analysis/verify_business_pipeline.py` → `business-pipeline-comparison.json`。
- 原始执行脚本为 `ghidra-scripts/EmulateBusinessRx.java`、`EmulateBusinessDispatch.java`；记录为两端`*-rx-original.jsonl`及`business-dispatch-original.jsonl`。
- 本文JSON包含原始入口字节、文件偏移及源码SHA。RX初轮日志因零长度readMemory工具调用失败被v2/v3结果取代，零长度目标行为已覆盖，未跳过目标指令。

接下来补class0控制分派、管理/厂商消费者、真实key安装包装、转交后的统计链、完整收发/重连与RTOS调度；全部仍以完整2.4GHz目标为范围。
