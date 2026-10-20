/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094c5c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e094c5c(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = DAT_23007654;
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[3] == 0) {
    iVar5 = (int)*(char *)(DAT_23007654 + 0xe);
LAB_0e094c7c:
    param_1[3] = param_1[3] + 1;
    param_1[4] = iVar5;
    param_1[2] = iVar8;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  iVar5 = param_1[2];
  if (iVar5 == DAT_23007654) {
    iVar5 = param_1[4];
    goto LAB_0e094c7c;
  }
  if (param_3 == 0 && param_4 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff0;
  }
  cVar1 = *(char *)(iVar5 + 0xe);
  cVar4 = *(char *)(DAT_23007654 + 0xe);
  if (cVar1 <= *(char *)(DAT_23007654 + 0xe)) {
    cVar4 = cVar1;
  }
  if (cVar4 < -0x7f) {
    cVar4 = -0x7f;
  }
  if (cVar4 < cVar1) {
    iVar8 = FUN_0e095df8(iVar5);
  }
  else {
    iVar8 = 0;
  }
  iVar5 = FUN_0e095cf8(&DAT_23007670,uVar7,param_1,param_4,param_3,param_4);
  if (iVar5 == 0) {
    return 0;
  }
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[2] != 0) {
    piVar6 = (int *)*param_1;
    iVar5 = param_1[4];
    if ((param_1 != piVar6) && (piVar6 != (int *)0x0)) {
      if (*(char *)((int)piVar6 + 0xe) <= iVar5) {
        iVar5 = (int)*(char *)((int)piVar6 + 0xe);
      }
      if (iVar5 < -0x7f) {
        iVar5 = -0x7f;
      }
    }
    if ((iVar5 != *(char *)(param_1[2] + 0xe)) && (iVar5 = FUN_0e095df8(), iVar5 != 0))
    goto LAB_0e094d26;
  }
  if (iVar8 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
LAB_0e094d26:
  FUN_0e095ea8(&DAT_23007670,uVar7);
  return 0xfffffff5;
}


