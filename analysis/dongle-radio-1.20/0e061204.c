/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061204. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061204(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23007170 = DAT_2300717c;
  _DAT_e000ed04 = 0x8000000;
  DAT_23006930 = *(undefined4 *)(DAT_2300717c + 0x84);
  uVar3 = *(undefined4 *)(DAT_2300717c + 0x88);
  *(undefined4 *)(DAT_2300717c + 0x88) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


