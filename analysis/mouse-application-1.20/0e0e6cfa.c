/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6cfa. Types and names are inferred; NOT original source. */

void FUN_0e0e6cfa(void)

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


