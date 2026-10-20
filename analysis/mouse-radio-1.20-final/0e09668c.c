/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09668c. Types and names are inferred; NOT original source. */

void FUN_0e09668c(uint param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  bool bVar10;
  
  uVar9 = 0;
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    uVar9 = getBasePriority();
  }
  bVar10 = (bool)isCurrentModePrivileged();
  if ((bVar10) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23007680 = DAT_230014f4;
  if ((undefined4 **)DAT_230014f4 == &DAT_230014f4) {
LAB_0e096778:
    DAT_23007680 = (undefined4 *)0x0;
    bVar10 = CARRY4(DAT_230025f8,param_1);
    DAT_230025f8 = DAT_230025f8 + param_1;
    DAT_230025fc = DAT_230025fc + ((int)param_1 >> 0x1f) + (uint)bVar10;
LAB_0e09678c:
    thunk_FUN_23028b70();
LAB_0e096790:
    uVar6 = 0x7fffffff;
  }
  else {
    if (DAT_230014f4 == (undefined4 *)0x0) {
      bVar10 = CARRY4(DAT_230025f8,param_1);
      DAT_230025f8 = DAT_230025f8 + param_1;
      DAT_230025fc = DAT_230025fc + ((int)param_1 >> 0x1f) + (uint)bVar10;
      goto LAB_0e09678c;
    }
    do {
      puVar1 = DAT_230014f4;
      uVar7 = DAT_230014f4[4];
      iVar5 = DAT_230014f4[5];
      iVar4 = (int)param_1 >> 0x1f;
      if ((int)((iVar4 - iVar5) - (uint)(param_1 < uVar7)) < 0 !=
          (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)(param_1 < uVar7)))) {
        DAT_230014f4[4] = uVar7 - param_1;
        puVar8 = DAT_230014f4;
        puVar1[5] = (iVar5 - iVar4) - (uint)(uVar7 < param_1);
        goto LAB_0e096726;
      }
      bVar10 = CARRY4(DAT_230025f8,uVar7);
      DAT_230025f8 = DAT_230025f8 + uVar7;
      DAT_230025fc = DAT_230025fc + ((int)uVar7 >> 0x1f) + (uint)bVar10;
      DAT_23007680 = (undefined4 *)param_1;
      DAT_230014f4[4] = 0;
      puVar1[5] = 0;
      iVar4 = FUN_0e09643c();
      bVar10 = (bool)isCurrentModePrivileged();
      if (bVar10) {
        setBasePriority(uVar9);
      }
      InstructionSynchronizationBarrier(0xf);
      (**(code **)(iVar4 + 8))();
      uVar9 = 0;
      bVar10 = (bool)isCurrentModePrivileged();
      if (bVar10) {
        uVar9 = getBasePriority();
      }
      bVar10 = (bool)isCurrentModePrivileged();
      if ((bVar10) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      param_1 = (int)DAT_23007680 - uVar7;
      if ((undefined4 **)DAT_230014f4 == &DAT_230014f4) goto LAB_0e096778;
    } while (DAT_230014f4 != (undefined4 *)0x0);
    iVar4 = (int)param_1 >> 0x1f;
    puVar8 = DAT_230014f4;
LAB_0e096726:
    DAT_23007680 = (undefined4 *)0x0;
    bVar10 = CARRY4(DAT_230025f8,param_1);
    DAT_230025f8 = DAT_230025f8 + param_1;
    DAT_230025fc = DAT_230025fc + iVar4 + (uint)bVar10;
    if ((undefined4 **)puVar8 == &DAT_230014f4) goto LAB_0e09678c;
    uVar7 = thunk_FUN_23028b70();
    if (puVar8 == (undefined4 *)0x0) goto LAB_0e096790;
    uVar6 = puVar8[4] - uVar7;
    iVar4 = (puVar8[5] - ((int)uVar7 >> 0x1f)) - (uint)((uint)puVar8[4] < uVar7);
    if ((int)(uint)(uVar6 < 0x80000000) <= iVar4) goto LAB_0e096790;
    if (iVar4 < 0) {
      uVar6 = 0;
    }
  }
  thunk_FUN_23028b9c(uVar6,0);
  puVar2 = DAT_23007654;
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar9 = 0;
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    uVar9 = getBasePriority();
  }
  bVar10 = (bool)isCurrentModePrivileged();
  if ((bVar10) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar3 = DAT_23007670;
  if (DAT_23007670 != DAT_23007654) {
    DAT_23007670 = (undefined *)0x0;
    if (((((&DAT_23007674)[DAT_2300765c] == '\0') || (0x7f < *(ushort *)(DAT_23007654 + 0xe))) ||
        (DAT_2300767c == 0)) ||
       ((((char)DAT_23007654[0xe] < DAT_23007678 || ((DAT_23007654[0xd] & 0x1f) != 0)) ||
        (DAT_23007654 == &DAT_23002378)))) goto LAB_0e0963e0;
    FUN_0e095b58(DAT_23007654);
    puVar3 = puVar2;
  }
  FUN_0e096318(puVar3);
LAB_0e0963e0:
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


