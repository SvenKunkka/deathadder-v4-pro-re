/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e6ac. Types and names are inferred; NOT original source. */

void FUN_0e06e6ac(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = *param_1;
  if ((*(int **)(DAT_0e06e6e0 + 4) != param_1) && (iVar3 != 0)) {
    uVar2 = *(uint *)(iVar3 + 0x10);
    uVar4 = param_1[4];
    iVar5 = param_1[5];
    *(uint *)(iVar3 + 0x10) = uVar2 + uVar4;
    *(uint *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5 + (uint)CARRY4(uVar2,uVar4);
    iVar3 = *param_1;
  }
  piVar1 = (int *)param_1[1];
  *piVar1 = iVar3;
  *(int **)(iVar3 + 4) = piVar1;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


