/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af2b0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0af2b0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0x90;
  iVar3 = param_1 * 0x14;
  FUN_0e0afad0(iVar2 + 0x2f011718,param_1 * 0x140 + 0x2f012ce0,0x140,&LAB_0e0af404_1,
               iVar3 + 0x2f011b98,0,0,0xf,1,0);
  bVar1 = *(byte *)(iVar2 + 0x2f011725);
  (&DAT_2f011ba8)[iVar3] = (char)param_1;
  *(byte *)(iVar2 + 0x2f011725) = bVar1 & 0xfb;
  *(int *)(iVar3 + 0x2f011b9c) = (param_1 + 1) * 0x800 + 0x2f0124e0;
  *(int *)(&DAT_2f011ba4 + iVar3) = iVar2 + 0x2f011718;
  _DAT_2f011b94 = _DAT_2f011b94 + 1;
  return;
}


