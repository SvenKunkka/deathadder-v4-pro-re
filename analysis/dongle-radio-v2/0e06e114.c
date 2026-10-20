/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e114. Types and names are inferred; NOT original source. */

void FUN_0e06e114(undefined4 param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1ff;
    }
    if (uVar2 == 0) {
      if (*(int *)(DAT_0e06e134 + 0x14) != *(int *)(DAT_0e06e134 + 8)) {
        FUN_0e0612cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


