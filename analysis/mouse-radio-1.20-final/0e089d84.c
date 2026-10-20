/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089d84. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e089d84(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23007654 = DAT_23007664;
  _DAT_e000ed04 = 0x8000000;
  DAT_23006d30 = *(undefined4 *)(DAT_23007664 + 0x84);
  uVar3 = *(undefined4 *)(DAT_23007664 + 0x88);
  *(undefined4 *)(DAT_23007664 + 0x88) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


