/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061130. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061130(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts(0);
  }
  uVar2 = 0;
  if ((_DAT_e000ed90 & 0xff00) != 0) {
    do {
      _DAT_e000ed98 = uVar2;
      _DAT_e000eda0 = 0;
      uVar2 = _DAT_e000ed98 + 1;
    } while ((_DAT_e000ed90 & 0xffff) >> 8 != _DAT_e000ed98 + 1);
  }
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 0x20;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar3 * 4 + -0x1fff1f00) = 0xffffffff;
  } while (iVar4 != 0x10);
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 0x60;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar3 * 4 + -0x1fff1f00) = 0xffffffff;
  } while (iVar4 != 0x10);
  enableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


