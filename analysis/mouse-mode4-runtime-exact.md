# 鼠标 1.20 mode4：速率、37频点计划、ACK与超时尾段

## 已交付与验收

新增 `mouse_mode4_lifecycle.c/.h`，扩展 `mouse_mode4_radio.c/.h`，调用既有 `mouse_timer_lifecycle` 的真实 ACK 生命周期。新增 **2560 组原指令对照全部一致**，其中 **2048 完整返回，512 停在原程序真实 RTOS 入口**。停止在边界不算成功完成断开尾段。

| 原执行范围 | 数量 | 实际结果 |
|---|---:|---|
| TIMER `2302516c`，速率/频表/跳频 |1536|完整返回|
| mode4 RADIO `23024650`，含 ACK 生命周期 |512|完整返回；472非空已知回调，393活动ACK定时器、235活动链路定时器|
| 超时→work-submit `0e0952ec` |128|停在真实入口，未伪造返回|
| 超时→work自然fast-return→timer-start `0e096a50` |384|停在真实入口，未执行定时器启动|

旧 3072 原指令/8边界与 TX 4352 原指令/6布局边界回归全部通过。另新增4项宿主边界合同测试与8场景/256周期双向组件测试，通过256次 pending-rate应用、256次信道计划提交、256次 selector2/3 跳频、192次ACK出队、64次失败保留及56次下一周期真实重发。组件与宿主边界不增加原指令数量。

## 接口与兼容合同

`rr_mouse_mode4_timer_lifecycle(ram,radio,timer,spim,image,clock,nvic,pending)` 提供扩展 TIMER 路径；image 必须是本任务确证 SHA256 的鼠标1.20无线核心镜像，基址 `0e06c000`，提供固定表数据。返回0代表已实现的软件路径完成；返回1代表 pending 指明的真实RTOS入口；负值仍是明确宿主分析边界，不是固件返回码。

`rr_mouse_mode4_radio_lifecycle(ram,radio,timer,rtc,clock,nvic)` 接入已知 class3 ACK回调。底层公开 `rr_mouse_mode4_radio_with_ack` 和 `rr_mouse_mode4_timer_with_runtime` 的回调接口，允许复用精确原调用位置。旧 API 的 callback/rate/plan/timeout边界保留，上一阶段 `*_full` 继续只扩展TX；不能把所有旧入口视为自动获得新生命周期。

RAM与MMIO窗口保持已有布局。新增 clock 为 `5302e040` 的2个uint32，RTC为 `5f99c000` 的4096字节。没有时钟推进、设备I/O、自动中断调度或PHY/DPPI副作用。

## pending rate：原指令顺序

slot5结束先递增周期、无响应和数据间隔，更新bank及频率，并处理RSSI周期事件；随后 `29ae!=0` 才复制到 `29ac` 并清 pending。`230217a4(0,new_rate,1)`：新值为1且 `76ee=0` 时写 clock[0]=1并置76ee；其它新值在76ee非零时写 clock[1]=1并清76ee。

随后 `23021744` 重算 `29f9`。mode4/8只在新值为4或>7时使能；函数其它mode分支还接受1/2。最后 `2302223c(0)` 清 `29e2`、`29e8`与`29e4`。这些发生在时钟校正和失联阈值判断之前；即使本周期随后超时，已经应用的新速率与clock写仍保留。

## selector2/3 计划构造与选择

同步提交条件保持 `27c5!=0 && 2972==2a0a`。`2302227c` 将待提交5字节 `26be..26c2` 复制到 `26b9..26bd`，selector2/3额外调用 `23021d6c`：

- 逐位枚举0..36；有效位写紧凑列表 `26ed+n=channel`、排名表 `26c8+n=n`；37项直接映射 `2712+i` 写 channel或FF。
- `2737` 存有效数。没有清理列表以外的旧尾部；空mask保留原程序会访问的旧表内容，不能声称空mask已经得到有效RF计划。
- `26c6=low16(RADIO.BASE1) XOR high16(RADIO.BASE1)`，BASE1为RADIO偏移e30。
- 随后清信道统计，与既有512/2048周期维护顺序一致。

`2302218c` 对selector2/3调用 `23021de0(counter)`，counter是本周期已经递增后的 `2a0a`。设 seed=26c6，P 为原镜像 `0e098a04` 的16项 nibble置换：

```
v=P(counter XOR seed)
v=P((seed+17*v)&FFFF)
v=P((seed+17*v)&FFFF)
x=seed XOR ((seed+17*v)&FFFF)
channel=direct[x % 37]
若channel==FF：channel=compact[rank[(x*count)>>16]]
```

函数同时保存 counter→26c4、channel→26c3/2792；从原镜像 `0e098a14+channel` 读取频率值写2790。P实际按原指令重排四个nibble；代码从镜像读取原16字节表。selector0/1保留原bank表选择，其他selector的回退值2402也保持。这里不将软件计划或频率寄存器值等同于已实测空口跳频。

## ACK：在真实出队位置执行生命周期

正常RX成功先完成原来的缓存/序号清理和队列pop，再于 `qid>1` 的原调用位置进入ACK helper。class3且 `6b68=23025c2d` 时，调用真实恢复的 `23025c2c`：停止15b0定时器，按6b7b进入 `23022d88`，包括活动双链表摘除、delta继承、头节点RTC compare重装及无线清理。回调完整返回才清6b68。

回调返回后原mode4 IRQ继续业务/adaptive请求和尾部状态更新；不能在回调把状态清零后提前结束整个IRQ。512个原IRQ用例比较了这一后续阶段。已有timer模块未被修改。

未知非零回调、真实timer stop callback、等待线程和忙RTC保持边界。四项宿主测试确认：错误返回保留已经发生的序号递增/队列pop，不清未完成的callback；若真实timer abort已摘除节点也不回滚。它们只验证恢复接口的边界合同，不是执行未知回调或scheduler的证据。

## 超时：准确恢复到真实RTOS入口

无响应计数16位递增后达到100，执行 `230256e0` 后的真实软件动作：状态置0并请求RADIO.DISABLE，取消TXEN/START/RXEN/DISABLE订阅，清TIMER capture7订阅与CC6并STOP，清全局链路状态。

`23022c3c` 仅清队列0读写索引；恢复RADIO SHORTS=80001、INTENCLR/SET、PREFIX0和2610处的packet配置，mode切回2，执行原radio mode2相关寄存器设置。`23022f5c` 只写 **297c一个字节** 为1，然后进入 `0e0952ec(23003858)`。这是 **work-submit，不是semaphore**。

- work.flags(3864)&6为0：返回pending.entry=`0e0952ec`、args[0]=`23003858`，停在原函数入口；不改工作队列/线程状态。
- flags含bit1/bit2：原函数自然返回−16/0。调用者忽略此值后在 `23025720` 把栈首word明确写0；`23025ed4`据此写6b82=0。它计算 `(uint16(6b80)*31250+999)/1000`，准备 `0e096a50(timer=23001578, arg1=0, duration, high=0)`，period栈参数为0。模型返回该pending入口，不执行start。

因此本轮已经恢复到定时器启动前的确定状态，尚未恢复这条超时通知的实际work排队及active timer-start。ACK路径中已恢复的stop不能替代start。512个边界用例逐字节比较到相同原PC，包含有意义的入口寄存器，不补成功返回、不跳过目标函数。

## 证据与剩余范围

`EmulateMouseMode4Runtime.java`、`EmulateMouseMode4Ack.java` 校验原镜像和79c→23020000切片映射一致；原程序只读执行。CPU BASEPRI getter读取同一个ArmCpuState，返回路径检查恢复；架构屏障仅是惯性模拟，未证明真实调度。对照比较全部65536 RAM、RADIO4096、TIMER1536，及对应SPIM16/RTC4096/clock8/NVIC4窗口。

正式结果为 `mouse-mode4-runtime-comparison.json`、`mouse-mode4-runtime-integration.json`、`mouse-mode4-runtime-boundaries.json`。源文件、原记录、日志与回归证据的SHA256在同名exact.json。源码与数据冻结；未修改主报告、总索引或其它工作者模块。

仍未恢复：超时真实work队列/scheduler及timer-start；任意ACK/stop callback及等待线程；真实IRQ/RTOS/DMA竞争、初始化到全部DPPI端点、空口比特流与实机RF。完整2.4GHz恢复目标仍未宣称完成。
