/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085ed0. Types and names are inferred; NOT original source. */

void FUN_0e085ed0(void)

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
  FUN_0e089c8c();
  FUN_0e085e6c("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e089fa8();
  } while( true );
}


