/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e804. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e804(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  
  piVar2 = DAT_0e06e890;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
    setBasePriority(0x40);
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
  piVar8 = (int *)*DAT_0e06e890;
  if (piVar8 == DAT_0e06e890) {
    FUN_0e06e6ac();
    goto LAB_0e06e82a;
  }
  piVar3 = (int *)FUN_0e06e6ac();
  if (piVar3 != piVar8) goto LAB_0e06e82a;
  piVar8 = (int *)*piVar2;
  if (piVar8 == piVar2) {
    if (*DAT_0e06e894 == 0) {
      FUN_0e068604();
    }
LAB_0e06e884:
    uVar6 = 0x7fffffff;
  }
  else {
    if (*DAT_0e06e894 == 0) {
      uVar4 = FUN_0e068604();
    }
    else {
      uVar4 = 0;
    }
    if (piVar8 == (int *)0x0) goto LAB_0e06e884;
    uVar6 = piVar8[4] - uVar4;
    iVar5 = (piVar8[5] - ((int)uVar4 >> 0x1f)) - (uint)((uint)piVar8[4] < uVar4);
    if ((int)(uint)(uVar6 < 0x80000000) <= iVar5) goto LAB_0e06e884;
    if (iVar5 < 0) {
      uVar6 = 0;
    }
  }
  FUN_0e068620(uVar6,0);
LAB_0e06e82a:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


