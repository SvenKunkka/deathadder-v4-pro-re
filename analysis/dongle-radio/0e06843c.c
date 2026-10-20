/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06843c. Types and names are inferred; NOT original source. */

void FUN_0e06843c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  byte bVar1;
  bool bVar2;
  uint *puVar3;
  int *piVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  undefined4 uVar14;
  uint in_stack_ffffffe8;
  uint in_stack_ffffffec;
  
  FUN_0e0696e0(&stack0xffffffe8);
  puVar3 = DAT_0e06846c;
  if (in_stack_ffffffec <= param_4 &&
      (uint)(param_3 <= in_stack_ffffffe8) <= in_stack_ffffffec - param_4) {
    return;
  }
  uVar6 = *DAT_0e06846c;
  DAT_0e06846c[1] = param_4;
  uVar6 = param_3 - uVar6;
  *puVar3 = param_3;
  puVar3 = DAT_0e06e9bc;
  piVar4 = DAT_0e06e9b8;
  uVar14 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar14 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar12 = getBasePriority(), uVar12 == 0 || 0x40 < uVar12)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  *DAT_0e06e9bc = uVar6;
  puVar5 = DAT_0e06e9c0;
  piVar7 = (int *)*piVar4;
  if (piVar7 == piVar4) {
LAB_0e06e984:
    uVar12 = *puVar5;
    *puVar3 = 0;
    *puVar5 = uVar12 + uVar6;
    puVar5[1] = puVar5[1] + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar12,uVar6);
LAB_0e06e998:
    FUN_0e068604();
LAB_0e06e99c:
    uVar12 = 0x7fffffff;
  }
  else {
    if (piVar7 == (int *)0x0) {
      *puVar3 = 0;
      uVar12 = *puVar5;
      *puVar5 = uVar12 + uVar6;
      puVar5[1] = puVar5[1] + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar12,uVar6);
      goto LAB_0e06e998;
    }
    do {
      uVar12 = piVar7[4];
      iVar9 = piVar7[5];
      iVar8 = (int)uVar6 >> 0x1f;
      if ((int)((iVar8 - iVar9) - (uint)(uVar6 < uVar12)) < 0 !=
          (SBORROW4(iVar8,iVar9) != SBORROW4(iVar8 - iVar9,(uint)(uVar6 < uVar12)))) {
        piVar7[4] = uVar12 - uVar6;
        piVar13 = (int *)*piVar4;
        piVar7[5] = (iVar9 - iVar8) - (uint)(uVar12 < uVar6);
        goto LAB_0e06e932;
      }
      uVar10 = *puVar5;
      uVar6 = puVar5[1];
      piVar7[4] = 0;
      piVar7[5] = 0;
      *puVar5 = uVar10 + uVar12;
      puVar5[1] = uVar6 + ((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar10,uVar12);
      iVar8 = FUN_0e06e6ac();
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar14);
      }
      InstructionSynchronizationBarrier(0xf);
      (**(code **)(iVar8 + 8))();
      uVar14 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar14 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      piVar7 = (int *)*piVar4;
      uVar6 = *puVar3 - uVar12;
      *puVar3 = uVar6;
      if (piVar7 == piVar4) goto LAB_0e06e984;
    } while (piVar7 != (int *)0x0);
    iVar8 = (int)uVar6 >> 0x1f;
    piVar13 = (int *)0x0;
LAB_0e06e932:
    *puVar3 = 0;
    uVar12 = *puVar5;
    *puVar5 = uVar12 + uVar6;
    puVar5[1] = puVar5[1] + iVar8 + (uint)CARRY4(uVar12,uVar6);
    if (piVar13 == piVar4) goto LAB_0e06e998;
    uVar6 = FUN_0e068604();
    if (piVar13 == (int *)0x0) goto LAB_0e06e99c;
    uVar12 = piVar13[4] - uVar6;
    iVar8 = (piVar13[5] - ((int)uVar6 >> 0x1f)) - (uint)((uint)piVar13[4] < uVar6);
    if ((int)(uint)(uVar12 < 0x80000000) <= iVar8) goto LAB_0e06e99c;
    if (iVar8 < 0) {
      uVar12 = 0;
    }
  }
  FUN_0e068620(uVar12,0);
  iVar8 = DAT_0e06e664;
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
  if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar11 = *(int *)(DAT_0e06e65c + 8);
  iVar9 = *DAT_0e06e660;
  if (*DAT_0e06e660 != iVar11) {
    bVar1 = *(byte *)(DAT_0e06e65c + 0x10);
    *DAT_0e06e660 = 0;
    if ((((*(char *)(iVar8 + (uint)bVar1) == '\0') || (0x7f < *(ushort *)(iVar11 + 0xe))) ||
        (*DAT_0e06e668 == 0)) ||
       ((((int)*(char *)(iVar11 + 0xe) < *DAT_0e06e66c || ((*(byte *)(iVar11 + 0xd) & 0x1f) != 0))
        || (iVar11 == DAT_0e06e670)))) goto LAB_0e06e650;
    FUN_0e06dd44(iVar11);
    iVar9 = iVar11;
  }
  FUN_0e06e588(iVar9);
LAB_0e06e650:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar14);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


