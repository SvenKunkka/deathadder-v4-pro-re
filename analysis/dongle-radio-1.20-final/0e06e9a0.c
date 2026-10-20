/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e9a0. Types and names are inferred; NOT original source. */

undefined8 FUN_0e06e9a0(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
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
  if (DAT_23007198 == 0) {
    uVar2 = FUN_0e068568();
    iVar3 = (int)uVar2 >> 0x1f;
  }
  else {
    uVar2 = 0;
    iVar3 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(iVar3 + DAT_23002c7c + (uint)CARRY4(uVar2,DAT_23002c78),uVar2 + DAT_23002c78);
}


