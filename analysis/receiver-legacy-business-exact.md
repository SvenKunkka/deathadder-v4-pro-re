# 接收器mode1/2完整业务适配：原指令差分

新增`recovered-code/portable/receiver_legacy_business.c/.h`，恢复mode1 `23023968`与mode2 `23022D90`，复用既有RX、cipher、management/USB消费者。**3456组原指令入口测试PASS**：3444组完整返回，12组停在实际USB驱动入口`0E0622BC`；12组在明确提供外部结果后继续执行原尾段，也与C一致。未使用成功桩、未修改共享模块、未写设备。

## 验证和证据范围

两mode各1728组，六class各576组，context0/1/2各1152组。每个组合96变体，覆盖新/重复序号、metadata0/1/127/128/254/255、长度0/128/255直接返回、class0控制opcode、分片index0/1/3/31和more、重组索引失配、cipher完成8/16B、管理消息与USB队列状态。90组短B1输入fixture保留整bank旧尾部的消费者语义；该数表示输入覆盖，不声称每组都执行B1消费者。

完整比较64KiB数据RAM、实际USB边界device指针、NVIC未写入以及续接后的最终内存。context2是输入参数覆盖，不额外宣称实际无线模式会把业务数据送到该context。mode2 class1本轮有效包长度为8；原本会覆盖临时栈的畸形长包不在等价范围。

可复验：`python3 analysis/verify_receiver_legacy_business.py`；输出`receiver-legacy-business-comparison.json`。原指令脚本`ghidra-scripts/EmulateReceiverLegacyBusiness.java`，记录`receiver-legacy-business-original.jsonl`。固件SHA256 `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`；执行前校验完整flash和RAM代码映射。

## 两入口共有的数据合同

context=230033E8+peer×F84；长度+114按signed byte>0判断，class=(+116 &63)>>3，seq=+116 &7；metadata来自+69，重复表+ B7 +class。长度0或128..255直接返回。class0不走数据去重。

新数据调用共享`230254A0 →23025004 →管理/解密→23020250`；其后按**实际转发peer**更新统计，再清**原选中context**的32位+8C业务间隔。模式差异通过两个peer分别保存，USB暂停时也保留，避免把peer1/2尾段误计到peer0。

## mode1：23023968

- class0 opcode17：BE16(payload+1)写context+8C；opcode2C：payload+1写u16+36、BE16(payload+2)写u16+38；其他opcode不做控制修改。随后统计使用原peer。没有mode4 opcode2B通知，也没有mode4额外33DC计数。
- 重复class1：reply+9D==1时清共享motion30A2..A7；无论reply值如何都清选中context+8C。重复其他class直接返回。
- 新class1：计算X/Y/wheel与共享motion缓存的差值（输出按16/8位截取），组装7B的`0,buttons,wheel,dxBE16,dyBE16`。reply==0更新缓存，否则清缓存。高位epoch/accumulated位不按mode4处理。
- 新其他class：保存序号后，以signed(len−2)>0决定下传；不下传时仍清+8C。
- 所有新数据调用共享下游时peer固定0；metadata仍来自原选中peer。

## mode2：23022D90

- class0仅统计原peer，不执行mode1的17/2C，也不执行mode4的2B/2C/17控制动作。
- 重复数据类全部直接返回，不清业务间隔或共享motion。
- 新class1：原数据前插0分片头，长度从len−2改为len−1；没有mode1的运动差分。其他类以len−2直接下传。
- 数据下游及统计保留原peer。返回后清该peer+8C。

两mode都不能复用mode4的整个`receiver_business_flow`/`business_dispatch`过程。本模块只复用下层RX、cipher、消费者和统计，不修改这些共享实现。

## USB暂停与续接

`rr_receiver_legacy_business`返回1表示实际消费者到USB驱动边界，pending保存selected_peer、forward_peer、metadata和device。此时统计及+8C清零尚未执行。`rr_receiver_legacy_resume(ram,driver_result,pending)`明确接收外部结果，执行已有消费者后处理，再做统计与选中context尾段。

原指令验证在0E0622BC暂停；续接试验保留实际调用栈，把指定返回值放r0并沿原LR继续，**这不是执行USB驱动，也不是断言驱动成功**。原入口的r0不是恢复API的状态返回；C以0完成/1pending/−1未支持域表示模型控制状态。

## 尚未覆盖

没有扩展本轮到mode1/2 RADIO或TIMER IRQ；静态索引仍作为后续入口。现有RX等价域保留class0..5、bank≤128B、class2/4完成密文8/16B及消费者有效消息范围。对mode2畸形短包导致的拷贝长度下溢返回模型未支持，不能理解为原固件具有这些校验。下游未支持结果可能保留已经发生的序号/motion等前缀修改；不提供事务回滚承诺。USB驱动、硬件时序、射频端到端均未验证。

## 原字节定位

|地址|GNU行|镜像偏移|入口16字节|作用|
|---|---:|---|---|---|
|0x23023968|5452|0x4104|`40f684732de9f04f00fb03f3594f85b0`|mode1 business entry|
|0x23022d90|4355|0x352c|`2de9f04740f6847400fb04f4294f84b0`|mode2 business entry|
|0x230239fe|5501|0x419a|`b8f1010fc0d196f89d30012b04d10022`|mode1 duplicate class1|
|0x23023a26|5515|0x41c2|`6378172b50d02c2b05d1a378f386b4f8`|mode1 class0 opcode17/2C|
|0x23023a54|5532|0x41f0|`b4f8052096f89de0b4f803601f4b76ba`|mode1 motion delta|
|0x23022e26|4405|0x35c2|`1a4600230df1090008f1ff388df80830`|mode2 class1 prepended fragment zero|
|0x230254a0|7993|0x5c3c|`38b5bdf81050dbb20446c9b2c0b2fff7`|RX then forwarded-peer statistics|
|0x23025004|7540|0x57a0|`2de9f04f1578dff8c4918db08df80f30`|RX fragment reassembly|
|0x23024c88|7167|0x5424|`0b78ab2b0ad0ac2b03d0a42b08d00020`|management consumer|
|0x23020250|240|0x9ec|`70b5564b8446b3f802e00c46bef1010f`|final consumer|
|0x2302552c|8051|0x5cc8|`09b3ff291fd010b4114b041d53f82420`|class0 selected-peer statistics|

原入口执行1113696条指令；12个明确外部返回后的续接执行522条指令，单独记账。
