/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2610. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0b2610(int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
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
  piVar4 = (int *)*param_1;
  if (param_1 == piVar4) {
    uVar3 = 0;
  }
  else if (piVar4 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    piVar4[0x22] = param_2;
    piVar4[5] = param_3;
    FUN_0e0b2468(piVar4);
    FUN_0e0b26cc(piVar4 + 6);
    FUN_0e0afc14(piVar4);
    uVar3 = 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


