/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e71d2. Types and names are inferred; NOT original source. */

void FUN_0e0e71d2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  
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
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0e0e7150(param_1,uVar3,0x20,*(int *)(param_1 + 8),param_4);
    uVar3 = extraout_r1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


