/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0abb20. Types and names are inferred; NOT original source. */

void FUN_0e0abb20(void)

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
  FUN_0e0ac974();
  FUN_0e0b0c28("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e0b1d38();
  } while( true );
}


