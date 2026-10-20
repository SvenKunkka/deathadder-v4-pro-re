/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ce48. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ce48(int *param_1,undefined4 param_2,int param_3,int param_4)

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
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[3] == 0) {
    iVar4 = *(int *)(DAT_0e06cf3c + 8);
    iVar6 = (int)*(char *)(iVar4 + 0xe);
LAB_0e06ce68:
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
  iVar4 = *(int *)(DAT_0e06cf3c + 8);
  if (iVar6 == iVar4) {
    iVar6 = param_1[4];
    goto LAB_0e06ce68;
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
    iVar4 = FUN_0e06e064(iVar6);
  }
  else {
    iVar4 = 0;
  }
  iVar6 = FUN_0e06df64(DAT_0e06cf40,uVar8,param_1,param_4,param_3,param_4);
  if (iVar6 == 0) {
    return 0;
  }
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
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
    if ((iVar6 != *(char *)(param_1[2] + 0xe)) && (iVar6 = FUN_0e06e064(), iVar6 != 0))
    goto LAB_0e06cf12;
  }
  if (iVar4 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
LAB_0e06cf12:
  FUN_0e06e114(DAT_0e06cf40,uVar8);
  return 0xfffffff5;
}


