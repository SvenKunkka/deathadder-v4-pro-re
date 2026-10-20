/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c10259c. Types and names are inferred; NOT original source. */

void FUN_1c10259c(int *param_1,int param_2,uint param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    return;
  }
  param_1[2] = param_2;
  uVar8 = 0;
  bVar9 = (bool)isCurrentModePrivileged();
  if (bVar9) {
    uVar8 = getBasePriority();
  }
  bVar9 = (bool)isCurrentModePrivileged();
  if ((bVar9) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((param_4 + 1) - (uint)(param_3 != 0xffffffff)) < 0 ==
      (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != 0xffffffff)))) {
    uVar6 = param_3 + 1;
    iVar7 = param_4 + (uint)(0xfffffffe < param_3);
    if (*DAT_1c1026b8 == 0) {
      uVar5 = FUN_1c103738();
      bVar9 = CARRY4(uVar5,uVar6);
      uVar6 = uVar5 + uVar6;
      iVar7 = iVar7 + ((int)uVar5 >> 0x1f) + (uint)bVar9;
    }
  }
  else {
    uVar5 = -*DAT_1c1026b0 - 2;
    uVar6 = uVar5 - param_3;
    iVar7 = (((-1 - DAT_1c1026b0[1]) - (uint)(0xfffffffe < *DAT_1c1026b0)) - param_4) -
            (uint)(uVar5 < param_3);
    if (iVar7 < (int)(uint)(uVar6 == 0)) {
      uVar6 = 1;
      iVar7 = 0;
    }
  }
  piVar1 = DAT_1c1026b4;
  param_1[4] = uVar6;
  param_1[5] = iVar7;
  piVar4 = (int *)*piVar1;
  puVar2 = (undefined4 *)piVar1[1];
  if (piVar4 != piVar1) {
    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      uVar5 = piVar4[4];
      iVar3 = piVar4[5];
      if ((int)((iVar7 - iVar3) - (uint)(uVar6 < uVar5)) < 0 !=
          (SBORROW4(iVar7,iVar3) != SBORROW4(iVar7 - iVar3,(uint)(uVar6 < uVar5)))) {
        piVar4[4] = uVar5 - uVar6;
        piVar4[5] = (iVar3 - iVar7) - (uint)(uVar5 < uVar6);
        puVar2 = (undefined4 *)piVar4[1];
        *param_1 = (int)piVar4;
        param_1[1] = (int)puVar2;
        *puVar2 = param_1;
        piVar4[1] = (int)param_1;
        goto LAB_1c10262c;
      }
      bVar9 = uVar6 < uVar5;
      uVar6 = uVar6 - uVar5;
      iVar7 = (iVar7 - iVar3) - (uint)bVar9;
      param_1[4] = uVar6;
      param_1[5] = iVar7;
      if (puVar2 == piVar4) break;
    }
  }
  *param_1 = (int)piVar1;
  param_1[1] = (int)puVar2;
  *puVar2 = param_1;
  piVar1[1] = (int)param_1;
LAB_1c10262c:
  if ((((int *)*piVar1 != piVar1) && (param_1 == (int *)*piVar1)) && (*DAT_1c1026b8 == 0)) {
    uVar5 = FUN_1c103738();
    uVar6 = param_1[4] - uVar5;
    iVar7 = (param_1[5] - ((int)uVar5 >> 0x1f)) - (uint)((uint)param_1[4] < uVar5);
    if (iVar7 < 0) {
      uVar6 = 0;
      iVar7 = 0;
    }
    bVar9 = uVar6 < 0x80000000;
    if ((int)(uint)bVar9 <= iVar7) {
      uVar6 = 0x7fffffff;
    }
    FUN_1c103648(uVar6,0,param_1[5],iVar7 - (uint)bVar9,param_4);
    bVar9 = (bool)isCurrentModePrivileged();
    if (bVar9) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  bVar9 = (bool)isCurrentModePrivileged();
  if (bVar9) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


