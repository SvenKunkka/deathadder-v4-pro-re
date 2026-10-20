/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08cab0. Types and names are inferred; NOT original source. */

int FUN_0e08cab0(undefined4 param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0e08d5cc();
  if (iVar1 == 0) {
    uVar2 = param_2;
    if ((int)(param_2 << 0x18) < 0) {
      uVar2 = (param_2 & 0xffffff7f) + 0x10;
    }
    *param_3 = *param_3 & ~(1 << (uVar2 & 0xff));
    iVar1 = FUN_0e08d738(param_1,param_2);
    if (iVar1 == 0) {
      FUN_0e096134();
      return 0;
    }
  }
  return iVar1;
}


