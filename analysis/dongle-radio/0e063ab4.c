/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063ab4. Types and names are inferred; NOT original source. */

uint FUN_0e063ab4(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = DAT_0e063b14;
  uVar2 = DAT_0e063b0c;
  uVar1 = DAT_0e063b08;
  if (param_2 == 0) {
    for (; uVar1 < uVar2; uVar1 = uVar1 + 0x18) {
      iVar4 = FUN_0e05bc0c(param_1,**(undefined4 **)(uVar1 + 4));
      if (iVar4 == 0) {
        return uVar1;
      }
    }
  }
  else {
    uVar1 = DAT_0e063b10;
    if (param_2 == 1) {
      for (; uVar1 < uVar3; uVar1 = uVar1 + 0x18) {
        iVar4 = FUN_0e05bc0c(param_1,**(undefined4 **)(uVar1 + 4));
        if (iVar4 == 0) {
          return uVar1;
        }
      }
    }
  }
  return 0;
}


