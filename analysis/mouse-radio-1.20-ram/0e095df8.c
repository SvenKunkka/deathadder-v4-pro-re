/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095df8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e095df8(int *param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
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
  if (((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0) || (param_1[6] != 0)) {
    *(char *)((int)param_1 + 0xe) = param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x7f;
  piVar3 = (int *)param_1[1];
  iVar5 = *param_1;
  *piVar3 = iVar5;
  *(int **)(iVar5 + 4) = piVar3;
  *param_1 = 0;
  param_1[1] = 0;
  *(char *)((int)param_1 + 0xe) = param_2;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  piVar3 = DAT_23007668;
  if ((int **)DAT_23007668 == &DAT_23007668) {
    piVar3 = (int *)0x0;
  }
  for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    if ((param_2 != *(char *)((int)piVar3 + 0xe)) && (param_2 < *(char *)((int)piVar3 + 0xe))) {
      puVar4 = (undefined4 *)piVar3[1];
      *param_1 = (int)piVar3;
      param_1[1] = (int)puVar4;
      *puVar4 = param_1;
      piVar3[1] = (int)param_1;
      goto LAB_0e095e72;
    }
    if (piVar3 == DAT_2300766c) break;
  }
  *param_1 = (int)&DAT_23007668;
  param_1[1] = (int)DAT_2300766c;
  *DAT_2300766c = (int)param_1;
  DAT_2300766c = param_1;
LAB_0e095e72:
  if (((int **)DAT_23007668 == &DAT_23007668) || (piVar3 = DAT_23007668, DAT_23007668 == (int *)0x0)
     ) {
    piVar3 = DAT_23007658;
  }
  if (piVar3 != DAT_23007654) {
    FUN_0e096318(piVar3);
  }
  DAT_23007664 = piVar3;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}


