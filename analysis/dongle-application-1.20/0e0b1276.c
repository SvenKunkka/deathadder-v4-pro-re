/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1276. Types and names are inferred; NOT original source. */

int FUN_0e0b1276(int *param_1,uint param_2,uint *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 < (uint)param_1[2]) {
    iVar4 = *param_1;
    iVar3 = param_1[1] * param_2;
    iVar1 = iVar4 + iVar3;
    if (param_3 != (uint *)0x0) {
      if (param_4 != 0) {
        FUN_0e0ad960(iVar1,4,param_3,param_1[1],param_4);
        DataMemoryBarrier(0x1b);
      }
      uVar2 = *(uint *)(iVar4 + iVar3);
      if ((param_1[1] * param_1[2] - 4U < uVar2) ||
         ((uint)(*param_1 + param_1[1] * param_1[2]) < uVar2 + 4 + iVar1)) goto LAB_0e0b1286;
      *param_3 = uVar2;
      if (param_4 != 0) {
        FUN_0e0ad960(iVar1 + 4);
        DataMemoryBarrier(0x1b);
      }
    }
    iVar1 = iVar1 + 4;
  }
  else {
LAB_0e0b1286:
    iVar1 = 0;
  }
  return iVar1;
}


