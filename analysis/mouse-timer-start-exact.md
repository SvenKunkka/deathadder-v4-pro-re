# 鼠标 1.20：实际 timer start 与 delta timeout start

本轮新增 `mouse_timer_start.c/.h`，恢复原 `0x0e096a50` 与 `0x0e096474`，复用已验证 `rr_mouse_timer_abort`；没有修改共享 lifecycle / mode4 模块。**4,096 组原 Thumb 执行对照全部通过**，另有 1,024 次连续链表操作及 6 个内存/RTC 合同检查通过。它们分别计数，后两者不是新增原指令数据集。

## 接口和对象

```c
int rr_mouse_timeout_start(uint8_t ram[65536], uint8_t rtc[4096],
                          uint32_t address, uint32_t callback, uint64_t delay);
int rr_mouse_timer_start(uint8_t ram[65536], uint8_t rtc[4096],
                        uint32_t address, uint64_t duration, uint64_t period);
```

返回 0 表示本模型支持域内到达原函数返回；-1 是非法内存/链表，-4 是 RTC 快照 busy。原函数本身为 void；这些值是恢复代码对无法继续执行环境的报告。进入边界前的真实写入不回滚。

低层对象至少 24 字节：next +0、prev +4、callback +8、保留字段 +12、64 位 delta +16。必须传入未链接对象；原低层不负责移除活动对象。高层对象至少 0x38 字节，wait queue +0x18、用户 expiry/stop callback +0x20/+0x24、period +0x28、status +0x30。全局环形 sentinel 位于 0x230014f4，head/tail 为其 +0/+4。

## 与原指令对应的行为

- `0e096474..47e`：delay `UINT64_MAX` 直接返回，不写 callback。否则 `486` 写入对象 +8，然后把 BASEPRI_MAX 设为 0x20。
- `0e096496..4c4` 与 `520..538`：非负 delay 的 delta 为 delay+1，再加 `sign_extend32(elapsed)`；7680 非零则不读 elapsed。负数（除 -1）为绝对编码，delta = `(UINT64_MAX-1) - ticks[25f8] - delay`，按有符号比较小于 1 时钳位为 1。运算遵循 64 位回绕。
- `0e0964c6..500`、`53a..54e`：按有符号 delta 比较插入，先经过的节点差值从目标 delta 扣除；插入节点之前则把节点 delta 减目标 delta。相等时排在现有节点之后。空链/末端通过 sentinel 接入。
- `0e096504..516`、`552..586`：新对象成为 head 且 7680 为零才重装 RTC。wait 为 delta−sign_extend32(elapsed)，钳位到 0..INT32_MAX。退出恢复入口 BASEPRI。
- `0e096a50..ac4`：duration=-1 不做任何 timer 变更。非负 duration 先 max(duration,1)-1；负绝对编码原样透传。真实调用 abort（inactive 返回 -22 是自然结果，原代码忽略），然后保存 period 全 64 位、status 清零，真实注册 `0x0e096951` 并调用低层 start。原 AAPCS 参数为 r0 对象、r2/r3 duration、入口 SP 上 period；r1 为对齐占位。
- `23028b70`：elapsed = low32((RTC_now−baseline[21c0]) >> 5)，随后由调用者符号扩展。这里保留右移、截断和符号扩展顺序。
- `23028b9c`：due=(RTC_now−baseline)+(wait<<5)；due<64 时取32，否则向下32对齐；传入 compare 的绝对 deadline 为 baseline+due。
- `23029adc→230298e4`：合法且可用 RTC channel 为7/13/14/15。清 compare subscription、复制回调描述符、设置分配位、清事件、写低32/高20 compare，写中断使能。channel无效/已占用时内部状态码被上层自然忽略；不伪装成成功硬件触发。

## 验证

`EmulateMouseTimerStart.java` 验证完整原始镜像哈希与 RAM 映射，使用 AdaptedEmulator 原始指令运行到 LR sentinel，不替换目标函数。getBasePriority 从原 setBasePriority 同一 ArmCpuState 读取，初始 0、0x20、0x80 均验证恢复。Ghidra 的 ISB userop 未模拟物理屏障，这是已知环境限制。

每组完整比较 RAM 65,536 字节与 RTC 4,096 字节；高层包含活动 head、middle、tail 与 inactive 对象。覆盖 duration0/1、32边界、32/64位边界、负绝对时限、UINT64_MAX，period 包含完整64位位型。以下为实际记录统计：

```json
{
  "raw_timeout_entries": 2048,
  "timer_start_entries": 2048,
  "active_timer_inputs": 1024,
  "active_timer_restarts": 968,
  "forever_noops": 224,
  "absolute_inputs": 1120,
  "basepri_values": [
    0,
    32,
    128
  ],
  "maximum_steps": 570
}
```

连续组件从独立绝对到期时间模型验证链表所有 next/prev/sentinel、累加 delta、相同时限的稳定顺序：253 relative start、241 absolute start、283 abort、247 forever no-op。6 个合同检查包括 RTC busy 在相对读时与绝对插入后读时的不同已提交状态、暂停链不读取忙 RTC、非法对象/链指针及恰好24字节低层对象。

## 真实边界

本轮闭合实际启动、活动 timer abort/restart 和注册到期处理入口；**没有声称执行到期 IRQ、到期回调或周期到期重入**。同一执行期间 RTC 为稳定输入，没有硬件计时前进、并发 IRQ 或调度切换。C 调用方必须提供原代码要求的串行/中断排除环境。raw start 只接受未链接对象；恶意/损坏环链和任意地址并非原固件有效域，模型提供有界返回而非无限循环。RTC busy 在原码中等待硬件，模型返回 -4，保留此前内存更改。

原图像 SHA-256：`c817c565857059f19092737922aa43c8e1badf0701b675c777a6e721e486af48`。地址切片、字节哈希、当前代码和全部验证产物哈希见 `mouse-timer-start-exact.json`。可复验入口为 `verify_mouse_timer_start.py` 和 `test_mouse_timer_start_integration.py`，均不进行设备 I/O。
