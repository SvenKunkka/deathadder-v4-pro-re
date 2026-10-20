/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c100cb4. Types and names are inferred; NOT original source. */

undefined4 FUN_1c100cb4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(int *)(param_1 + 0x20) == 0) {
    if (param_3 != 0 || param_4 != 0) {
      *(undefined4 *)(*(int *)(DAT_1c100d70 + 8) + 0x14) = param_2;
      uVar6 = FUN_1c101e20(param_1 + 8,uVar6,param_1,param_4,param_3,param_4);
      return uVar6;
    }
    uVar3 = 0xffffffdd;
  }
  else {
    FUN_1c1034c4(param_2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 8));
    iVar4 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8);
    *(int *)(param_1 + 0x18) = iVar4;
    if (iVar4 == *(int *)(param_1 + 0x14)) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    iVar4 = FUN_1c101ec8(param_1);
    uVar3 = 0;
    if (iVar4 != 0) {
      FUN_1c1034c4(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(iVar4 + 0x14),
                   *(undefined4 *)(param_1 + 8));
      iVar5 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
      *(int *)(param_1 + 0x1c) = iVar5;
      if (iVar5 == *(int *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      *(undefined4 *)(iVar4 + 0x8c) = 0;
      FUN_1c101cfc(iVar4);
      FUN_1c101fd0(param_1 + 8,uVar6);
      return 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


