/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068b38. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e068b82) */

undefined4 FUN_0e068b38(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if (-1 < (int)((uVar3 >> (param_2 & 0xff)) << 0x1f)) {
    uVar2 = 1 << (param_2 & 0xff);
    bVar1 = false;
    if (*param_1 == uVar3) {
      *param_1 = uVar3 | uVar2;
      bVar1 = true;
    }
    while (!bVar1) {
      bVar1 = false;
      if (*param_1 == *param_1) {
        *param_1 = uVar2 | *param_1;
        bVar1 = true;
      }
    }
    return DAT_0e068b84;
  }
  return DAT_0e068b88;
}


