/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028b00. Types and names are inferred; NOT original source. */

undefined4 FUN_23028b00(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_10 [2];
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_23029b84(local_10);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return local_10[0];
}


