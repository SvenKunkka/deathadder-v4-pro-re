/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f205c. Types and names are inferred; NOT original source. */

void FUN_1c0f205c(void)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_1c0f5e18();
  FUN_1c0f1ff8(DAT_1c0f207c);
  do {
    FUN_1c0f6134();
  } while( true );
}


