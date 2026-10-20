# 鼠标 1.20：配对身份分支与 state 0x16

已补入 `recovered-code/portable/mouse_handshake.c/.h` 和 `mouse_handshake_transition.py`。本轮只涉及 `230227B8` 内的配对身份处理及 state 0x16 发送完成；state 0x17 的终态初始化仍未实现，完整无线代码目标未缩小。

## 精确恢复

phase 0 收到合法 0x11 包时，先更新 23002846（packet[8:10] 小端）、23002A09（packet[8] bit7）、23002992（packet[8] bit6）。能力低四位交集为零则走原有 reset。否则检查 u32[2300298C]：为零跳过身份更新；非零时比较**更新上半字后的完整 u32[23002990] 是否恰等于 0x00010000**。相等则 reset，保留此前三处字段更新，不更新身份。其它值把 packet[4:8] 按大端解释为 u32 写入 230027B0（原指令 23022938 为 REV）。这里不清 pairing flag，也没有持久化操作。

state 0x16 只响应 event 5，不检查 CRCOK：清 RADIO SUBSCRIBE_TXEN；调用 23021B90 将 state 设为 0x14，清 READY(5302C200)、END(5302C218)、DISABLED(5302C220)，向 TASKS_RXEN(5302C004) 写 1；再写 u32[23002A4E]=0x50001。phase、23002A52、packet、身份和 TIMER SUBSCRIBE_CLEAR 保持原值。其它 event 无改动。

## 接口兼容

保留 `rr_mouse_handshake_rx` 的 15-word、零初始寄存器投影，不破坏旧调用方。新增 `rr_mouse_handshake_step` 的 19-word **in/out** 接口，末四项依次 READY、END、DISABLED、RXEN；未触及项保留调用方初始值。完整 state 0x16 副作用应使用新接口。Python 对应 `extended_registers=True, initial_registers=...`。

## 原指令验证

`EmulateMouseHandshakeExtended.java` 使用现代 `AdaptedEmulator`，执行前比对原 flash SHA-256 和 RAM 拷贝的全部字节，不替换目标函数或其辅助函数。所有外设地址均为无副作用的模拟内存。新输出 `mouse-handshake-extended-original.jsonl` 共 384 组，包含随机非零的 19 个寄存器初始值。旧 256 组及旧验证结果文件未覆盖。

独立 `verify_mouse_handshake_extended.py` 编译 C（C11，Wall/Wextra/Werror/pedantic），把 C 和 Python 分别与原 Thumb 输出比较：640 组全部通过，每组比较完整 992 字节 RAM 窗口，旧组 15 个寄存器，新组 19 个寄存器。新组覆盖身份更新 120 次、精确 0x10000 拒绝 24 次、state 0x16 + event5 转回 0x14 共 96 次、state0x16 其它 event 保持 32 次；另含 CRC/header/长度/类型/能力不匹配。

证据范围、原始字节、区间哈希见 `mouse-handshake-extended-evidence.json`；全部输入及代码哈希、覆盖计数见 `mouse-handshake-extended-comparison.json`。复验入口为本目录 `verify_mouse_handshake_extended.py`。结果证明已覆盖局部软件分支的差分一致，不证明 RF 时序、外设自主状态变化或实机行为。
