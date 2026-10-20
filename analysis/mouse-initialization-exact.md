# 鼠标无线初始化及应用包装恢复（1.20，phase65）

已恢复官方鼠标无线镜像中的完整 `23022E28` 初始化、`230259A4` 应用包装，以及 RADIO、DPPI、状态清理、发送队列初始化辅助入口。新增3,840组原指令输入，43,086,518条实际指令，全部返回且与C的最终内存状态一致。

这补上了原先“密钥安装已恢复，但完整调用方未恢复”的缺口。身份、配置和工作线程的更上游来源尚未全部接通，不能把本阶段称为整机上电或完整2.4GHz固件恢复。

## 实现

[mouse_initialization.c](../recovered-code/portable/mouse_initialization.c) 与 [接口](../recovered-code/portable/mouse_initialization.h) 新增六个入口，既有模块保持原样。

|入口|行为|
|---|---|
|rr_mouse_radio_queue_initialize / 21528|按原布局建立6类发送队列元数据、容量和缓冲指针|
|rr_mouse_radio_reset / 225CC|依次清零2978..3858、2794..2978、2688..2794，填充16字节FF，再初始化peer0队列|
|rr_mouse_radio_dppi / 21800|登记7个通道编号，发布6个TIMER比较事件和RADIO ADDRESS事件|
|rr_mouse_radio_initialize / 218EC|地址、前缀、包格式、CRC、SHORTS、INTEN与RADIO IRQ配置；独立入口保留PHY参数|
|rr_mouse_initialize / 22E28|状态清理、通道连接、身份和字段打包、PHY固定4、有效rate配置、定时器及IRQ配置|
|rr_mouse_application_initialize / 259A4|构造capability7配置，执行完整初始化，再从原表安装16字节key，保存应用元数据|

输入的三个配置字段及capability按原指令截为16位。297E的未对齐32位写入由两个16位字段分别交换字节后拼接。rate只在1..64时生效；清理范围不包含76EE，所以进入/退出rate1的时钟请求必须保留原标志条件。这里的rate数字不被直接解释为实测Hz。

PHY固定4有明确栈写入依据：22E28把4写入localSP+24，再把localSP+4传给RADIO配置，后者读取参数+20。没有把旧栈字节补成4。原始字节、全部寄存器写入和调用树见 [静态证据](mouse-initialization-map.md) 与 [结构化证据](mouse-initialization-map.json)。

## 原指令验证

[差分结果](mouse-initialization-comparison.json) 比较全128KiB RAM、5个4KiB外设窗口及BASEPRI。完整初始化/应用包装/RADIO独立入口各1,024组，三个辅助入口各256组；共3,840组全部完整返回，没有用成功桩替代被调函数。

覆盖全部16个key表索引、独立RADIO入口全部256个PHY字节值、rate边界0/1/2/4/8/16/32/64/65/FFFF、参数高16位截断及76EE四种初态。孤立队列初始化的索引0..31仅是地址有界的参数测试，不证明产品支持31个peer；256种PHY参数也不代表硬件均支持。

[原始执行记录](mouse-initialization-original.jsonl) 与 [本轮来源绑定](mouse-initialization-exact.json) 保留固件和工具输入哈希；[完整性结果](phase-mouse-initialization-integrity.json) 核对本轮与历史记录。

## 两端初始化后的业务组件

[组件测试](mouse-initialization-exchange-comparison.json) 先执行鼠标完整应用初始化，以及接收器事件1完整初始化和key安装，再运行既有业务发送、分片、接收、去重和消费者：832次初始化、416条消息、1,536片段、928次重复包检查、16个B1请求回复，全部通过。

没有另行调用队列初始化或直接补装key来代替本阶段初始化。初始化后连接状态、数据缓冲交接和工作消费者执行由测试环境明确提供；因此它证明初始化产物可供后续软件使用，不证明握手自动完成、真实调度、空口传输或USB主机接收。组件数不加入原指令输入累计数。

## 未完成部分

上游已定位 `2869C → 21150 → 25D1C/等待 → 259A4`。首次调用会创建线程、初始化工作项并进入真实PendSV等待路径；不能省略等待后直接宣称完成启动。持久配置A001/A003的身份/速率来源、模式切换、真实CPU续跑和其余厂商命令仍待恢复。

本阶段比较最终内存效果，不比较IRQ配置的瞬态写入顺序；所有外设窗口均为静态输入输出，不模拟SET/CLR硬件联动、并发、物理时钟或RF时序。没有设备写入，没有接收器实机验证，完整目标保持未完成。
