/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e7fc. Types and names are inferred; NOT original source. */

void FUN_0e06e7fc(uint param_1)

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
  if ((bVar10) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x40 < uVar7)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23007198 = DAT_23000b48;
  if ((undefined4 **)DAT_23000b48 == &DAT_23000b48) {
LAB_0e06e8e8:
    DAT_23007198 = (undefined4 *)0x0;
    bVar10 = CARRY4(DAT_23002c78,param_1);
    DAT_23002c78 = DAT_23002c78 + param_1;
    DAT_23002c7c = DAT_23002c7c + ((int)param_1 >> 0x1f) + (uint)bVar10;
LAB_0e06e8fc:
    FUN_0e068568();
LAB_0e06e900:
    uVar6 = 0x7fffffff;
  }
  else {
    if (DAT_23000b48 == (undefined4 *)0x0) {
      bVar10 = CARRY4(DAT_23002c78,param_1);
      DAT_23002c78 = DAT_23002c78 + param_1;
      DAT_23002c7c = DAT_23002c7c + ((int)param_1 >> 0x1f) + (uint)bVar10;
      goto LAB_0e06e8fc;
    }
    do {
      puVar1 = DAT_23000b48;
      uVar7 = DAT_23000b48[4];
      iVar5 = DAT_23000b48[5];
      iVar4 = (int)param_1 >> 0x1f;
      if ((int)((iVar4 - iVar5) - (uint)(param_1 < uVar7)) < 0 !=
          (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)(param_1 < uVar7)))) {
        DAT_23000b48[4] = uVar7 - param_1;
        puVar8 = DAT_23000b48;
        puVar1[5] = (iVar5 - iVar4) - (uint)(uVar7 < param_1);
        goto LAB_0e06e896;
      }
      bVar10 = CARRY4(DAT_23002c78,uVar7);
      DAT_23002c78 = DAT_23002c78 + uVar7;
      DAT_23002c7c = DAT_23002c7c + ((int)uVar7 >> 0x1f) + (uint)bVar10;
      DAT_23007198 = (undefined4 *)param_1;
      DAT_23000b48[4] = 0;
      puVar1[5] = 0;
      iVar4 = FUN_0e06e610();
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
      if ((bVar10) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      param_1 = (int)DAT_23007198 - uVar7;
      if ((undefined4 **)DAT_23000b48 == &DAT_23000b48) goto LAB_0e06e8e8;
    } while (DAT_23000b48 != (undefined4 *)0x0);
    iVar4 = (int)param_1 >> 0x1f;
    puVar8 = DAT_23000b48;
LAB_0e06e896:
    DAT_23007198 = (undefined4 *)0x0;
    bVar10 = CARRY4(DAT_23002c78,param_1);
    DAT_23002c78 = DAT_23002c78 + param_1;
    DAT_23002c7c = DAT_23002c7c + iVar4 + (uint)bVar10;
    if ((undefined4 **)puVar8 == &DAT_23000b48) goto LAB_0e06e8fc;
    uVar7 = FUN_0e068568();
    if (puVar8 == (undefined4 *)0x0) goto LAB_0e06e900;
    uVar6 = puVar8[4] - uVar7;
    iVar4 = (puVar8[5] - ((int)uVar7 >> 0x1f)) - (uint)((uint)puVar8[4] < uVar7);
    if ((int)(uint)(uVar6 < 0x80000000) <= iVar4) goto LAB_0e06e900;
    if (iVar4 < 0) {
      uVar6 = 0;
    }
  }
  FUN_0e068584(uVar6,0);
  puVar2 = DAT_23007170;
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
  if ((bVar10) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x40 < uVar7)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar3 = DAT_23007188;
  if (DAT_23007188 != DAT_23007170) {
    DAT_23007188 = (undefined *)0x0;
    if (((((&DAT_2300718c)[DAT_23007178] == '\0') || (0x7f < *(ushort *)(DAT_23007170 + 0xe))) ||
        (DAT_23007194 == 0)) ||
       ((((char)DAT_23007170[0xe] < DAT_23007190 || ((DAT_23007170[0xd] & 0x1f) != 0)) ||
        (DAT_23007170 == &DAT_230029f8)))) goto LAB_0e06e5b4;
    FUN_0e06dca8(DAT_23007170);
    puVar3 = puVar2;
  }
  FUN_0e06e4ec(puVar3);
LAB_0e06e5b4:
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


