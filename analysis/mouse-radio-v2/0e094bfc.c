/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094bfc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e094bfc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  uVar4 = 0;
  bVar5 = (bool)isCurrentModePrivileged();
  if (bVar5) {
    uVar4 = getBasePriority();
  }
  bVar5 = (bool)isCurrentModePrivileged();
  if ((bVar5) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(uint *)(param_1 + 0x20) < *(uint *)(param_1 + 0xc)) {
    iVar3 = FUN_0e095ec8();
    if (iVar3 != 0) {
      FUN_0e0974c4(*(undefined4 *)(iVar3 + 0x14),param_2,*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      FUN_0e095cfc(iVar3);
      FUN_0e095fd0(param_1 + 8,uVar4);
      return 0;
    }
    FUN_0e0974c4(*(undefined4 *)(param_1 + 0x1c),param_2,*(undefined4 *)(param_1 + 8));
    iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
    bVar5 = iVar3 == *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x1c) = iVar3;
    if (bVar5) {
      iVar3 = *(int *)(param_1 + 0x10);
    }
    uVar2 = 0;
    if (bVar5) {
      *(int *)(param_1 + 0x1c) = iVar3;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  else {
    if (param_3 != 0 || param_4 != 0) {
      *(undefined4 *)(*(int *)(DAT_0e094cb0 + 8) + 0x14) = param_2;
      uVar4 = FUN_0e095e20(param_1 + 8,uVar4,param_1,param_4,param_3,param_4);
      return uVar4;
    }
    uVar2 = 0xffffffdd;
  }
  bVar5 = (bool)isCurrentModePrivileged();
  if (bVar5) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar2;
}


