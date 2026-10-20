/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e09c. Types and names are inferred; NOT original source. */

void FUN_0e06e09c(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1ff;
    }
    if (uVar2 == 0) {
      if (DAT_2300717c != DAT_23007170) {
        FUN_0e0611cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


