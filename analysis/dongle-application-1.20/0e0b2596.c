/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2596. Types and names are inferred; NOT original source. */

int FUN_0e0b2596(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  
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
  piVar3 = (int *)*param_1;
  if (param_1 == piVar3) {
    piVar3 = (int *)0x0;
  }
  else if (piVar3 != (int *)0x0) {
    FUN_0e0b2468(piVar3);
    FUN_0e0b26cc(piVar3 + 6);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return (int)piVar3;
}


