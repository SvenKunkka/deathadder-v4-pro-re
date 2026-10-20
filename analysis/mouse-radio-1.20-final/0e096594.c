/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096594. Types and names are inferred; NOT original source. */

undefined4 FUN_0e096594(int *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  puVar2 = DAT_230014f4;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*param_1 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xffffffea;
  }
  if ((undefined4 **)DAT_230014f4 == &DAT_230014f4) {
    FUN_0e09643c();
    goto LAB_0e0965ba;
  }
  puVar4 = (undefined4 *)FUN_0e09643c();
  puVar3 = DAT_230014f4;
  if (puVar4 != puVar2) goto LAB_0e0965ba;
  if ((undefined4 **)DAT_230014f4 == &DAT_230014f4) {
    if (DAT_23007680 == 0) {
      thunk_FUN_23028b70();
    }
LAB_0e096614:
    uVar7 = 0x7fffffff;
  }
  else {
    if (DAT_23007680 == 0) {
      uVar5 = thunk_FUN_23028b70();
    }
    else {
      uVar5 = 0;
    }
    if (puVar3 == (undefined4 *)0x0) goto LAB_0e096614;
    uVar7 = puVar3[4] - uVar5;
    iVar6 = (puVar3[5] - ((int)uVar5 >> 0x1f)) - (uint)((uint)puVar3[4] < uVar5);
    if ((int)(uint)(uVar7 < 0x80000000) <= iVar6) goto LAB_0e096614;
    if (iVar6 < 0) {
      uVar7 = 0;
    }
  }
  thunk_FUN_23028b9c(uVar7,0);
LAB_0e0965ba:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


