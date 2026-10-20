/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c1026bc. Types and names are inferred; NOT original source. */

undefined4 FUN_1c1026bc(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  
  piVar2 = DAT_1c102748;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*param_1 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xffffffea;
  }
  piVar8 = (int *)*DAT_1c102748;
  if (piVar8 == DAT_1c102748) {
    FUN_1c102564();
    goto LAB_1c1026e2;
  }
  piVar3 = (int *)FUN_1c102564();
  if (piVar3 != piVar8) goto LAB_1c1026e2;
  piVar8 = (int *)*piVar2;
  if (piVar8 == piVar2) {
    if (*DAT_1c10274c == 0) {
      FUN_1c103738();
    }
LAB_1c10273c:
    uVar6 = 0x7fffffff;
  }
  else {
    if (*DAT_1c10274c == 0) {
      uVar4 = FUN_1c103738();
    }
    else {
      uVar4 = 0;
    }
    if (piVar8 == (int *)0x0) goto LAB_1c10273c;
    uVar6 = piVar8[4] - uVar4;
    iVar5 = (piVar8[5] - ((int)uVar4 >> 0x1f)) - (uint)((uint)piVar8[4] < uVar4);
    if ((int)(uint)(uVar6 < 0x80000000) <= iVar5) goto LAB_1c10273c;
    if (iVar5 < 0) {
      uVar6 = 0;
    }
  }
  FUN_1c103648(uVar6,0);
LAB_1c1026e2:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


