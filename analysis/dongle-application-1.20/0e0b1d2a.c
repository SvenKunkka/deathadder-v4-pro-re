/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1d2a. Types and names are inferred; NOT original source. */

void FUN_0e0b1d2a(undefined4 param_1)

{
  bool bVar1;
  
  enableFIQinterrupts();
  enableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


