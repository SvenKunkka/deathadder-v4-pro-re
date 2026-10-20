/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5ed0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e5ed0(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (((param_1 != (int *)0x0) && (param_1 != _DAT_2f0112a4)) && (iVar3 = *param_1, iVar3 != 0)) {
    uVar1 = *(uint *)(iVar3 + 0x10);
    uVar4 = param_1[4];
    iVar5 = param_1[5];
    *(uint *)(iVar3 + 0x10) = uVar1 + uVar4;
    *(uint *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5 + (uint)CARRY4(uVar1,uVar4);
  }
  iVar3 = *param_1;
  piVar2 = (int *)param_1[1];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


