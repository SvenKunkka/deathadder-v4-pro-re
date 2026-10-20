/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d560. Types and names are inferred; NOT original source. */

void FUN_0e05d560(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar1 = *param_1;
    uVar2 = (param_2 + -4) - iVar1;
    iVar3 = (uVar2 & 0xfffffff8) + iVar1;
    *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) & 0xfffe;
    FUN_0e05d4e0(iVar1,uVar2 >> 3);
    return;
  }
  return;
}


