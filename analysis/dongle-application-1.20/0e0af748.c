/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0af748. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0af748(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
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
  if (*(int *)(param_1 + 8) == 0) {
    if (param_3 == 0 && param_4 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar3 = 0xfffffff0;
    }
    else {
      uVar3 = FUN_0e0afdcc(0x2f011bda,uVar3,param_1,param_4,param_3,param_4);
    }
  }
  else {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar3 = 0;
  }
  return uVar3;
}


