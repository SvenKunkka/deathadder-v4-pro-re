/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ad218. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0ad218(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  
  if (param_1 == 2) {
    disableIRQinterrupts();
    if (param_2 < 2) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0);
      }
      InstructionSynchronizationBarrier(0xf);
      DataSynchronizationBarrier(0xf);
      WaitForInterrupt();
    }
    else if (param_2 == 2) {
      FUN_0e0ad7c4(0x2f0119ec,1,param_3,param_4,param_4);
      FUN_0e0ad168();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0);
      }
      InstructionSynchronizationBarrier(0xf);
      DataSynchronizationBarrier(0xf);
      WaitForInterrupt();
      FUN_0e0ad1e0();
      FUN_0e0ad844(0x2f0119ec,1);
    }
  }
  else {
    if (param_1 != 4) {
      FUN_0e0b1d38();
      return;
    }
    disableIRQinterrupts();
    FUN_0e0ad29c(&LAB_0e0ad1a4_1);
    FUN_0e0ad1e0();
    _DAT_5201e494 = _DAT_5201e494 | 0x10;
  }
  enableIRQinterrupts();
  return;
}


