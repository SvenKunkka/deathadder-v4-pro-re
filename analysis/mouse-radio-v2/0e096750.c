/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096750. Types and names are inferred; NOT original source. */

uint FUN_0e096750(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
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
  piVar5 = (int *)*DAT_0e0967ac;
  if (piVar5 == DAT_0e0967ac) {
    if (*DAT_0e0967b0 == 0) {
      FUN_0e097738();
    }
  }
  else {
    if (*DAT_0e0967b0 == 0) {
      uVar2 = FUN_0e097738();
    }
    else {
      uVar2 = 0;
    }
    if (piVar5 != (int *)0x0) {
      uVar4 = piVar5[4] - uVar2;
      iVar3 = (piVar5[5] - ((int)uVar2 >> 0x1f)) - (uint)((uint)piVar5[4] < uVar2);
      if (iVar3 < (int)(uint)(uVar4 < 0x80000000)) {
        if (iVar3 < 0) {
          uVar4 = 0;
        }
        goto LAB_0e09678e;
      }
    }
  }
  uVar4 = 0x7fffffff;
LAB_0e09678e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar4;
}


