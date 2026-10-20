/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089d4c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e089d4c(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = DAT_23007654;
  *(undefined4 *)(DAT_23007654 + 0x88) = param_1;
  *(undefined4 *)(iVar2 + 0x8c) = 0xfffffff5;
  _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)(DAT_23007654 + 0x8c);
}


