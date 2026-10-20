/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e52b8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e52b8(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int extraout_r3;
  int *piVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[3] == 0) {
    iVar3 = (int)*(char *)(_DAT_2f0118dc + 0xe);
LAB_0e0e52fc:
    param_1[3] = param_1[3] + 1;
    iVar4 = _DAT_2f0118dc;
    param_1[4] = iVar3;
    param_1[2] = iVar4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  if (param_1[2] == _DAT_2f0118dc) {
    iVar3 = param_1[4];
    goto LAB_0e0e52fc;
  }
  if (param_3 == 0 && param_4 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff0;
  }
  iVar4 = (int)*(char *)(param_1[2] + 0xe);
  iVar3 = (int)*(char *)(_DAT_2f0118dc + 0xe);
  if (iVar4 <= *(char *)(_DAT_2f0118dc + 0xe)) {
    iVar3 = iVar4;
  }
  if (iVar3 < -0x7f) {
    iVar3 = -0x7f;
  }
  if (iVar3 < iVar4) {
    iVar3 = FUN_0e0e6f74();
    iVar4 = extraout_r3;
  }
  else {
    iVar3 = 0;
  }
  iVar4 = FUN_0e0e5ae0(0x2f011915,uVar6,param_1,iVar4,param_3,param_4);
  if (iVar4 == 0) {
    return 0;
  }
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[2] != 0) {
    piVar5 = (int *)*param_1;
    iVar4 = param_1[4];
    if ((param_1 != piVar5) && (piVar5 != (int *)0x0)) {
      if (*(char *)((int)piVar5 + 0xe) <= iVar4) {
        iVar4 = (int)*(char *)((int)piVar5 + 0xe);
      }
      if (iVar4 < -0x7f) {
        iVar4 = -0x7f;
      }
    }
    iVar4 = FUN_0e0e6f74(param_1[2],iVar4);
    if (iVar4 != 0) goto LAB_0e0e5380;
  }
  if (iVar3 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
LAB_0e0e5380:
  FUN_0e0e5bc0(0x2f011915,uVar6);
  return 0xfffffff5;
}


