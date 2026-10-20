/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d698. Types and names are inferred; NOT original source. */

void FUN_0e05d698(void)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06110c();
  FUN_0e05d634("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e061410();
  } while( true );
}


