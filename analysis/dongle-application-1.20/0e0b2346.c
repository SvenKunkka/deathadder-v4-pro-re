/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2346. Types and names are inferred; NOT original source. */

void FUN_0e0b2346(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_14;
  
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
  local_14 = 0;
  iVar3 = FUN_0e0b229e(param_1 + -4,3,param_3,0,param_1);
  if (iVar3 != 0) {
    local_14 = *(undefined4 *)(param_1 + 0x18);
    FUN_0e0af8d8(param_1 + -0x10,&local_14);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


