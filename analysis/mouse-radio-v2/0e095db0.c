/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095db0. Types and names are inferred; NOT original source. */

void FUN_0e095db0(int *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  
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
  bVar4 = *(byte *)((int)param_1 + 0xd);
  if (((char)param_1[0x1b] == '\0') || (param_2 == 0)) {
    *(undefined1 *)(param_1 + 0x1b) = 0;
    if ((bVar4 & 0x28) == 0) {
      if (param_1[2] != 0) {
        iVar5 = *param_1;
        piVar7 = (int *)param_1[1];
        *piVar7 = iVar5;
        *(int **)(iVar5 + 4) = piVar7;
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = bVar4 & 0x28;
        bVar4 = *(byte *)((int)param_1 + 0xd) & 0xfd;
      }
      if (param_2 == 0) {
        bVar3 = 0xfb;
      }
      else {
        bVar3 = 0xeb;
      }
      *(byte *)((int)param_1 + 0xd) = bVar4 & bVar3;
      FUN_0e0959e4();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x1b) = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


