/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f80f0. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f80f0(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 1;
  uVar2 = *param_2;
  do {
    iVar4 = (uVar1 & 0x7f) + 0x10;
    if (uVar2 == 0) {
      return 0;
    }
    if ((int)((uVar2 >> iVar4) << 0x1f) < 0) {
      if (-1 < (int)((*param_1 >> iVar4) << 0x1f)) {
        return 0xffffffea;
      }
      *param_1 = *param_1 & ~(1 << iVar4);
      uVar2 = *param_2 & ~(1 << iVar4);
      *param_2 = uVar2;
    }
    uVar3 = 1 << (uVar1 & 0xff);
    if ((uVar2 >> (uVar1 & 0xff) & 1) != 0) {
      if (-1 < (int)((*param_1 >> (uVar1 & 0xff)) << 0x1f)) {
        return 0xffffffea;
      }
      *param_1 = *param_1 & ~uVar3;
      uVar2 = *param_2 & ~uVar3;
      *param_2 = uVar2;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0x10);
  return 0;
}


