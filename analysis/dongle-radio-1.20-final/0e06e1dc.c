/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e1dc. Types and names are inferred; NOT original source. */

void FUN_0e06e1dc(void)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  
  piVar6 = DAT_23007170;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar3 = (int *)DAT_23007170[1];
  *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) & 0x7f;
  iVar4 = *piVar6;
  *piVar3 = iVar4;
  *(int **)(iVar4 + 4) = piVar3;
  *piVar6 = 0;
  piVar6[1] = 0;
  piVar3 = DAT_23007170;
  *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) | 0x80;
  piVar6 = DAT_23007180;
  if ((int **)DAT_23007180 == &DAT_23007180) {
    piVar6 = (int *)0x0;
  }
  for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
    if ((*(char *)((int)piVar3 + 0xe) != *(char *)((int)piVar6 + 0xe)) &&
       (*(char *)((int)piVar3 + 0xe) < *(char *)((int)piVar6 + 0xe))) {
      puVar5 = (undefined4 *)piVar6[1];
      *piVar3 = (int)piVar6;
      piVar3[1] = (int)puVar5;
      *puVar5 = piVar3;
      piVar6[1] = (int)piVar3;
      goto LAB_0e06e242;
    }
    if (piVar6 == DAT_23007184) break;
  }
  *piVar3 = (int)&DAT_23007180;
  piVar3[1] = (int)DAT_23007184;
  *DAT_23007184 = (int)piVar3;
  DAT_23007184 = piVar3;
LAB_0e06e242:
  if (((int **)DAT_23007180 == &DAT_23007180) || (piVar6 = DAT_23007180, DAT_23007180 == (int *)0x0)
     ) {
    piVar6 = DAT_23007174;
  }
  if (piVar6 != DAT_23007170) {
    FUN_0e06e4ec(piVar6);
  }
  DAT_2300717c = piVar6;
  FUN_0e0611cc(uVar7);
  return;
}


