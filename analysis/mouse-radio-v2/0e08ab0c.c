/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ab0c. Types and names are inferred; NOT original source. */

void FUN_0e08ab0c(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


