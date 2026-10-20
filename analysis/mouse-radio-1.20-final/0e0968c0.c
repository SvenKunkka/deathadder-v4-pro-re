/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0968c0. Types and names are inferred; NOT original source. */

int * FUN_0e0968c0(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_4 == 0xffffffff && param_3 == 0xffffffff) {
    *param_1 = -1;
    param_1[1] = -1;
    return param_1;
  }
  if (param_4 != 0 || param_3 != 0) {
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
    if (DAT_23007680 == 0) {
      uVar2 = thunk_FUN_23028b70();
      iVar4 = (int)uVar2 >> 0x1f;
    }
    else {
      uVar2 = 0;
      iVar4 = 0;
    }
    uVar3 = uVar2 + DAT_230025f8;
    uVar2 = iVar4 + DAT_230025fc + (uint)CARRY4(uVar2,DAT_230025f8);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    if (uVar2 <= param_4 && (uint)(param_3 <= uVar3) <= uVar2 - param_4) {
      *param_1 = param_3 - uVar3;
      param_1[1] = (param_4 - uVar2) - (uint)(param_3 < uVar3);
      return param_1;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


