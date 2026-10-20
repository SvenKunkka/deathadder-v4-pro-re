/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cf44. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cf44(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
    return 0xffffffea;
  }
  if (*(int *)(param_1 + 8) != *(int *)(DAT_0e06cfc0 + 8)) {
    return 0xffffffff;
  }
  if (*(uint *)(param_1 + 0xc) < 2) {
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
    if (*(int *)(param_1 + 0x10) != (int)*(char *)(*(int *)(param_1 + 8) + 0xe)) {
      FUN_0e06e064();
    }
    iVar3 = FUN_0e06e00c(param_1);
    *(int *)(param_1 + 8) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      *(int *)(param_1 + 0x10) = (int)*(char *)(iVar3 + 0xe);
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      FUN_0e06ddc0();
      FUN_0e06e114(DAT_0e06cfc4,uVar4);
    }
  }
  else {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) - 1;
  }
  return 0;
}


