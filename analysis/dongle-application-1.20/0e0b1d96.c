/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1d96. Types and names are inferred; NOT original source. */

void FUN_0e0b1d96(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


