# 鼠标无线首次启动：原始指令映射

依据官方1.20鼠标无线镜像与原始Thumb指令；本页是静态映射，执行验证见[差分报告](mouse-wireless-startup-exact.md)。逐段字节、偏移、哈希与源文件绑定见[JSON证据](mouse-wireless-startup-map.json)。

- `23021150(identity,rate)`：779A为零时调用25D1C，写779A=1，调用E096164(625 ticks)。等待实际返回后才执行259A4(identity,BF,0,rate)，最后写7799=1。
- `23025D1C`：初始化3858扫描工作项；创建TCB1BB8、栈109E0、长度400、入口25D91、优先级10、options0、delay0的线程；随后初始化67C0/67B0/67A0工作项，清76FB/76FA。
- 创建线程的AAPCS栈参数：+0/+4/+8三个参数，+C优先级，+10选项，+14是未读取的对齐空位；真正64位delay在+18/+1C，调用者显式写零。反编译器把空位误当一个参数，不能据此推断随机delay。
- 新线程帧为stack+align8(size)-48；R0入口、R1..R3参数、PC=E085EA4、xPSR=01000000。R12/LR、上部两个保留字保持旧值；顶端8字节清零。TCB+6C只清一个字节，+6D..6F保留。
- E095BF4清flag4后就绪排序；只有BASEPRI原为0、线程态且next不同于current才进入E089D4C。真实恢复点先到E095856，完成create返回，才能回25D48。
- ticks sleep：0走yield；其他值保存32位deadline，移出当前ready，插入timeout，置flag10，进入E089D4C。有限睡眠的恢复点E096110需重新读取tick；不能把到达切换入口当成睡眠结束。
- public infinite sleep先取消timeout；已有flag10直接返回FFFFFFFF，否则suspend；线程态可切换，异常上下文直接还原优先级后返回。
- tick读取是32位；7680非零仅用25F8低word，否则加RTC52位计数差右移5的低32位。高word超过3FFFFFFF是实际轮询等待。

当前代码在真实CPU请求入口暂停。创建线程后谁先运行、异常入栈/出栈、真实线程恢复、625tick经过和25D90消息消费仍需继续恢复。原始调用栈保留为证据；主机语义C不声称复现全部原生寄存器或调用栈。
