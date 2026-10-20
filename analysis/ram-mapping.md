# Radio 核启动 RAM 拷贝映射

核验日期：2026-10-19。只读本地官方镜像；没有执行目标代码、修改 Ghidra 项目或写设备。原始逐条汇编、常量地址、文件 SHA 和分段 SHA 见 `ram-mapping.json`。

## 已验证的参数顺序

四个镜像的复制函数具有相同机器码：`add r2,r1` 计算源结束地址，`subs r3,r0,#1` 初始化目标指针，循环 `ldrb.w r4,[r1],#1` 读取源、`strb.w r4,[r3,#1]!` 写目标。因此 `r0=destination, r1=source, r2=byte_count`。验证了启动函数的两条 BL 到 thunk，再由 thunk 无参数交换跳转至该字节循环；第三次是 tail-call，同样设置 r2/r1/r0。反编译显示的额外 in_r3 不是第四个复制参数。

## 拷贝表

以下区间均为 `[start,end)`；非零源区间全部位于对应镜像内。第二次拷贝 size=0，不创建有效 RAM 内容。

|版本|设备|类别|LMA|VMA|长度|源文件偏移|
|---|---|---|---|---|---|---|
|1.21|mouse|initialized_data|0xe09b9c8–0xe09d274|0x23000000–0x230018ac|0x18ac (6316)|0x2f9c8|
|1.21|mouse|zero_length_copy|0xe09b9c8–0xe09b9c8|0x23000000–0x23000000|0x0 (0)|0x2f9c8|
|1.21|mouse|ram_code|0xe06c79c–0xe079034|0x23020000–0x2302c898|0xc898 (51352)|0x79c|
|1.21|dongle|initialized_data|0xe070904–0xe072748|0x23000000–0x23001e44|0x1e44 (7748)|0x1c904|
|1.21|dongle|zero_length_copy|0xe070904–0xe070904|0x23000000–0x23000000|0x0 (0)|0x1c904|
|1.21|dongle|ram_code|0xe05479c–0xe05bbd4|0x23020000–0x23027438|0x7438 (29752)|0x79c|
|1.20|mouse|initialized_data|0xe09b888–0xe09d100|0x23000000–0x23001878|0x1878 (6264)|0x2f888|
|1.20|mouse|zero_length_copy|0xe09b888–0xe09b888|0x23000000–0x23000000|0x0 (0)|0x2f888|
|1.20|mouse|ram_code|0xe06c79c–0xe078e4c|0x23020000–0x2302c6b0|0xc6b0 (50864)|0x79c|
|1.20|dongle|initialized_data|0xe070854–0xe07265c|0x23000000–0x23001e08|0x1e08 (7688)|0x1c854|
|1.20|dongle|zero_length_copy|0xe070854–0xe070854|0x23000000–0x23000000|0x0 (0)|0x1c854|
|1.20|dongle|ram_code|0xe05479c–0xe05ba0c|0x23020000–0x23027270|0x7270 (29296)|0x79c|

## 验证地址

|版本|设备|启动函数|第三复制入口|memcpy thunk|实际字节循环|
|---|---|---|---|---|---|
|1.21|mouse|0xe09652c|0xe096e28|0xe094804|0xe0974c4|
|1.21|dongle|0xe06e674|0xe06ef28|0xe06c8f0|0xe06f3f8|
|1.20|mouse|0xe096404|0xe096d00|0xe0946dc|0xe09739c|
|1.20|dongle|0xe06e5d8|0xe06ee8c|0xe06c854|0xe06f35c|

## 地址换算与限制

若静态调用目标在 `ram_code` 的 VMA 区间，取清除 Thumb bit 后的地址 `v`，对应文件偏移为 `source_file_offset + (v - vma_start)`，对应原始 LMA 为 `lma_start + (v - vma_start)`。应该将该区域作为 initialized RAM 以 VMA 解析，以保留绝对跳转/全局引用的意义；仅从 LMA 反汇编并不等价。

这证明启动拷贝意图和可恢复的初始化字节，不证明某次实机已执行该路径。未将 BSS、栈或运行后可变内容当作固件初值。版本 1.20 与 1.21 的拷贝长度不同，不能混用镜像或将 1.21 RAM 内容贴入 1.20 项目。
