/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08c68c. Types and names are inferred; NOT original source. */

uint FUN_0e08c68c(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = DAT_0e08c6ec;
  uVar2 = DAT_0e08c6e4;
  uVar1 = DAT_0e08c6e0;
  if (param_2 == 0) {
    for (; uVar1 < uVar2; uVar1 = uVar1 + 0x18) {
      iVar4 = FUN_0e0797f4(param_1,**(undefined4 **)(uVar1 + 4));
      if (iVar4 == 0) {
        return uVar1;
      }
    }
  }
  else {
    uVar1 = DAT_0e08c6e8;
    if (param_2 == 1) {
      for (; uVar1 < uVar3; uVar1 = uVar1 + 0x18) {
        iVar4 = FUN_0e0797f4(param_1,**(undefined4 **)(uVar1 + 4));
        if (iVar4 == 0) {
          return uVar1;
        }
      }
    }
  }
  return 0;
}


