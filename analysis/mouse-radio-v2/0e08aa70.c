/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08aa70. Types and names are inferred; NOT original source. */

void FUN_0e08aa70(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = DAT_0e08ab04;
  if (param_1 != 2) {
    FUN_0e08a134();
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
    FUN_0e097760();
    FUN_0e097768();
    *(uint *)(iVar2 + 0x500) = *(uint *)(iVar2 + 0x500) & 0xffffff7f;
    FUN_0e097620();
    *(uint *)(iVar2 + 0x500) = *(uint *)(iVar2 + 0x500) & 0xffffffbf;
    FUN_0e0976d0(DAT_0e08ab08,0x10);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
    WaitForInterrupt();
    *(uint *)(iVar2 + 0x500) = *(uint *)(iVar2 + 0x500) | 0x40;
    FUN_0e097688();
    *(uint *)(iVar2 + 0x500) = *(uint *)(iVar2 + 0x500) | 0x80;
    FUN_0e0976e0();
    FUN_0e097650(DAT_0e08ab08,0x10);
    enableIRQinterrupts();
    return;
  }
  enableIRQinterrupts();
  return;
}


