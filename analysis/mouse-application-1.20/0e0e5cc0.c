/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5cc0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e5cc0(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int extraout_r1;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  *(byte *)(_DAT_2f0118dc + 0xd) = *(byte *)(_DAT_2f0118dc + 0xd) & 0x7f;
  FUN_0e0e7140();
  piVar6 = *(int **)(extraout_r1 + 8);
  *(byte *)((int)piVar6 + 0xd) = *(byte *)((int)piVar6 + 0xd) | 0x80;
  puVar4 = (undefined4 *)(extraout_r1 + 0x1c);
  puVar5 = (undefined4 *)*puVar4;
  puVar7 = *(undefined4 **)(extraout_r1 + 0x20);
  if (puVar5 == puVar4) {
    puVar5 = (undefined4 *)0x0;
  }
  for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
    if ((*(char *)((int)piVar6 + 0xe) != *(char *)((int)puVar5 + 0xe)) &&
       (*(char *)((int)piVar6 + 0xe) < *(char *)((int)puVar5 + 0xe))) {
      puVar4 = (undefined4 *)puVar5[1];
      *piVar6 = (int)puVar5;
      piVar6[1] = (int)puVar4;
      *puVar4 = piVar6;
      puVar5[1] = piVar6;
      goto LAB_0e0e3400;
    }
    if (puVar5 == puVar7) break;
  }
  *piVar6 = (int)puVar4;
  piVar6[1] = (int)puVar7;
  *puVar7 = piVar6;
  *(int **)(extraout_r1 + 0x20) = piVar6;
LAB_0e0e3400:
  FUN_0e0e58bc(1);
  iVar3 = _DAT_2f0118dc;
  *(undefined4 *)(_DAT_2f0118dc + 0x88) = 0xfffffff5;
  *(undefined4 *)(iVar3 + 0x84) = uVar8;
  _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)(_DAT_2f0118dc + 0x88);
}


