/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f868c. Types and names are inferred; NOT original source. */

uint FUN_1c0f868c(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = DAT_1c0f86ec;
  uVar2 = DAT_1c0f86e4;
  uVar1 = DAT_1c0f86e0;
  if (param_2 == 0) {
    for (; uVar1 < uVar2; uVar1 = uVar1 + 0x18) {
      iVar4 = FUN_1c0e57f4(param_1,**(undefined4 **)(uVar1 + 4));
      if (iVar4 == 0) {
        return uVar1;
      }
    }
  }
  else {
    uVar1 = DAT_1c0f86e8;
    if (param_2 == 1) {
      for (; uVar1 < uVar3; uVar1 = uVar1 + 0x18) {
        iVar4 = FUN_1c0e57f4(param_1,**(undefined4 **)(uVar1 + 4));
        if (iVar4 == 0) {
          return uVar1;
        }
      }
    }
  }
  return 0;
}


