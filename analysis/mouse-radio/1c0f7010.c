/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f7010. Types and names are inferred; NOT original source. */

int FUN_1c0f7010(int param_1)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  FUN_1c10201c();
  iVar2 = param_1 + 4;
  FUN_1c100d84(iVar2,extraout_r1,0xffffffff,0xffffffff);
  if (*(int *)(param_1 + 0x18) != 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
      iVar1 = -0x78;
      goto LAB_1c0f7044;
    }
    iVar1 = FUN_1c100688();
    if (iVar1 != 0) {
      iVar1 = FUN_1c0f80bc(param_1);
      if (iVar1 == 0) {
        FUN_1c103512(param_1 + 0x20,0,0x28);
        *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 1;
        FUN_1c100e80(iVar2);
        FUN_1c102044();
        return 0;
      }
      goto LAB_1c0f7044;
    }
  }
  iVar1 = -0x13;
LAB_1c0f7044:
  FUN_1c100e80(iVar2);
  FUN_1c102044();
  return iVar1;
}


