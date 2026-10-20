/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060e10. Types and names are inferred; NOT original source. */

void FUN_0e060e10(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 1) {
    param_4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      param_4 = getCurrentExceptionNumber();
      param_4 = param_4 & 0x1ff;
    }
  }
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(undefined4 *)(DAT_0e06c7b8 + 8);
  FUN_0e06c784();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e061298(uVar3,extraout_r1,extraout_r2,param_4);
  return;
}


