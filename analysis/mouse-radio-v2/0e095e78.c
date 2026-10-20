/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095e78. Types and names are inferred; NOT original source. */

int * FUN_0e095e78(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
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
  piVar3 = (int *)*param_1;
  if ((param_1 != piVar3) && (piVar3 != (int *)0x0)) {
    iVar6 = *piVar3;
    piVar4 = (int *)piVar3[1];
    *piVar4 = iVar6;
    *(int **)(iVar6 + 4) = piVar4;
    *piVar3 = 0;
    piVar3[1] = 0;
    *(byte *)((int)piVar3 + 0xd) = *(byte *)((int)piVar3 + 0xd) & 0xfd;
    piVar3[2] = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return piVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return (int *)0x0;
}


