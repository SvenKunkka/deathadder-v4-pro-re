/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cc78. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cc78(int param_1,undefined4 param_2,int param_3,int param_4)

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
  if ((bVar5) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(uint *)(param_1 + 0x20) < *(uint *)(param_1 + 0xc)) {
    iVar3 = FUN_0e06e00c();
    if (iVar3 != 0) {
      FUN_0e06f3f8(*(undefined4 *)(iVar3 + 0x14),param_2,*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      FUN_0e06ddc0(iVar3);
      FUN_0e06e114(param_1 + 8,uVar4);
      return 0;
    }
    FUN_0e06f3f8(*(undefined4 *)(param_1 + 0x1c),param_2,*(undefined4 *)(param_1 + 8));
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
      *(undefined4 *)(*(int *)(DAT_0e06cd2c + 8) + 0x14) = param_2;
      uVar4 = FUN_0e06df64(param_1 + 8,uVar4,param_1,param_4,param_3,param_4);
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


