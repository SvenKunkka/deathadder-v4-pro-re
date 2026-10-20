/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e2adc. Types and names are inferred; NOT original source. */

void FUN_0e0e2adc(void)

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
  FUN_0e0e3340();
  FUN_0e0e6878("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e0e6cfa();
  } while( true );
}


