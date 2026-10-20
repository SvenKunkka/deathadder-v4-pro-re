/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062338. Types and names are inferred; NOT original source. */

int FUN_0e062338(int param_1)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  FUN_0e06e0c4();
  iVar2 = param_1 + 4;
  FUN_0e06cdac(iVar2,extraout_r1,0xffffffff,0xffffffff);
  if (*(int *)(param_1 + 0x18) != 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
      iVar1 = -0x78;
      goto LAB_0e06236c;
    }
    iVar1 = FUN_0e06c6c0();
    if (iVar1 != 0) {
      iVar1 = FUN_0e0633e4(param_1);
      if (iVar1 == 0) {
        FUN_0e06f3aa(param_1 + 0x20,0,0x28);
        *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 1;
        FUN_0e06cea8(iVar2);
        FUN_0e06e0ec();
        return 0;
      }
      goto LAB_0e06236c;
    }
  }
  iVar1 = -0x13;
LAB_0e06236c:
  FUN_0e06cea8(iVar2);
  FUN_0e06e0ec();
  return iVar1;
}


