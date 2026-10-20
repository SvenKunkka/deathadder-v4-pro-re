/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c1020a0. Types and names are inferred; NOT original source. */

undefined4 FUN_1c1020a0(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = (int *)*param_1;
  if ((piVar6 != param_1) && (piVar6 != (int *)0x0)) {
    do {
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
      if (piVar6[2] != 0) {
        iVar5 = *piVar6;
        piVar4 = (int *)piVar6[1];
        *piVar4 = iVar5;
        *(int **)(iVar5 + 4) = piVar4;
        *piVar6 = 0;
        piVar6[1] = 0;
        *(byte *)((int)piVar6 + 0xd) = *(byte *)((int)piVar6 + 0xd) & 0xfd;
        piVar6[2] = 0;
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_1c1026bc(piVar6 + 6,uVar3);
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
      FUN_1c1019e4(piVar6);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      piVar6 = (int *)*param_1;
    } while ((param_1 != piVar6) && (piVar6 != (int *)0x0));
    return 1;
  }
  return 0;
}


