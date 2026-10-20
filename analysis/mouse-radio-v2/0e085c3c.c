/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085c3c. Types and names are inferred; NOT original source. */

void FUN_0e085c3c(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_2 * 8 + 2;
  sVar1 = (short)param_3 - (short)param_2;
  iVar2 = (param_2 - param_3) + (uint)(*(ushort *)(param_1 + iVar3) >> 1);
  uVar4 = iVar2 * 2;
  *(short *)(param_1 + iVar3) = sVar1 * 2;
  *(short *)(param_1 + param_3 * 8 + 2) = (short)uVar4;
  *(short *)(param_1 + param_3 * 8) = sVar1;
  *(short *)(param_1 + (((uVar4 & 0xffff) >> 1) + param_3) * 8) = (short)iVar2;
  return;
}


