/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6cba. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e6cba(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 uVar4;
  
  uVar3 = _DAT_2f0118dc;
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
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0e6f34();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0e33d4(uVar3,extraout_r1,extraout_r2,param_4);
  return;
}


