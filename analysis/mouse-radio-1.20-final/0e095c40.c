/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095c40. Types and names are inferred; NOT original source. */

void FUN_0e095c40(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
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
  if (param_1[2] == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  iVar5 = *param_1;
  piVar4 = (int *)param_1[1];
  *piVar4 = iVar5;
  *(int **)(iVar5 + 4) = piVar4;
  *param_1 = 0;
  param_1[1] = 0;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
  param_1[2] = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


