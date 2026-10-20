/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a8e4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e08a8e4(int param_1,uint param_2)

{
  bool bVar1;
  
  if (param_1 != 2) {
    FUN_0e089fa8();
    return;
  }
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
    FUN_0e097628();
    FUN_0e097608();
    _DAT_53012500 = _DAT_53012500 & 0xffffff7f;
    FUN_0e097610();
    _DAT_53012500 = _DAT_53012500 & 0xffffffbf;
    FUN_0e0975f0(&DAT_23006d54,0x10);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
    WaitForInterrupt();
    _DAT_53012500 = _DAT_53012500 | 0x40;
    FUN_0e097638();
    _DAT_53012500 = _DAT_53012500 | 0x80;
    FUN_0e097688();
    FUN_0e097670(&DAT_23006d54,0x10);
    enableIRQinterrupts();
    return;
  }
  enableIRQinterrupts();
  return;
}


