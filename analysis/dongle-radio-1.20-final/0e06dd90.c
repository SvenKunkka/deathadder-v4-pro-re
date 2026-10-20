/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dd90. Types and names are inferred; NOT original source. */

void FUN_0e06dd90(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  FUN_0e06e768(param_1 + 0x18);
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
  if ((*(byte *)(param_1 + 0xd) & 0x10) == 0) {
    FUN_0e06db60(param_1,uVar3);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


