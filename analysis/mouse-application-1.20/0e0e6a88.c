/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6a88. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0e6a88(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = FUN_0e0e6a30(iVar3);
  if (iVar1 == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    **(int **)(iVar3 + 4) = param_1[1];
    **(int **)*param_1 = param_1[2];
    DataMemoryBarrier(0x1b);
    FUN_0e0e41f0(*(undefined4 *)(*param_1 + 4),4);
    FUN_0e0e41f0(*(undefined4 *)*param_1,4);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


