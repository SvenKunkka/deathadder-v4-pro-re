/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06db60. Types and names are inferred; NOT original source. */

void FUN_0e06db60(int *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  
  if (param_3 == 0) {
    bVar6 = 0x10;
  }
  else {
    bVar6 = 8;
  }
  bVar1 = *(byte *)((int)param_1 + 0xd);
  if ((bVar6 & bVar1) != 0) goto joined_r0x0e06dbd4;
  if ((char)bVar1 < '\0') {
    *(byte *)((int)param_1 + 0xd) = bVar6 | bVar1 & 0x7f;
    iVar5 = *param_1;
    piVar2 = (int *)param_1[1];
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    *param_1 = 0;
    param_1[1] = 0;
    if (bVar6 == 8) goto LAB_0e06dbfe;
LAB_0e06db9a:
    bVar7 = false;
  }
  else {
    *(byte *)((int)param_1 + 0xd) = bVar6 | bVar1;
    if (bVar6 != 8) goto LAB_0e06db9a;
LAB_0e06dbfe:
    if (param_1[2] != 0) {
      iVar5 = *param_1;
      piVar2 = (int *)param_1[1];
      *piVar2 = iVar5;
      *(int **)(iVar5 + 4) = piVar2;
      *param_1 = 0;
      param_1[1] = 0;
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
      param_1[2] = 0;
    }
    FUN_0e06e768(param_1 + 6);
    piVar2 = (int *)param_1[0x16];
    while ((param_1 + 0x16 != piVar2 && (piVar2 != (int *)0x0))) {
      iVar5 = *piVar2;
      piVar3 = (int *)piVar2[1];
      *piVar3 = iVar5;
      *(int **)(iVar5 + 4) = piVar3;
      *(byte *)((int)piVar2 + 0xd) = *(byte *)((int)piVar2 + 0xd) & 0xfd;
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      FUN_0e06e768(piVar2 + 6);
      piVar2[0x23] = 0;
      FUN_0e06da0c(piVar2);
      piVar2 = (int *)param_1[0x16];
    }
    if (param_1 == DAT_23007170) {
      uVar4 = 0;
      bVar7 = (bool)isCurrentModePrivileged();
      if (bVar7) {
        uVar4 = getCurrentExceptionNumber();
        uVar4 = uVar4 & 0x1ff;
      }
      bVar7 = uVar4 != 0;
    }
    else {
      bVar7 = false;
    }
  }
  if (((int **)DAT_23007180 == &DAT_23007180) || (piVar2 = DAT_23007180, DAT_23007180 == (int *)0x0)
     ) {
    piVar2 = DAT_23007174;
  }
  if (piVar2 != DAT_23007170) {
    FUN_0e06e4ec(piVar2);
  }
  DAT_2300717c = piVar2;
  if ((bVar6 != 0x10) && (bVar7)) {
    DAT_23002c44 = 0;
    DAT_23002c48 = 0;
    DAT_23002bdc = 0x101;
    FUN_0e06ee28(&DAT_23002bd0);
    DAT_23007170 = (int *)&DAT_23002bd0;
  }
  DataMemoryBarrier(0x1f);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x9f;
joined_r0x0e06dbd4:
  if (DAT_23007170 == param_1) {
    uVar4 = 0;
    bVar7 = (bool)isCurrentModePrivileged();
    if (bVar7) {
      uVar4 = getCurrentExceptionNumber();
      uVar4 = uVar4 & 0x1ff;
    }
    if (uVar4 == 0) {
      FUN_0e0611cc(param_2);
      return;
    }
  }
  bVar7 = (bool)isCurrentModePrivileged();
  if (bVar7) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


