/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6e8. Types and names are inferred; NOT original source. */

void FUN_0e06c6e8(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  undefined4 extraout_r3;
  undefined4 uVar4;
  
  FUN_0e06c6d8();
  uVar3 = DAT_23007170;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06c6e8();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e061198(uVar3,extraout_r1,extraout_r2,extraout_r3,in_r3);
  return;
}


