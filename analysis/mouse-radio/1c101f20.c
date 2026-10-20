/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c101f20. Types and names are inferred; NOT original source. */

undefined4 FUN_1c101f20(int *param_1,char param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar9 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0) || (param_1[6] != 0)) {
    *(char *)((int)param_1 + 0xe) = param_2;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x7f;
  iVar4 = DAT_1c101fcc;
  piVar6 = (int *)param_1[1];
  iVar7 = *param_1;
  *piVar6 = iVar7;
  *(int **)(iVar7 + 4) = piVar6;
  *param_1 = 0;
  param_1[1] = 0;
  *(char *)((int)param_1 + 0xe) = param_2;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  puVar1 = (undefined4 *)(iVar4 + 0x1c);
  puVar8 = (undefined4 *)*puVar1;
  puVar5 = *(undefined4 **)(iVar4 + 0x20);
  if (puVar8 == puVar1) {
    puVar8 = (undefined4 *)0x0;
  }
  for (; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
    if ((param_2 != *(char *)((int)puVar8 + 0xe)) && (param_2 < *(char *)((int)puVar8 + 0xe))) {
      puVar5 = (undefined4 *)puVar8[1];
      *param_1 = (int)puVar8;
      param_1[1] = (int)puVar5;
      *puVar5 = param_1;
      puVar8[1] = param_1;
      goto LAB_1c101f9a;
    }
    if (puVar8 == puVar5) break;
  }
  *param_1 = (int)puVar1;
  param_1[1] = (int)puVar5;
  *puVar5 = param_1;
  *(int **)(iVar4 + 0x20) = param_1;
LAB_1c101f9a:
  puVar5 = *(undefined4 **)(iVar4 + 0x1c);
  if ((puVar5 == puVar1) || (puVar5 == (undefined4 *)0x0)) {
    puVar5 = *(undefined4 **)(iVar4 + 0xc);
  }
  if (puVar5 != *(undefined4 **)(iVar4 + 8)) {
    FUN_1c102440(puVar5);
  }
  *(undefined4 **)(iVar4 + 0x18) = puVar5;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}


