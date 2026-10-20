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
    ram_candidate_23020bec();
    ram_candidate_23020b9c();
    _DAT_53012500 = _DAT_53012500 & 0xffffff7f;
    ram_candidate_23020cdc();
    _DAT_53012500 = _DAT_53012500 & 0xffffffbf;
    thunk_FUN_2302a75c(&DAT_23006d54,0x10);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
    WaitForInterrupt();
    _DAT_53012500 = _DAT_53012500 | 0x40;
    ram_candidate_23020cec();
    _DAT_53012500 = _DAT_53012500 | 0x80;
    ram_candidate_23020bdc();
    thunk_FUN_2302a7fc(&DAT_23006d54,0x10);
    enableIRQinterrupts();
    return;
  }
  enableIRQinterrupts();
  return;
}


