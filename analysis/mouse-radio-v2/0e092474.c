/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092474. Types and names are inferred; NOT original source. */

undefined4 FUN_0e092474(int param_1,int param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_1 == param_2) {
    puVar6 = *(uint **)(param_1 + 4);
    uVar7 = *puVar6;
    uVar9 = (*(uint *)(param_1 + 8) | *(uint *)(param_1 + 0xc)) & uVar7;
    do {
      uVar7 = uVar7 & uVar9;
      if (uVar7 == 0) {
        return DAT_0e092644;
      }
      uVar8 = 0x1f - LZCOUNT(uVar7);
      uVar5 = *puVar6;
      *puVar6 = uVar5 & ~(1 << (uVar8 & 0xff));
      uVar10 = DAT_0e092640;
      uVar7 = *puVar6;
    } while (uVar5 == uVar7);
    *param_3 = (byte)uVar8;
    return uVar10;
  }
  uVar10 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar10 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar9 = getBasePriority(), uVar9 == 0 || 0x20 < uVar9)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar9 = *(uint *)(param_1 + 8) & *(uint *)(param_2 + 0xc) & **(uint **)(param_2 + 4) &
          **(uint **)(param_1 + 4);
  iVar2 = FUN_0e0920c4();
  if (iVar2 != 0) {
    iVar4 = FUN_0e092b68();
    uVar5 = *(uint *)(iVar4 + 8);
    iVar4 = FUN_0e092b68();
    uVar7 = *(uint *)(iVar4 + 0xc);
    iVar4 = FUN_0e092b68();
    uVar9 = uVar5 & uVar7 & uVar9 & **(uint **)(iVar4 + 4);
  }
  puVar6 = *(uint **)(param_1 + 4);
  uVar7 = *puVar6;
  do {
    if ((uVar7 & uVar9) == 0) goto LAB_0e09254c;
    uVar8 = 0x1f - LZCOUNT(uVar7 & uVar9);
    uVar5 = uVar8 & 0xff;
    uVar11 = *puVar6;
    *puVar6 = uVar11 & ~(1 << uVar5);
    uVar7 = *puVar6;
  } while (uVar11 == uVar7);
  *param_3 = (byte)uVar8;
  puVar6 = *(uint **)(param_2 + 4);
  uVar7 = *puVar6;
  do {
    if ((uVar7 & uVar9) == 0) {
      uVar8 = 0xff;
      goto LAB_0e092536;
    }
    uVar8 = 0x1fU - LZCOUNT(uVar7 & uVar9) & 0xff;
    uVar11 = *puVar6;
    *puVar6 = uVar11 & ~(1 << uVar8);
    uVar7 = *puVar6;
  } while (uVar11 == uVar7);
  uVar7 = uVar8;
  if (iVar2 != 0) {
    *param_3 = 0xff;
    iVar2 = FUN_0e092b68();
    puVar6 = *(uint **)(iVar2 + 4);
    uVar11 = *puVar6;
    do {
      if ((uVar11 & uVar9) == 0) goto LAB_0e092536;
      uVar7 = 0x1fU - LZCOUNT(uVar11 & uVar9) & 0xff;
      uVar12 = *puVar6;
      *puVar6 = uVar12 & ~(1 << uVar7);
      uVar11 = *puVar6;
    } while (uVar12 == uVar11);
  }
  *param_3 = (byte)uVar7;
  iVar2 = FUN_0e092b60(param_1);
  uVar3 = DAT_0e092640;
  if (iVar2 == 3) {
    uVar9 = (uint)*param_3;
    *(uint *)(*(int *)(param_1 + 0x10) + (uVar9 & 0x3f) * 4 + 0x80) = uVar9 | 0x80000000;
    *(uint *)(*(int *)(param_2 + 0x10) + uVar9 * 4 + 0x180) = uVar9 | 0x80000000;
    uVar3 = DAT_0e092640;
  }
LAB_0e09255e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar10);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
LAB_0e092536:
  FUN_0e0977e0(*(undefined4 *)(param_1 + 4),uVar5);
  if (uVar8 != 0xff) {
    FUN_0e0977e0(*(undefined4 *)(param_2 + 4),uVar8);
  }
LAB_0e09254c:
  iVar2 = FUN_0e092b68();
  uVar3 = DAT_0e092644;
  if (*param_3 != 0xff) {
    FUN_0e0977e0(*(undefined4 *)(iVar2 + 4));
    uVar3 = DAT_0e092644;
  }
  goto LAB_0e09255e;
}


