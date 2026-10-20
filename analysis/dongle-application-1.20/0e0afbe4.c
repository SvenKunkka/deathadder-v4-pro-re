/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0afbe4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0afbe4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r1;
  int iVar1;
  int extraout_r2;
  
  iVar1 = (int)*(char *)(param_1 + 0xd);
  if (iVar1 < 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0x7f;
    FUN_0e0b2458();
    param_1 = extraout_r1;
    iVar1 = extraout_r2;
  }
  FUN_0e0afba8(_DAT_2f011ba0 == param_1,param_1,iVar1,param_4);
  return;
}


