/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1532. Types and names are inferred; NOT original source. */

int FUN_0e0b1532(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*param_1 + 0x1c);
  iVar2 = param_4 * *(int *)(*param_1 + 0x20);
  *(int *)(iVar1 + iVar2) = param_5;
  DataMemoryBarrier(0x1b);
  FUN_0e0ad944(iVar1 + iVar2,param_5 + 4);
  iVar1 = FUN_0e0b142e(param_1,param_2,param_3,param_4 & 0xff);
  if (iVar1 < 0) {
    FUN_0e0b14a2(param_1,param_4,param_5,0xffffffff);
  }
  return iVar1;
}


