/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06caf4. Types and names are inferred; NOT original source. */

void FUN_0e06caf4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  
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
  FUN_0e05d560();
  iVar3 = FUN_0e06e1e4(param_1 + 0xc);
  if (iVar3 != 0) {
    FUN_0e06e114(param_1 + 0x14,uVar4,extraout_r2,param_4);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


