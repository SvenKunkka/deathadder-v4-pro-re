# 鼠标 1.20 mode4 RADIO / 定时槽恢复

## 交付与验证结论

独立可编译模块 `recovered-code/portable/mouse_mode4_radio.c/.h` 已冻结；没有设备操作。恢复的是下面明确列出的软件域，未完成完整 mode4 发送选择、非空 ACK 回调及所有生命周期。直接执行原始 Thumb 与 C 对照 **3,072 / 3,072 PASS**，另 8 个边界预检保持所有输入不变。连续组件验证 **8 场景 / 256 周期 PASS**，不加入原指令案例计数。

| 原入口 | C 入口 | 验证域 |
|---|---|---|
| `23024650`，由 RADIO ISR `23021704` 的 mode4 分支进入 | `rr_mouse_mode4_radio` | 事件清除、TX 完成、正常 RX 成功/失败、队列释放与 SWI 请求；非空 class3 ACK 回调除外 |
| `23024918` | `rr_mouse_mode4_action` | 忙态动作、停止 TX、RX 启动和长度异常后的 DISABLE；idle/action3 选包除外 |
| `2302516c`，由 TIMER ISR `2302243c` 的 mode4 分支进入 | `rr_mouse_mode4_timer` | 首个比较事件、正常槽寄存器安排、时钟样本/修正、统计维护及有限 slot5 周期维护；边界见下文 |

函数以调用者提供的 RAM 与 MMIO 快照运行。RAM 为 `23000000..2300ffff`，RADIO 为 `5302c000` 的 4096 字节，TIMER 为 `53028000` 的 1536 字节，辅助 SPIM 映射为 `5f9c2000` 的 16 字节。寄存器写入没有自动触发射频、DPPI、时钟或中断。

## 精确 IRQ 状态与业务交接

`TXREADY(204)`、`RXREADY(208)`、`ADDRESS(20c)`、`END(218)` 仅值为 1 时清除。END 先于 DISABLED：若状态 `2a04=19`，END 将其改为 `18`；同一次 DISABLED 因而不会再走旧 TX 状态的收尾。这一先后顺序已包含于原指令对照。

DISABLED 不等于 1 时立即返回。DISABLED=1、状态 `1a` 时取消 RXEN/DISABLE 订阅并清 SHORTS bit19；CRCOK=1 是成功分支。成功时 `2630` 的 16 字节 DMA 包复制到 `2a96`，仅清源首字节；循环序号 `2a1e` 增一，恰为 8 时回到 1。清 `2a14+2*bank`、无响应计数 `2a0c`、24 字节缓存 `2670`、`2a26/27c7`，置 `2a22=1`。队列号 `2a1a<6` 调用实际恢复的 `rr_bt_pop`；class3 的非空 `6b68` ACK 回调为显式边界，不伪造成功。

成功时 `29c4|29cc=0` 才采集时钟：slot2 保存 CC7，slot5 保存 CC7−250。包 `2633=1f` 时读取 `2634..2635` 大端计数：CC7 无符号范围 166..249 原值写 `2a0a`，416..499 写原值+1，其他时刻保持。成功先写 NVIC `10000000` 请求业务 SWI，再调用实际 `rr_mouse_adaptive_request(phase=1,channel,reason)` 写 `08000000`。真实 NVIC 是 W1S，两次请求均存在；本模块的 nvic 输出只保留最后一次写入，不能据此声称只触发 adaptive。

失败时递增该信道累计失败 `289e+2*channel`、连续失败 `28e8+2*channel`、全局失败 `293a`，置 `29d0=2`，请求 adaptive phase0/reason255。成功/失败均递增 `2854+2*channel`、`2932`、`2938`，清 SHORTS bit4，状态回到 `18`；DISABLED 尾部清 CRCOK/CRCERROR。

业务 SWI 与 adaptive SWI 分别服务，消费者继续延期。256 个原指令用例明确连续执行 `23024650→23022508→23022f70`，包括真实重组和 work.flags 自然 fast-return。没有用空函数替代 RTOS 排队；work.flags=0 域仍由既有业务模块拒绝。

## 动作与定时槽

动作6 在 idle 状态且 `2a20=1` 时安装 DISABLE 订阅（`80000000|76f4`）、SHORTS bit19，清 availability，状态变 `1a`，PACKETPTR 指向 `23002630`；RSSI 采样开关非零时增加 SHORTS bit4。未满足 availability 时执行实际 DISABLE 请求并保持原状态。RX 动作8 使用 PACKETPTR 首字节，原无符号 `(length-1)>9` 判断拒绝 0 或大于 10 的长度；清 READY/END/DISABLED 并请求 DISABLE。TX 动作1 取消 TXEN/START 订阅。

TIMER 仅处理 COMPARE0..7 中第一个值为 1 的事件。CC0 设置周期值 500，并依速率/状态选择 CC1/CC2/CC4。CC1 使用比较值 75/140/220/325/390/470 切换 slot1/2/3/4/5/0；TX 槽 action3 在已经忙的状态自然返回，真正 idle TX 选包未恢复。CC2 链接后续槽，slot5 结束更新周期/无响应/活跃计数，bank 使用 `(event>>1)&2`，是 0/2 索引。支持 selector0/1 的既有频表取值；selector>=4 的原回退值为 2402，不能擅自把所有选择器值重新解释为统一 MHz 偏移。

CC0 的真实软件维护包括时钟样本累计、4 样本基准、偏差大于 1 时设置校正及 4 周期冷却；slot5 校正值 1/2 分别使下一 CC0 为 503/497。每 512 周期清信道统计，每 2048 周期按失败数与总数右移 3 的比较调整 0..60 等级，并由等级>14 设置标志。已恢复的同步频表复制不包含 selector2/3 重新计算。SPIM 启动只记录原来的寄存器写入，没有模拟实际总线。

## 原指令证据与连续组件

`EmulateMouseMode4.java` 在 1.20 原程序 RAM 映射上执行未改写目标指令：1536 个 RADIO、1024 个 TIMER、256 个动作、256 个 IRQ/业务/adaptive 链。逐案例比较全部 65536 RAM、4096 RADIO、1536 TIMER、16 SPIM 字节以及最后 NVIC 写值。仅 256 个业务交接用例需要 CPU BASEPRI getter bridge；这是 CPU 状态操作适配，不是目标函数桩。ISB 等架构同步操作在惯性模拟器中不代表真实硬件时序。

`test_mouse_mode4_integration.py` 是独立 C 组件测试：4 种接收器信道选择模式 × 2 种鼠标初始 bank × 32 周期。实际使用接收器 class3 入队与定时选包生成 256 个下行包，复制 DMA 后显式输入 CRC/硬件事件。得到 3072 次接收器定时事件、256 次接收器扫描 IRQ、512 次鼠标定时事件、336 次成功 RX、64 次 CRC 失败、256 次新业务完成、80 次重复拒绝和 400 次 adaptive 服务。接收器上行 ACK 是显式环境输入，**不是未恢复的鼠标 TX 生成结果**；没有完整双向空口模拟声明。消费者未自动执行，work.flags=4 自然 fast-return 保持延期语义。

## 明确未完成范围

- idle/action3 的发送选择、编码及其调用链（包括静态已知 `23024baa` 附近）未接入；不以忙态 no-op 冒充完成。
- class3 非零 ACK 回调 `6b68` 未接入 mode4；已有其它模块的恢复不能自动算作本模块闭合。
- slot5 无响应增至 100 的断开、待应用速率 `29ae`、selector2/3 的频表重算未接入。
- 不模拟异步中断竞争、真实 RTOS 排队/线程执行、DMA 并发、NVIC 调度、PHY/DPPI、频率误差与实机射频行为。
- 所有负返回是宿主分析边界，不是固件错误码；预检在修改快照之前返回。8 项边界覆盖 callback、bank、channel、idle TX、无效 PACKETPTR、断开阈值、待速率、selector2/3。

本轮仅新增独立模块与证据。完整功能目标仍需以上未恢复部分，当前 PASS 仅适用于明确列出的案例与输入域。
