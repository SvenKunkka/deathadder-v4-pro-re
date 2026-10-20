/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060eb0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e060eb0(undefined4 param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = (*(uint *)(DAT_0e060f10 + 0x28) & 0x2000000) != 0;
  if (bVar2) {
    param_1 = 0x1e;
  }
  if (!bVar2) {
    param_1 = 0x1d;
  }
  uVar1 = *(uint *)(DAT_0e060f10 + 0x28);
  if ((*(uint *)(DAT_0e060f10 + 0x28) & 0x1000000) != 0) {
    param_1 = 0x1f;
  }
  if ((*(uint *)(DAT_0e060f10 + 0x28) & 0x100000) != 0) {
    param_1 = 2;
  }
  if ((*(uint *)(DAT_0e060f10 + 0x28) & 0x80000) != 0) {
    param_1 = 0x21;
  }
  if ((*(uint *)(DAT_0e060f10 + 0x28) & 0x40000) != 0) {
    param_1 = 0x22;
  }
  if ((*(uint *)(DAT_0e060f10 + 0x28) & 0x20000) != 0) {
    param_1 = 0x23;
  }
  *(uint *)(DAT_0e060f10 + 0x28) = ~((uint)~(*(int *)(DAT_0e060f10 + 0x28) << 0x10) >> 0x10);
  if ((uVar1 & 0x10000) != 0) {
    param_1 = 0x24;
  }
  return param_1;
}


