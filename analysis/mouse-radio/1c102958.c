/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c102958. Types and names are inferred; NOT original source. */

int * FUN_1c102958(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    *param_1 = -1;
    param_1[1] = -1;
    return param_1;
  }
  if (param_3 == 0 && param_4 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    return param_1;
  }
  iVar4 = -2 - param_3;
  iVar3 = (-1 - param_4) - (uint)(0xfffffffe < param_3);
  if (iVar3 < 0) {
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
    if (*DAT_1c1029e0 == 0) {
      uVar2 = FUN_1c103738();
      iVar3 = (int)uVar2 >> 0x1f;
    }
    else {
      uVar2 = 0;
      iVar3 = 0;
    }
    uVar5 = uVar2 + *DAT_1c1029e4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar4 = uVar5 + param_3;
    iVar3 = iVar3 + DAT_1c1029e4[1] + (uint)CARRY4(uVar2,*DAT_1c1029e4) +
            param_4 + (uint)CARRY4(uVar5,param_3);
  }
  *param_1 = iVar4;
  param_1[1] = iVar3;
  return param_1;
}


