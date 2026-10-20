/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e00c. Types and names are inferred; NOT original source. */

int * FUN_0e06e00c(int *param_1)

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
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar5 = (int *)*param_1;
  if (param_1 == piVar5) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return (int *)0x0;
  }
  if (piVar5 != (int *)0x0) {
    iVar4 = *piVar5;
    piVar3 = (int *)piVar5[1];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    *piVar5 = 0;
    piVar5[1] = 0;
    *(byte *)((int)piVar5 + 0xd) = *(byte *)((int)piVar5 + 0xd) & 0xfd;
    piVar5[2] = 0;
    FUN_0e06e804(piVar5 + 6);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return piVar5;
}


