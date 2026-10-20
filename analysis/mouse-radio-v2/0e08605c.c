/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08605c. Types and names are inferred; NOT original source. */

void FUN_0e08605c(void)

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
  FUN_0e089e18();
  FUN_0e085ff8(DAT_0e08607c);
  do {
    FUN_0e08a134();
  } while( true );
}


