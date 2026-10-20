/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a75c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302a75c(int *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (param_2 == 1) {
    piVar6 = &DAT_23006d68;
  }
  else {
    if (param_2 != 0x10) {
      return;
    }
    piVar6 = &DAT_23006d60;
  }
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
  piVar3 = (int *)*piVar6;
  if (piVar3 == (int *)0x0) {
LAB_2302a78c:
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  else {
    if (param_1 == piVar3) {
      iVar5 = *param_1;
      *piVar6 = iVar5;
      if (param_1 == (int *)piVar6[1]) {
        piVar6[1] = iVar5;
      }
    }
    else {
      do {
        piVar4 = piVar3;
        piVar3 = (int *)*piVar4;
        if (piVar3 == (int *)0x0) goto LAB_2302a78c;
      } while (param_1 != piVar3);
      *piVar4 = *param_1;
      if (param_1 == (int *)piVar6[1]) {
        piVar6[1] = (int)piVar4;
      }
    }
    iVar5 = 0;
    *param_1 = 0;
    piVar6 = (int *)*piVar6;
    if (piVar6 != (int *)0x0) {
      do {
        piVar6 = (int *)*piVar6;
        iVar5 = iVar5 + 1;
      } while (piVar6 != (int *)0x0);
      DAT_23006d5c = (int *)0x0;
      piVar6 = (int *)0x0;
      if (iVar5 != 0) goto LAB_2302a78c;
    }
    DAT_23006d5c = piVar6;
    _DAT_5301e490 = _DAT_5301e490 & ~param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


