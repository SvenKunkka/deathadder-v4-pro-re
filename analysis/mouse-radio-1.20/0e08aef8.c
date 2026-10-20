/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08aef8. Types and names are inferred; NOT original source. */

int FUN_0e08aef8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 4;
  FUN_0e094c5c(iVar2,param_2,0xffffffff,0xffffffff);
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1e) < 0) {
      iVar1 = -0x78;
    }
    else {
      iVar1 = FUN_0e08d6f0(*(undefined4 *)(param_1 + 0x18));
      if (iVar1 == 0) {
        iVar1 = FUN_0e08bc80(param_1);
        if (iVar1 == 0) {
          *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 2;
          FUN_0e094d58(iVar2);
          return 0;
        }
        FUN_0e08d758(*(undefined4 *)(param_1 + 0x18));
      }
    }
  }
  else {
    iVar1 = -1;
  }
  FUN_0e094d58(iVar2);
  return iVar1;
}


