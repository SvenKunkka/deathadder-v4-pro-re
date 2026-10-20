/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8ab0. Types and names are inferred; NOT original source. */

int FUN_1c0f8ab0(undefined4 param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_1c0f95cc();
  if (iVar1 == 0) {
    uVar2 = param_2;
    if ((int)(param_2 << 0x18) < 0) {
      uVar2 = (param_2 & 0xffffff7f) + 0x10;
    }
    *param_3 = *param_3 & ~(1 << (uVar2 & 0xff));
    iVar1 = FUN_1c0f9738(param_1,param_2);
    if (iVar1 == 0) {
      FUN_1c102134();
      return 0;
    }
  }
  return iVar1;
}


