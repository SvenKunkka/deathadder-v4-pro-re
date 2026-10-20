/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0920f8. Types and names are inferred; NOT original source. */

void FUN_0e0920f8(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  
  iVar5 = DAT_0e092250;
  piVar10 = *(int **)(DAT_0e092250 + param_1 * 0xc);
  iVar11 = DAT_0e092250 + param_1 * 0xc;
  piVar9 = *(int **)(iVar11 + 4);
  iVar3 = FUN_0e092b60(piVar10);
  if (iVar3 == 0xf) {
    bVar1 = *(byte *)(iVar11 + 8);
  }
  else {
    bVar1 = *(byte *)(iVar11 + 9);
  }
  iVar3 = FUN_0e092b60(piVar9);
  iVar11 = iVar5 + param_1 * 0xc;
  if (iVar3 == 0xf) {
    bVar2 = *(byte *)(iVar11 + 8);
  }
  else {
    bVar2 = *(byte *)(iVar11 + 9);
  }
  iVar3 = 1 << (uint)bVar1;
  iVar11 = 1 << (uint)bVar2;
  if (param_2 == 0) {
    *(int *)(*piVar10 + 0x508) = iVar3;
    *(int *)(*piVar9 + 0x508) = iVar11;
    iVar4 = FUN_0e0920c4(piVar10,piVar9);
    if (iVar4 != 0) {
      piVar8 = (int *)FUN_0e092b68();
      *(int *)(*piVar8 + 0x508) = 1 << *(sbyte *)(iVar5 + param_1 * 0xc + 8);
    }
    iVar5 = FUN_0e092b60(piVar10);
    iVar4 = FUN_0e092b60(piVar9);
    if (iVar5 != iVar4) {
      puVar6 = (undefined4 *)FUN_0e092be4(piVar10);
      puVar7 = (undefined4 *)FUN_0e092be4(piVar9);
      piVar9 = (int *)FUN_0e092b70(*puVar6);
      piVar10 = (int *)FUN_0e092b70(*puVar7);
      *(int *)(*piVar9 + 0x508) = iVar3;
      *(int *)(*piVar10 + 0x508) = iVar11;
    }
  }
  else {
    *(int *)(*piVar10 + 0x504) = iVar3;
    *(int *)(*piVar9 + 0x504) = iVar11;
    iVar4 = FUN_0e0920c4(piVar10,piVar9);
    if (iVar4 == 0) {
      iVar5 = FUN_0e092b60(piVar10);
      iVar4 = FUN_0e092b60(piVar9);
      if (iVar4 != iVar5) {
LAB_0e09217e:
        puVar6 = (undefined4 *)FUN_0e092be4(piVar10);
        puVar7 = (undefined4 *)FUN_0e092be4(piVar9);
        piVar9 = (int *)FUN_0e092b70(*puVar6);
        piVar10 = (int *)FUN_0e092b70(*puVar7);
        *(int *)(*piVar9 + 0x504) = iVar3;
        *(int *)(*piVar10 + 0x504) = iVar11;
        return;
      }
    }
    else {
      piVar8 = (int *)FUN_0e092b68();
      *(int *)(*piVar8 + 0x504) = 1 << (uint)*(byte *)(iVar5 + param_1 * 0xc + 8);
      iVar5 = FUN_0e092b60(piVar10);
      iVar4 = FUN_0e092b60(piVar9);
      if (iVar5 != iVar4) goto LAB_0e09217e;
    }
  }
  return;
}


