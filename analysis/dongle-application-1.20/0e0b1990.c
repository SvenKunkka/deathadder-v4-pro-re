/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1990. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0b1990(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = FUN_0e0b1938(iVar3);
  if (iVar1 == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    **(int **)(iVar3 + 4) = param_1[1];
    **(int **)*param_1 = param_1[2];
    DataMemoryBarrier(0x1b);
    FUN_0e0ad944(*(undefined4 *)(*param_1 + 4),4);
    FUN_0e0ad944(*(undefined4 *)*param_1,4);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


