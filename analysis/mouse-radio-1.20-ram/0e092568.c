/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092568. Types and names are inferred; NOT original source. */

void FUN_0e092568(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0e092a48(param_2);
  iVar3 = FUN_0e092a38();
  if (iVar3 == 0xf) {
    bVar1 = (&DAT_23007340)[param_1 * 0xc];
  }
  else {
    bVar1 = (&DAT_23007341)[param_1 * 0xc];
  }
  if (((*(int *)(&DAT_2300733c + param_1 * 0xc) != iVar2) &&
      (*(int *)(&DAT_23007338 + param_1 * 0xc) != iVar2)) && (iVar2 = FUN_0e091f9c(), iVar2 != 0)) {
    FUN_0e092a40();
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


