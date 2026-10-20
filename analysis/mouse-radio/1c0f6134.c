/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f6134. Types and names are inferred; NOT original source. */

void FUN_1c0f6134(void)

{
  bool bVar1;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  WaitForInterrupt();
  enableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  return;
}


