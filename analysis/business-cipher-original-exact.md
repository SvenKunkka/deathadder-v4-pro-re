# 业务软件加解密：原指令差分

原始函数为鼠标 `23020D50` 和接收器 `2302003C`。它们对32位小端字实现互逆的XXTEA更新循环；已发现业务调用使用8/16字节，对应2/4个word、32/19轮。算法及表项来源的静态链见 `business-queue-map.md`。

`EmulateBusinessCipher.java` 直接运行两端原函数，各64组，覆盖16个表项×两种长度×每组合两组输入。key来自各自已核验原镜像中的表；入口参数为数据指针、word数量和key指针。没有替换指令、跳过函数或补充CPU userop。

**128组通过**：Python `business_software_cipher.py` 和C `portable/business_cipher.c` 各自与原指令输出一致；同时检查数据尾部16/24字节guard及key内存保持不变。结果见 `business-cipher-original-comparison.json`，输入输出分别在 `mouse-cipher-original.jsonl` 和 `dongle-cipher-original.jsonl`。

这将验证从“两个恢复实现能互逆”推进到了“与原函数计算结果一致”。仍只覆盖纯算法入口，不证明key安装包装函数、分片/重组、整条无线业务或认证机制已经端到端验证。数据加密与身份认证是不同问题，不能由这个算法推导完整认证安全性。

C函数以numeric uint32_t数组为接口；原固件从字节加载/存回时使用小端。恢复接口对不属于2/4的word数量返回-1，这属于分析接口保护，不是原函数自身的检查。复验：`rtk proxy python3 analysis/verify_business_cipher_original.py`。
