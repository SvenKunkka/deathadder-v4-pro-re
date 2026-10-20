/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a75c. Types and names are inferred; NOT original source. */

void FUN_0e08a75c(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 1);
  iVar2 = *param_1;
  *(ushort *)(param_1 + 1) = uVar1 + 2;
  *(char *)(iVar2 + (uint)uVar1) = (char)param_2;
  *(char *)(iVar2 + (uint)uVar1 + 1) = (char)((uint)param_2 >> 8);
  return;
}


