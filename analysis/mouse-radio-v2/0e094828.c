/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094828. Types and names are inferred; NOT original source. */

void FUN_0e094828(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0e094894 + param_1 * 0x90;
  iVar3 = DAT_0e094898 + param_1 * 0x14;
  FUN_0e095838(iVar4,DAT_0e09489c + param_1 * 0x200,0x200,DAT_0e0948a0,iVar3,0,0,0xb,1,0);
  iVar2 = DAT_0e0948a4 + (param_1 + 1) * 0xa00;
  *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) & 0xfb;
  piVar1 = DAT_0e0948a8;
  *(int *)(iVar3 + 0xc) = iVar4;
  *(char *)(iVar3 + 0x10) = (char)param_1;
  *(int *)(iVar3 + 4) = iVar2;
  *piVar1 = *piVar1 + 1;
  return;
}


