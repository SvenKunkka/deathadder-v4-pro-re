/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c101ff4. Types and names are inferred; NOT original source. */

void FUN_1c101ff4(int param_1)

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
      if (*(int *)(DAT_1c102018 + 0x18) != *(int *)(DAT_1c102018 + 8)) {
        FUN_1c0f5ed8();
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


