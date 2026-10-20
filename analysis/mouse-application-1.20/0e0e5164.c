/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5164. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e5164(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(uint *)(param_1 + 0x20) < *(uint *)(param_1 + 0xc)) {
    iVar3 = FUN_0e0e724a();
    if (iVar3 != 0) {
      FUN_0e0e74b6(*(undefined4 *)(iVar3 + 0x14),param_2,*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(iVar3 + 0x88) = 0;
      FUN_0e0e71b4(iVar3);
      FUN_0e0e5bc0(param_1 + 8,uVar5);
      return 0;
    }
    FUN_0e0e74b6(*(undefined4 *)(param_1 + 0x1c),param_2,*(undefined4 *)(param_1 + 8));
    uVar4 = 0;
    iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
    *(int *)(param_1 + 0x1c) = iVar3;
    if (iVar3 == *(int *)(param_1 + 0x14)) {
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  else {
    if (param_3 != 0 || param_4 != 0) {
      *(undefined4 *)(_DAT_2f0118dc + 0x14) = param_2;
      uVar5 = FUN_0e0e5ae0(param_1 + 8,uVar5,param_1,param_4,param_3,param_4);
      return uVar5;
    }
    uVar4 = 0xffffffdd;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar4;
}


