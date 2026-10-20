/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a6a0. Types and names are inferred; NOT original source. */

void FUN_0e06a6a0(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0e06ab80(param_2);
  iVar3 = FUN_0e06ab70();
  if (iVar3 == 0xf) {
    bVar1 = (&DAT_23006e60)[param_1 * 0xc];
  }
  else {
    bVar1 = (&DAT_23006e61)[param_1 * 0xc];
  }
  if (((*(int *)(&DAT_23006e5c + param_1 * 0xc) != iVar2) &&
      (*(int *)(&DAT_23006e58 + param_1 * 0xc) != iVar2)) && (iVar2 = FUN_0e06a0d4(), iVar2 != 0)) {
    FUN_0e06ab78();
  }
  if (param_2 + 0xacfd4000U < 0x1065) {
    iVar2 = 0x100;
  }
  else {
    iVar2 = 0x80;
  }
  *(uint *)(iVar2 + param_2) = bVar1 | 0x80000000;
  return;
}


