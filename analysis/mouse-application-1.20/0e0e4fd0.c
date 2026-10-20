/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e4fd0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e4fd0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0x90;
  iVar3 = param_1 * 0x14;
  FUN_0e0e57e4(iVar2 + 0x2f011488,param_1 * 0x140 + 0x2f012818,0x140,&LAB_0e0e5124_1,
               iVar3 + 0x2f0118d4,0,0,0xf,1,0);
  bVar1 = *(byte *)(iVar2 + 0x2f011495);
  (&DAT_2f0118e4)[iVar3] = (char)param_1;
  *(byte *)(iVar2 + 0x2f011495) = bVar1 & 0xfb;
  *(int *)(iVar3 + 0x2f0118d8) = (param_1 + 1) * 0x800 + 0x2f012018;
  *(int *)(&DAT_2f0118e0 + iVar3) = iVar2 + 0x2f011488;
  _DAT_2f0118d0 = _DAT_2f0118d0 + 1;
  return;
}


