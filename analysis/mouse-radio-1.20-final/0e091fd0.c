/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091fd0. Types and names are inferred; NOT original source. */

void FUN_0e091fd0(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  
  piVar11 = *(int **)(&DAT_23007338 + param_1 * 0xc);
  iVar4 = param_1 * 0xc;
  piVar10 = *(int **)(&DAT_2300733c + iVar4);
  iVar3 = FUN_0e092a38(piVar11);
  if (iVar3 == 0xf) {
    bVar1 = (&DAT_23007340)[iVar4];
  }
  else {
    bVar1 = (&DAT_23007341)[iVar4];
  }
  iVar4 = FUN_0e092a38(piVar10);
  if (iVar4 == 0xf) {
    bVar2 = (&DAT_23007340)[param_1 * 0xc];
  }
  else {
    bVar2 = (&DAT_23007341)[param_1 * 0xc];
  }
  iVar4 = 1 << (uint)bVar1;
  iVar3 = 1 << (uint)bVar2;
  if (param_2 == 0) {
    *(int *)(*piVar11 + 0x508) = iVar4;
    *(int *)(*piVar10 + 0x508) = iVar3;
    iVar5 = FUN_0e091f9c(piVar11,piVar10);
    if (iVar5 != 0) {
      piVar9 = (int *)FUN_0e092a40();
      *(int *)(*piVar9 + 0x508) = 1 << (&DAT_23007340)[param_1 * 0xc];
    }
    iVar5 = FUN_0e092a38(piVar11);
    iVar6 = FUN_0e092a38(piVar10);
    if (iVar5 != iVar6) {
      puVar7 = (undefined4 *)FUN_0e092abc(piVar11);
      puVar8 = (undefined4 *)FUN_0e092abc(piVar10);
      piVar10 = (int *)FUN_0e092a48(*puVar7);
      piVar11 = (int *)FUN_0e092a48(*puVar8);
      *(int *)(*piVar10 + 0x508) = iVar4;
      *(int *)(*piVar11 + 0x508) = iVar3;
    }
  }
  else {
    *(int *)(*piVar11 + 0x504) = iVar4;
    *(int *)(*piVar10 + 0x504) = iVar3;
    iVar5 = FUN_0e091f9c(piVar11,piVar10);
    if (iVar5 == 0) {
      iVar5 = FUN_0e092a38(piVar11);
      iVar6 = FUN_0e092a38(piVar10);
      if (iVar6 != iVar5) {
LAB_0e092056:
        puVar7 = (undefined4 *)FUN_0e092abc(piVar11);
        puVar8 = (undefined4 *)FUN_0e092abc(piVar10);
        piVar10 = (int *)FUN_0e092a48(*puVar7);
        piVar11 = (int *)FUN_0e092a48(*puVar8);
        *(int *)(*piVar10 + 0x504) = iVar4;
        *(int *)(*piVar11 + 0x504) = iVar3;
        return;
      }
    }
    else {
      piVar9 = (int *)FUN_0e092a40();
      *(int *)(*piVar9 + 0x504) = 1 << (uint)(byte)(&DAT_23007340)[param_1 * 0xc];
      iVar5 = FUN_0e092a38(piVar11);
      iVar6 = FUN_0e092a38(piVar10);
      if (iVar5 != iVar6) goto LAB_0e092056;
    }
  }
  return;
}


