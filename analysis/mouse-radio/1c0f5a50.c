/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f5a50. Types and names are inferred; NOT original source. */

int FUN_1c0f5a50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_1c0f5a8c;
  iVar1 = DAT_1c0f5a88;
  iVar3 = DAT_1c0f5a88 + DAT_1c0f5a8c;
  param_2 = param_2 - iVar3;
  FUN_1c1034c4(param_2,DAT_1c0f5a90,DAT_1c0f5a88);
  FUN_1c103512(param_2 + iVar1,0,iVar2);
  *(int *)(param_1 + 0x84) = param_2 + -8;
  return iVar3 + 8;
}


