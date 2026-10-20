/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096628. Types and names are inferred; NOT original source. */

uint FUN_0e096628(void)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  puVar2 = DAT_230014f4;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((undefined4 **)DAT_230014f4 == &DAT_230014f4) {
    if (DAT_23007680 == 0) {
      thunk_FUN_23028b70();
    }
  }
  else {
    if (DAT_23007680 == 0) {
      uVar3 = thunk_FUN_23028b70();
    }
    else {
      uVar3 = 0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar5 = puVar2[4] - uVar3;
      iVar4 = (puVar2[5] - ((int)uVar3 >> 0x1f)) - (uint)((uint)puVar2[4] < uVar3);
      if (iVar4 < (int)(uint)(uVar5 < 0x80000000)) {
        if (iVar4 < 0) {
          uVar5 = 0;
        }
        goto LAB_0e096666;
      }
    }
  }
  uVar5 = 0x7fffffff;
LAB_0e096666:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar5;
}


