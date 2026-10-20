/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f1e24. Types and names are inferred; NOT original source. */

void FUN_1c0f1e24(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar1 = *param_1;
    uVar2 = (param_2 + -4) - iVar1;
    iVar3 = (uVar2 & 0xfffffff8) + iVar1;
    *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) & 0xfffe;
    FUN_1c0f1da4(iVar1,uVar2 >> 3);
    return;
  }
  return;
}


