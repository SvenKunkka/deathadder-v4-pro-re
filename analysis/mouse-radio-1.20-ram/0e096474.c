/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096474. Types and names are inferred; NOT original source. */

void FUN_0e096474(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    return;
  }
  param_1[2] = param_2;
  uVar7 = 0;
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    uVar7 = getBasePriority();
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if ((bVar8) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((param_4 + 1) - (uint)(param_3 != 0xffffffff)) < 0 ==
      (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != 0xffffffff)))) {
    uVar5 = param_3 + 1;
    iVar6 = param_4 + (uint)(0xfffffffe < param_3);
    if (DAT_23007680 == 0) {
      uVar3 = thunk_FUN_23028b70();
      bVar8 = CARRY4(uVar3,uVar5);
      uVar5 = uVar3 + uVar5;
      iVar6 = iVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar8;
    }
  }
  else {
    uVar5 = (-DAT_230025f8 - 2) - param_3;
    iVar6 = (((-1 - DAT_230025fc) - (uint)(0xfffffffe < DAT_230025f8)) - param_4) -
            (uint)(-DAT_230025f8 - 2 < param_3);
    if (iVar6 < (int)(uint)(uVar5 == 0)) {
      uVar5 = 1;
      iVar6 = 0;
    }
  }
  param_1[4] = uVar5;
  param_1[5] = iVar6;
  puVar4 = DAT_230014f8;
  puVar1 = DAT_230014f4;
  if ((undefined4 **)DAT_230014f4 != &DAT_230014f4) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      uVar3 = puVar1[4];
      iVar2 = puVar1[5];
      if ((int)((iVar6 - iVar2) - (uint)(uVar5 < uVar3)) < 0 !=
          (SBORROW4(iVar6,iVar2) != SBORROW4(iVar6 - iVar2,(uint)(uVar5 < uVar3)))) {
        puVar1[4] = uVar3 - uVar5;
        puVar1[5] = (iVar2 - iVar6) - (uint)(uVar3 < uVar5);
        puVar4 = (undefined4 *)puVar1[1];
        *param_1 = puVar1;
        param_1[1] = puVar4;
        *puVar4 = param_1;
        puVar1[1] = param_1;
        goto LAB_0e096504;
      }
      bVar8 = uVar5 < uVar3;
      uVar5 = uVar5 - uVar3;
      iVar6 = (iVar6 - iVar2) - (uint)bVar8;
      param_1[4] = uVar5;
      param_1[5] = iVar6;
      if (puVar4 == puVar1) break;
    }
  }
  *param_1 = &DAT_230014f4;
  param_1[1] = puVar4;
  *puVar4 = param_1;
  DAT_230014f8 = param_1;
LAB_0e096504:
  if ((((undefined4 **)DAT_230014f4 != &DAT_230014f4) && (param_1 == DAT_230014f4)) &&
     (DAT_23007680 == 0)) {
    uVar3 = thunk_FUN_23028b70();
    uVar5 = param_1[4] - uVar3;
    iVar6 = (param_1[5] - ((int)uVar3 >> 0x1f)) - (uint)((uint)param_1[4] < uVar3);
    if (iVar6 < 0) {
      uVar5 = 0;
      iVar6 = 0;
    }
    bVar8 = uVar5 < 0x80000000;
    if ((int)(uint)bVar8 <= iVar6) {
      uVar5 = 0x7fffffff;
    }
    thunk_FUN_23028b9c(uVar5,0,param_1[5],iVar6 - (uint)bVar8,param_4);
    bVar8 = (bool)isCurrentModePrivileged();
    if (bVar8) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


