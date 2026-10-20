# 接收器 mode1/2 RADIO IRQ 与业务接线（1.20，冻结）

新增独立 `receiver_legacy_radio.c/.h`，恢复原入口 `0x23023498`（mode1）与 `0x23022A50`（mode2），连接已有握手、六类发送队列、RTOS 通知和业务模块。没有改动共享模块，也没有操作设备。

原指令差分 **2,688 组全部通过**：1,536 组正常/失败与事件门控、512 组握手、256 组协商模式应用与连接通知、384 组同一 RAM/MMIO 状态的原 IRQ→原 SWI。2,676 组完整返回，12 组停在真实 USB 驱动入口；这12组另有显式外部返回值续接验证全部通过。总计576,920步原指令和729步 USB 续接；真实执行350次 message_put 和50次 purge。

验证覆盖131,072B RAM、4KiB RADIO、2KiB TIMER、2KiB auxiliary、NVIC 最后写值和实际请求掩码、CPU BASEPRI。IRQ→SWI 的第二入口由测试显式调用，未声称实现硬件 NVIC 自动调度。

## 两模式不可混用的规则

| 项目 | mode1 `23023498` | mode2 `23022A50` |
|---|---|---|
| 业务 peer | `u16[23006274]` | `u16[230032D0]` |
| 数据触发 | `END == 1` | `DISABLED == 1` |
| END 非1值 | 保留 | 非0均清零 |
| ADDRESS | 等于1则清零 | 保留 |
| 数据有效条件 | CRCOK等于1，DMA首字节非0 | 仅CRCOK等于1；首字节0仍复制/确认/请求SWI |
| 长度与校验 | 不递减、不算mode4额外checksum | 同左 |
| 失败 | 清DMA首字节；设置+A2或调用peer0失败计数 | state12→11；失败不清DMA首字节 |
| 接收头低4位 | 写选中context+90+2channel及全局5380+2channel | 不写 |
| CRC清理 | 仅实际处理DISABLED后 | 实际处理DISABLED后的共同尾段 |

特别保留 `23023516` 的副作用：mode1 state13 收到END时调用DISABLE辅助函数，清READY、END、DISABLED并写DISABLE任务；因此同次调用原先已置位的DISABLED不会再进入后面的处理，也不会顺带清CRC。不能把CRC清理提到统一返回处。

## 确认、队列和失败候选

成功接收将 DMA `23003050` 的16B复制到 `33E8 + peer*F84 +114`，清DMA首字节，置context+9F。头bit7同时存+9C/+9D；确认序号取`(header&7F)>>4`。新序号清+88和所选channel失败计数；仅当`u16 context+96 != 0`时弹出队列，推进+9A（uint8加1，结果8改为1），保存队列号到+98。随后所有成功接收都写新+9B、清队列号为0、请求SWI4。

这里**队列号0是确认路径的特殊值**，不是mode4的255，也不是业务class0。源码按原条件`q!=0`恢复，q0..5是模型有效输入域；没有把人为边界检查描述成原固件保护。

SWI请求源 `23021C24` 保存peer到`230071A4`，实际写`E000E208=10000000`。`nvic_requests`只记录本次执行的写动作；旧last值恰好等于已知掩码不算新请求。

mode1失败辅助`23023708(1)`固定访问peer0：受348A门控，连接态3按interval/事件计数筛选，连接态4按`5376&1D`筛选；递增3478+2channel，超过3才换候选并清计数。DISABLED/state13路径使用选中peer计数且阈值为超过2。两路径均在5384非0时抑制候选推进，候选达到5353时归零；未将这些推断为已验证真实无线跳频时刻。

## 握手、模式应用与通知

mode2 state8→7。state9 CRC通过时调用原`230223F0`对应已有握手模型：返回0/1→7，返回2→DISABLE/state10。终态配对有context+14时构造type5消息，接入真实RTOS消息队列；成功后清+14/+1A，两peer待配对标志都为0才清RXADDRESSES bit0，最后设置握手state6、timeout0。

state10清RADIO订阅，DISABLE/state0，然后执行`23021DBC`的模式应用：3234取3236；模式1/2/4分别配置PCNF、SHORTS、中断、MODE及TIMER，其他值保留原早退行为，之后仍发送连接type1通知。模式1/4重写PCNF；模式2保留PCNF；mode4不写CC3；mode1按interval1选择slot4，否则slot3，mode4选slot5。身份字段按原16bit字节序写消息。

通知链实际使用队列`23001B8C`，36B×5记录，ring `23015760..23015814`；真实`0E06CBDC`排队失败后调用真实`0E06CD54`清队列再重试。没有替换为成功返回。测试覆盖环尾回绕与满队列重试。

原type5消息尾20B、type1尾24B及连接pair内部2B未被函数初始化。测试在原message_put入口捕获这些旧栈字节，作为明确的环境输入交给C；定义字段仍由C独立重建。它们不是空中协议字段，也没有用全零掩盖来源。

## 业务接线和真实边界

`rr_receiver_legacy_radio_swi`从71A4取得实际请求peer，调用已有 `receiver_legacy_business`。384组同状态原指令串接覆盖业务class0..5及不同peer。12组触发USB恢复：停止于真实`0E0622BC`、核对device指针，再分别给出外部返回值执行原保存调用栈的尾段，验证延迟统计及状态清理。驱动本体没有执行。

RTOS接口复用 `receiver_rtos_lifecycle`；遇到其真实timeout/scheduler边界时返回pending及CPU入口/参数，保留已发生副作用。此模块没有为这种CPU边界实现自动续接，**重进IRQ不是resume**。本次IRQ通知输入覆盖无等待线程的ring及purge；活动等待线程的计时取消属于父任务RTOS验证范围，未被这组IRQ样本代替验证。

## 可复验产物与限制

- 源码：`recovered-code/portable/receiver_legacy_radio.c/.h`
- 原指令脚本：`ghidra-scripts/EmulateReceiverLegacyRadio.java`
- 差分：`analysis/verify_receiver_legacy_radio.py`
- 样本和结果：`receiver-legacy-radio-original.jsonl`、`receiver-legacy-radio-comparison.json`
- 逐入口原字节/地址/来源SHA：`receiver-legacy-radio-exact.json`

固件SHA256：`f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162`。AdaptedEmulator执行原Thumb字节，未改指令或替换目标函数。CPU getBasePriority桥接到同一ArmCpuState，getCurrentExceptionNumber是显式中断环境输入；Ghidra屏障警告意味着未验证真实多核/总线屏障语义。

仍不包含mode1/2完整TIMER调度、无线时序、DPPI自动事件、IRQ抢占、并发队列生产者、无效peer/队列/溢出输入，以及USB驱动本体。该交付是可执行且有原指令证据的RADIO入口恢复，不是完整可烧录固件或实机RF验证。
