/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0685dc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0685dc(void)

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
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0696e0(local_10);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return local_10[0];
}


