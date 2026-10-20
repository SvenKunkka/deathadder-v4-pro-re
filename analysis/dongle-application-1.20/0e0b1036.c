/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1036. Types and names are inferred; NOT original source. */

void FUN_0e0b1036(int param_1,undefined4 param_2)

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
  *(undefined4 *)(param_1 + 0x14) = param_2;
  FUN_0e0abb44(param_1,1,uVar3);
  return;
}


