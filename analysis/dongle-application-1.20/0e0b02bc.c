/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b02bc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0b02bc(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  
  if (param_4 != -1 || param_3 != 0xffffffff) {
    param_1[2] = param_2;
    uVar9 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar9 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar6 = (param_4 + 1) - (uint)(param_3 != 0xffffffff);
    if (iVar6 < 0 == (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != 0xffffffff))))
    {
      uVar5 = FUN_0e0b0270(param_1,param_2,param_3 + 1,iVar6,param_4);
      iVar8 = param_3 + 1 + uVar5;
      iVar6 = param_4 + (uint)(0xfffffffe < param_3) +
              ((int)uVar5 >> 0x1f) + (uint)CARRY4(param_3 + 1,uVar5);
    }
    else {
      iVar8 = (-_DAT_2f0118e0 - 2) - param_3;
      iVar6 = (((-1 - _DAT_2f0118e4) - (uint)(0xfffffffe < _DAT_2f0118e0)) - param_4) -
              (uint)(-_DAT_2f0118e0 - 2 < param_3);
      if (iVar6 < (int)(uint)(iVar8 == 0)) {
        iVar8 = 1;
        iVar6 = 0;
      }
    }
    param_1[4] = iVar8;
    param_1[5] = iVar6;
    puVar2 = (undefined4 *)FUN_0e0b0260();
    puVar3 = _DAT_2f011478;
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      uVar5 = puVar2[4];
      iVar8 = puVar2[5];
      uVar7 = param_1[4];
      iVar6 = param_1[5];
      if ((int)((iVar6 - iVar8) - (uint)(uVar7 < uVar5)) < 0 !=
          (SBORROW4(iVar6,iVar8) != SBORROW4(iVar6 - iVar8,(uint)(uVar7 < uVar5)))) {
        puVar3 = (undefined4 *)puVar2[1];
        puVar2[4] = uVar5 - uVar7;
        puVar2[5] = (iVar8 - iVar6) - (uint)(uVar5 < uVar7);
        *param_1 = puVar2;
        param_1[1] = puVar3;
        *puVar3 = param_1;
        puVar2[1] = param_1;
        goto LAB_0e0b0366;
      }
      param_1[4] = uVar7 - uVar5;
      param_1[5] = (iVar6 - iVar8) - (uint)(uVar7 < uVar5);
      if (puVar2 == puVar3) break;
    }
    *param_1 = &DAT_2f011474;
    param_1[1] = puVar3;
    *puVar3 = param_1;
    _DAT_2f011478 = param_1;
LAB_0e0b0366:
    puVar3 = (undefined4 *)FUN_0e0b0260();
    if ((param_1 == puVar3) && (_DAT_2f011bd0 == 0)) {
      uVar4 = FUN_0e0b269a();
      FUN_0e0adf4c(uVar4,0);
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


