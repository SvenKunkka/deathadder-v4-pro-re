/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0affac. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0affac(void)

{
  bool bVar1;
  uint uVar2;
  int extraout_r1;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  *(byte *)(_DAT_2f011ba0 + 0xd) = *(byte *)(_DAT_2f011ba0 + 0xd) & 0x7f;
  FUN_0e0b2458();
  piVar5 = *(int **)(extraout_r1 + 8);
  *(byte *)((int)piVar5 + 0xd) = *(byte *)((int)piVar5 + 0xd) | 0x80;
  puVar3 = (undefined4 *)(extraout_r1 + 0x1c);
  puVar4 = (undefined4 *)*puVar3;
  puVar6 = *(undefined4 **)(extraout_r1 + 0x20);
  if (puVar4 == puVar3) {
    puVar4 = (undefined4 *)0x0;
  }
  for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    if ((*(char *)((int)piVar5 + 0xe) != *(char *)((int)puVar4 + 0xe)) &&
       (*(char *)((int)piVar5 + 0xe) < *(char *)((int)puVar4 + 0xe))) {
      puVar3 = (undefined4 *)puVar4[1];
      *piVar5 = (int)puVar4;
      piVar5[1] = (int)puVar3;
      *puVar3 = piVar5;
      puVar4[1] = piVar5;
      goto LAB_0e0b000a;
    }
    if (puVar4 == puVar6) break;
  }
  *piVar5 = (int)puVar3;
  piVar5[1] = (int)puVar6;
  *puVar6 = piVar5;
  *(int **)(extraout_r1 + 0x20) = piVar5;
LAB_0e0b000a:
  FUN_0e0afba8(1);
  FUN_0e0aca34(uVar7);
  return;
}


