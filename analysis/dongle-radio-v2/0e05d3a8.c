/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d3a8. Types and names are inferred; NOT original source. */

void FUN_0e05d3a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  iVar1 = param_2 * 8 + 2;
  iVar3 = param_3 * 8 + 2;
  sVar2 = (*(ushort *)(param_1 + iVar1) >> 1) + (*(ushort *)(param_1 + iVar3) >> 1);
  *(short *)(param_1 + iVar1) = sVar2 * 2;
  *(short *)(param_1 + (param_3 + (uint)(*(ushort *)(param_1 + iVar3) >> 1)) * 8) = sVar2;
  return;
}


