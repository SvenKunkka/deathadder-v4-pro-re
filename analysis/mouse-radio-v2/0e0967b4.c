/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0967b4. Types and names are inferred; NOT original source. */

void FUN_0e0967b4(uint param_1)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  undefined4 uVar14;
  
  puVar4 = DAT_0e0968d8;
  piVar3 = DAT_0e0968d4;
  uVar14 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar14 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar12 = getBasePriority(), uVar12 == 0 || 0x20 < uVar12)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  *DAT_0e0968d8 = param_1;
  puVar5 = DAT_0e0968dc;
  piVar6 = (int *)*piVar3;
  if (piVar6 == piVar3) {
LAB_0e0968a0:
    uVar12 = *puVar5;
    *puVar4 = 0;
    *puVar5 = uVar12 + param_1;
    puVar5[1] = puVar5[1] + ((int)param_1 >> 0x1f) + (uint)CARRY4(uVar12,param_1);
LAB_0e0968b4:
    FUN_0e097738();
LAB_0e0968b8:
    uVar9 = 0x7fffffff;
  }
  else {
    if (piVar6 == (int *)0x0) {
      *puVar4 = 0;
      uVar12 = *puVar5;
      *puVar5 = uVar12 + param_1;
      puVar5[1] = puVar5[1] + ((int)param_1 >> 0x1f) + (uint)CARRY4(uVar12,param_1);
      goto LAB_0e0968b4;
    }
    do {
      uVar12 = piVar6[4];
      iVar8 = piVar6[5];
      iVar7 = (int)param_1 >> 0x1f;
      if ((int)((iVar7 - iVar8) - (uint)(param_1 < uVar12)) < 0 !=
          (SBORROW4(iVar7,iVar8) != SBORROW4(iVar7 - iVar8,(uint)(param_1 < uVar12)))) {
        piVar6[4] = uVar12 - param_1;
        piVar13 = (int *)*piVar3;
        piVar6[5] = (iVar8 - iVar7) - (uint)(uVar12 < param_1);
        goto LAB_0e09684e;
      }
      uVar10 = *puVar5;
      uVar9 = puVar5[1];
      piVar6[4] = 0;
      piVar6[5] = 0;
      *puVar5 = uVar10 + uVar12;
      puVar5[1] = uVar9 + ((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar10,uVar12);
      iVar7 = FUN_0e096564();
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar14);
      }
      InstructionSynchronizationBarrier(0xf);
      (**(code **)(iVar7 + 8))();
      uVar14 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar14 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar9 = getBasePriority(), uVar9 == 0 || 0x20 < uVar9)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      piVar6 = (int *)*piVar3;
      param_1 = *puVar4 - uVar12;
      *puVar4 = param_1;
      if (piVar6 == piVar3) goto LAB_0e0968a0;
    } while (piVar6 != (int *)0x0);
    iVar7 = (int)param_1 >> 0x1f;
    piVar13 = (int *)0x0;
LAB_0e09684e:
    *puVar4 = 0;
    uVar12 = *puVar5;
    *puVar5 = uVar12 + param_1;
    puVar5[1] = puVar5[1] + iVar7 + (uint)CARRY4(uVar12,param_1);
    if (piVar13 == piVar3) goto LAB_0e0968b4;
    uVar12 = FUN_0e097738();
    if (piVar13 == (int *)0x0) goto LAB_0e0968b8;
    uVar9 = piVar13[4] - uVar12;
    iVar7 = (piVar13[5] - ((int)uVar12 >> 0x1f)) - (uint)((uint)piVar13[4] < uVar12);
    if ((int)(uint)(uVar9 < 0x80000000) <= iVar7) goto LAB_0e0968b8;
    if (iVar7 < 0) {
      uVar9 = 0;
    }
  }
  FUN_0e097648(uVar9,0);
  iVar7 = DAT_0e09651c;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar14);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar14 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar14 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar12 = getBasePriority(), uVar12 == 0 || 0x20 < uVar12)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar11 = *(int *)(DAT_0e096514 + 8);
  iVar8 = *DAT_0e096518;
  if (*DAT_0e096518 != iVar11) {
    bVar1 = *(byte *)(DAT_0e096514 + 0x10);
    *DAT_0e096518 = 0;
    if ((((*(char *)(iVar7 + (uint)bVar1) == '\0') || (0x7f < *(ushort *)(iVar11 + 0xe))) ||
        (*DAT_0e096520 == 0)) ||
       ((((int)*(char *)(iVar11 + 0xe) < *DAT_0e096524 || ((*(byte *)(iVar11 + 0xd) & 0x1f) != 0))
        || (iVar11 == DAT_0e096528)))) goto LAB_0e096508;
    FUN_0e095c80(iVar11);
    iVar8 = iVar11;
  }
  FUN_0e096440(iVar8);
LAB_0e096508:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar14);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


