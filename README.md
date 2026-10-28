<!-- SVENKUNKKA-README-NAV:BEGIN -->
[English overview](#project-overview-en) · [中文项目说明](#project-overview-zh) · [Maintainer on X / 维护者 X](https://x.com/Svenu1s5)
<!-- SVENKUNKKA-README-NAV:END -->

# DeathAdder V4 Pro — firmware reconstruction

Razer DeathAdder V4 Pro 官方 **1.20** 固件的部分行为复刻、反编译导出与验证工具。包含鼠标端及配套接收器端。此仓库是研究快照，**不是原厂源码，也不是可直接刷入设备的完整固件**。

Reverse-engineering research snapshot of the mouse and receiver firmware. The portable library reconstructs bounded firmware behavior; it is not a complete, flashable replacement or an independently validated RF implementation.

研究于 2026-10-20 按要求停止；本次发布只整理已有成果。

## 内容

| 路径 | 内容 |
|---|---|
| [`recovered-code/portable/`](recovered-code/portable/) | 69 个可编译 C11 单元及头文件：握手、队列、收发处理、时隙、定时器、工作线程、存储与部分初始化 |
| [`recovered-code/cortex-m/`](recovered-code/cortex-m/) | 鼠标及接收器所选上下文切换汇编、链接脚本与构建文件 |
| [`recovered-code/`](recovered-code/) | 两端合并的反编译 C 及入口索引；反编译输出不作为可直接编译工程 |
| [`analysis/`](analysis/) | 各阶段反编译导出、行为模型、测试/验证脚本、紧凑结果与证据报告 |
| [`ghidra-scripts/`](ghidra-scripts/) | Ghidra 导出及原始 Thumb 指令执行工具 |
| 根目录 Python 脚本 | 静态提取、来源核验、寄存器映射及有线版本查询工具 |
| [`publication-manifest.json`](publication-manifest.json) | 发布文件清单、原文件与公开副本 SHA-256、路径规范化记录 |

完整复制了上述目录中已有的恢复代码、分析代码、验证代码和历史源码快照。原厂更新器/固件二进制、第三方参考下载、Ghidra 数据库、构建产物、设备枚举记录、运行日志和约 5.5 GB 原始测试 JSONL 未随源码发布。

## 构建与可直接运行的检查

要求主机安装 Clang、Make、ar 和 Python 3。在仓库根目录执行：

```sh
make
make check
```

输出为 `recovered-code/portable/build/librr_recovered.a`。`make check` 编译全部 69 个 C 单元，并运行不依赖固件文件的握手字节契约测试。它不连接设备。

其余原指令差分测试需要自行准备对应官方镜像、Ghidra 项目及原始数据集；公开仓库没有这些输入，不能直接重放全部历史验证。部分历史运行脚本保留 macOS/Homebrew 工具位置，需要按环境配置。历史文档中的 `rtk proxy` 是本地命令包装器，不是源码构建依赖。

## 验证状态

- 发布前历史记录：69 个 C 单元、90 份数据集、219,264 组原指令输入差分；见[阶段 66 完整性记录](analysis/phase-mouse-wireless-startup-integrity.json)。这些记录包含完整返回与明确停止在未恢复入口的案例，不表示全部固件已执行完毕。
- Frame Sync 专项另有 **464 组、35,071 步**定时原指令对照，全部通过；见[专项结果](analysis/frame-sync/timing-comparison.json)。未并入上述 90 份数据集统计。
- 历史报告引用的是本地原始快照。少数脚本/文档的个人目录已替换，因此其公开副本哈希可能不同；发布清单保留前后哈希。**69 个 portable C 单元及所有同目录头文件均保持原字节。**
- 未完成完整启动、真实异常返回/线程续跑、传感器内部成帧和端到端无线/USB 实机验证。当前成果只能支持各模块声明的输入域与边界。

## Frame Sync 当前结论

已追踪到 USB SOF 软件回调校正接收器无线定时器、鼠标依据无线包 ADDRESS 事件捕获值校正自身周期，以及无线周期启动 TIMER134 并调度传感器读取。读取、报告入队、无线发送及 USB IN 完成属于不同阶段。

仍未证明传感器内部曝光/成帧如何与这些阶段锁定。`0x16` burst 和 SPI END 只证明读取与总线传输完成；Timer132 的 GPIO 路径关联按键采样。旧代码 `mouse_mode4_radio.c` 中 `spim`/`s` 所指 `0x5F9C2000` 实为 **TIMER134**，该历史参数名保留以维持来源绑定。

入口：[传感器侧](analysis/frame-sync-sensor-map.md) · [USB 侧](analysis/frame-sync-usb-map.md) · [无线至读取调度证据](analysis/frame-sync/radio-sampling-map.json) · [当前状态](STATUS.md)

## 镜像身份

分析对象是官方升级包提取的镜像，不是实机完整 dump。

| 镜像 | SHA-256 |
|---|---|
| 鼠标 `Suit2FWData__radio_radio.bin` | `c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48` |
| 接收器 `Suit1FWData__radio_radio.bin` | `f7a9bd6f51490bcceeaf0121775e2da3ef701a7a3218862956fb60dde2c52162` |

本项目与 Razer 无隶属关系。名称和商标归各自权利人；保留文件中已有的来源与版权声明。


---

<!-- SVENKUNKKA-PROJECT-INFO:BEGIN -->

<a id="project-overview-zh"></a>
## 中文项目说明

Razer DeathAdder V4 Pro 1.20 鼠标及接收器固件的逆向研究快照，包含部分行为重建、可移植 C 代码、反编译导出、分析工具与限定范围的历史验证记录。

**使用入口：** 主机准备 Clang、Make、ar 与 Python 3 后运行 `make`、`make check`；当前状态和证据入口见 README 与 [STATUS.md](STATUS.md)。

**范围说明：** 不是原厂源码或可直接刷写的完整固件。原始镜像和大型数据集未发布，无法直接重放全部历史验证；完整启动、传感器成帧及端到端无线/USB 实机验证仍未完成。

<a id="project-overview-en"></a>
## English project overview

A reverse-engineering snapshot of Razer DeathAdder V4 Pro 1.20 mouse and receiver firmware, with partial behavior reconstruction, portable C, decompilation exports, analysis tools and bounded historical validation records.

**Getting started:** With Clang, Make, ar and Python 3 available, run `make` and `make check`. See the README and [STATUS.md](STATUS.md) for status and evidence entry points.

**Scope:** This is neither original vendor source nor a complete flashable replacement. Original images and large datasets are excluded, preventing direct replay of all historical validation. Full startup, sensor framing and end-to-end wireless/USB hardware verification remain incomplete.

**仓库维护者 / Repository maintainer:** [SvenKunkka](https://github.com/SvenKunkka) · [X / Twitter](https://x.com/Svenu1s5)

<!-- SVENKUNKKA-PROJECT-INFO:END -->
