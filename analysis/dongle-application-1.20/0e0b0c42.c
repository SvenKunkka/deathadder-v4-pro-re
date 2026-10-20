/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0c42. Types and names are inferred; NOT original source. */

void FUN_0e0b0c42(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_3 + -1 + param_2;
  uVar3 = param_2 >> 5;
  uVar4 = uVar1 >> 5;
  uVar1 = uVar1 & 0x1f;
  param_1[3] = uVar1;
  uVar1 = 1 << uVar1;
  param_1[2] = param_2 & 0x1f;
  uVar2 = -(1 << (param_2 & 0x1f));
  uVar1 = uVar1 | uVar1 - 1;
  param_1[4] = uVar2;
  if (uVar3 == uVar4) {
    uVar2 = uVar2 & uVar1;
  }
  *param_1 = uVar3;
  param_1[1] = uVar4;
  param_1[5] = uVar1;
  if (uVar3 == uVar4) {
    param_1[4] = uVar2;
  }
  return;
}


