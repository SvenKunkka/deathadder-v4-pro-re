/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095ea8. Types and names are inferred; NOT original source. */

void FUN_0e095ea8(undefined4 param_1,int param_2)

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
      if (DAT_23007664 != DAT_23007654) {
        FUN_0e089d4c();
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


