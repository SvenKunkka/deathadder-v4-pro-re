/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09600c. Types and names are inferred; NOT original source. */

void FUN_0e09600c(void)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  
  piVar6 = DAT_23007654;
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
  piVar3 = (int *)DAT_23007654[1];
  *(byte *)((int)DAT_23007654 + 0xd) = *(byte *)((int)DAT_23007654 + 0xd) & 0x7f;
  iVar4 = *piVar6;
  *piVar3 = iVar4;
  *(int **)(iVar4 + 4) = piVar3;
  *piVar6 = 0;
  piVar6[1] = 0;
  piVar3 = DAT_23007654;
  *(byte *)((int)DAT_23007654 + 0xd) = *(byte *)((int)DAT_23007654 + 0xd) | 0x80;
  piVar6 = DAT_23007668;
  if ((int **)DAT_23007668 == &DAT_23007668) {
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
      goto LAB_0e096072;
    }
    if (piVar6 == DAT_2300766c) break;
  }
  *piVar3 = (int)&DAT_23007668;
  piVar3[1] = (int)DAT_2300766c;
  *DAT_2300766c = (int)piVar3;
  DAT_2300766c = piVar3;
LAB_0e096072:
  if (((int **)DAT_23007668 == &DAT_23007668) || (piVar6 = DAT_23007668, DAT_23007668 == (int *)0x0)
     ) {
    piVar6 = DAT_23007658;
  }
  if (piVar6 != DAT_23007654) {
    FUN_0e096318(piVar6);
  }
  DAT_23007664 = piVar6;
  FUN_0e089d4c(uVar7);
  return;
}


