/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096348. Types and names are inferred; NOT original source. */

undefined4 FUN_0e096348(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
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
  piVar5 = (int *)*param_1;
  if (param_1 == piVar5) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  if (piVar5 == (int *)0x0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  piVar5[5] = param_3;
  piVar3 = (int *)piVar5[1];
  iVar4 = *piVar5;
  piVar5[0x23] = param_2;
  *piVar3 = iVar4;
  *(int **)(iVar4 + 4) = piVar3;
  piVar5[2] = 0;
  *(byte *)((int)piVar5 + 0xd) = *(byte *)((int)piVar5 + 0xd) & 0xfd;
  *piVar5 = 0;
  piVar5[1] = 0;
  FUN_0e0966bc(piVar5 + 6);
  FUN_0e0959e4(piVar5);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}


