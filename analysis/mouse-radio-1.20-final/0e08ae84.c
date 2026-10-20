/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ae84. Types and names are inferred; NOT original source. */

int FUN_0e08ae84(int param_1)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  FUN_0e095ef4();
  iVar2 = param_1 + 4;
  FUN_0e094c5c(iVar2,extraout_r1,0xffffffff,0xffffffff);
  if (*(int *)(param_1 + 0x18) != 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
      iVar1 = -0x78;
      goto LAB_0e08aeb8;
    }
    iVar1 = FUN_0e094560();
    if (iVar1 != 0) {
      iVar1 = FUN_0e08bf30(param_1);
      if (iVar1 == 0) {
        FUN_0e0973ea(param_1 + 0x20,0,0x28);
        *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 1;
        FUN_0e094d58(iVar2);
        FUN_0e095f1c();
        return 0;
      }
      goto LAB_0e08aeb8;
    }
  }
  iVar1 = -0x13;
LAB_0e08aeb8:
  FUN_0e094d58(iVar2);
  FUN_0e095f1c();
  return iVar1;
}


