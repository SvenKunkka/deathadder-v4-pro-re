/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090058. Types and names are inferred; NOT original source. */

uint FUN_0e090058(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  
  if (7 < param_2) {
    param_2 = 8;
  }
  uVar2 = *(uint *)(DAT_0e090090 + 0x10);
  uVar1 = *(uint *)(DAT_0e090090 + 0x14);
  local_18 = uVar1 << 0x18 | ((uVar1 & 0xff00) >> 8) << 0x10 |
             (((*(uint *)(DAT_0e090090 + 0x18) & 0xff) << 0x10 | uVar1 & 0xff0000) >> 0x10) << 8 |
             (uVar1 | *(int *)(DAT_0e090090 + 0x28) << 0x18) >> 0x18;
  local_14 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
             uVar2 >> 0x18;
  FUN_0e0974c4(param_1,&local_18,param_2);
  return param_2;
}


