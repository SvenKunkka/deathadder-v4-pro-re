/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c100d84. Types and names are inferred; NOT original source. */

undefined4 FUN_1c100d84(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[3] == 0) {
    iVar4 = *(int *)(DAT_1c100e78 + 8);
    iVar6 = (int)*(char *)(iVar4 + 0xe);
LAB_1c100da4:
    param_1[3] = param_1[3] + 1;
    param_1[4] = iVar6;
    param_1[2] = iVar4;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  iVar6 = param_1[2];
  iVar4 = *(int *)(DAT_1c100e78 + 8);
  if (iVar6 == iVar4) {
    iVar6 = param_1[4];
    goto LAB_1c100da4;
  }
  if (param_3 == 0 && param_4 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff0;
  }
  cVar1 = *(char *)(iVar6 + 0xe);
  cVar5 = *(char *)(iVar4 + 0xe);
  if (cVar1 <= *(char *)(iVar4 + 0xe)) {
    cVar5 = cVar1;
  }
  if (cVar5 < -0x7f) {
    cVar5 = -0x7f;
  }
  if (cVar5 < cVar1) {
    iVar4 = FUN_1c101f20(iVar6);
  }
  else {
    iVar4 = 0;
  }
  iVar6 = FUN_1c101e20(DAT_1c100e7c,uVar8,param_1,param_4,param_3,param_4);
  if (iVar6 == 0) {
    return 0;
  }
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[2] != 0) {
    piVar7 = (int *)*param_1;
    iVar6 = param_1[4];
    if ((param_1 != piVar7) && (piVar7 != (int *)0x0)) {
      if (*(char *)((int)piVar7 + 0xe) <= iVar6) {
        iVar6 = (int)*(char *)((int)piVar7 + 0xe);
      }
      if (iVar6 < -0x7f) {
        iVar6 = -0x7f;
      }
    }
    if ((iVar6 != *(char *)(param_1[2] + 0xe)) && (iVar6 = FUN_1c101f20(), iVar6 != 0))
    goto LAB_1c100e4e;
  }
  if (iVar4 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
LAB_1c100e4e:
  FUN_1c101fd0(DAT_1c100e7c,uVar8);
  return 0xfffffff5;
}


