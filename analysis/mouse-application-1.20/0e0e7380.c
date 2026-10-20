/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e7380. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0e7380(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_r2;
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
  if (*param_1 == 0) {
    uVar5 = 0xffffffea;
  }
  else {
    iVar3 = FUN_0e0e5eac(param_1,param_2,param_1,*param_1,param_4);
    iVar4 = FUN_0e0e5ed0(extraout_r2);
    if (iVar3 == iVar4) {
      uVar5 = FUN_0e0e734e();
      FUN_0e0e44bc(uVar5,0);
    }
    uVar5 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar5;
}


