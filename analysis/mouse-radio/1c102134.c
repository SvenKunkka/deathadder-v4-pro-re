/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c102134. Types and names are inferred; NOT original source. */

void FUN_1c102134(void)

{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  
  iVar4 = DAT_1c1021cc;
  uVar10 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar10 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar7 = *(int **)(DAT_1c1021cc + 8);
  piVar5 = (int *)piVar7[1];
  *(byte *)((int)piVar7 + 0xd) = *(byte *)((int)piVar7 + 0xd) & 0x7f;
  iVar6 = *piVar7;
  *piVar5 = iVar6;
  *(int **)(iVar6 + 4) = piVar5;
  *piVar7 = 0;
  piVar7[1] = 0;
  piVar5 = *(int **)(iVar4 + 8);
  *(byte *)((int)piVar5 + 0xd) = *(byte *)((int)piVar5 + 0xd) | 0x80;
  puVar1 = (undefined4 *)(iVar4 + 0x1c);
  puVar8 = (undefined4 *)*puVar1;
  puVar9 = *(undefined4 **)(iVar4 + 0x20);
  if (puVar8 == puVar1) {
    puVar8 = (undefined4 *)0x0;
  }
  for (; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
    if ((*(char *)((int)piVar5 + 0xe) != *(char *)((int)puVar8 + 0xe)) &&
       (*(char *)((int)piVar5 + 0xe) < *(char *)((int)puVar8 + 0xe))) {
      puVar9 = (undefined4 *)puVar8[1];
      *piVar5 = (int)puVar8;
      piVar5[1] = (int)puVar9;
      *puVar9 = piVar5;
      puVar8[1] = piVar5;
      goto LAB_1c10219a;
    }
    if (puVar8 == puVar9) break;
  }
  *piVar5 = (int)puVar1;
  piVar5[1] = (int)puVar9;
  *puVar9 = piVar5;
  *(int **)(iVar4 + 0x20) = piVar5;
LAB_1c10219a:
  iVar6 = *(int *)(iVar4 + 0x1c);
  if (((undefined4 *)iVar6 == puVar1) || (iVar6 == 0)) {
    iVar6 = *(int *)(iVar4 + 0xc);
  }
  if (iVar6 != *(int *)(iVar4 + 8)) {
    FUN_1c102440(iVar6);
  }
  *(int *)(iVar4 + 0x18) = iVar6;
  FUN_1c0f5ed8(uVar10);
  return;
}


