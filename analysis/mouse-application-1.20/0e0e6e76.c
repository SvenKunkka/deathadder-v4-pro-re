/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6e76. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0e6e76(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 uStack_c;
  
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
  local_10 = param_1;
  uStack_c = param_2;
  FUN_0e0e45f4(&local_10);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return local_10;
}


