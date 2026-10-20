/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a108. Types and names are inferred; NOT original source. */

void FUN_0e06a108(int param_1,int param_2)

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
  
  piVar11 = *(int **)(&DAT_23006e58 + param_1 * 0xc);
  iVar4 = param_1 * 0xc;
  piVar10 = *(int **)(&DAT_23006e5c + iVar4);
  iVar3 = FUN_0e06ab70(piVar11);
  if (iVar3 == 0xf) {
    bVar1 = (&DAT_23006e60)[iVar4];
  }
  else {
    bVar1 = (&DAT_23006e61)[iVar4];
  }
  iVar4 = FUN_0e06ab70(piVar10);
  if (iVar4 == 0xf) {
    bVar2 = (&DAT_23006e60)[param_1 * 0xc];
  }
  else {
    bVar2 = (&DAT_23006e61)[param_1 * 0xc];
  }
  iVar4 = 1 << (uint)bVar1;
  iVar3 = 1 << (uint)bVar2;
  if (param_2 == 0) {
    *(int *)(*piVar11 + 0x508) = iVar4;
    *(int *)(*piVar10 + 0x508) = iVar3;
    iVar5 = FUN_0e06a0d4(piVar11,piVar10);
    if (iVar5 != 0) {
      piVar9 = (int *)FUN_0e06ab78();
      *(int *)(*piVar9 + 0x508) = 1 << (&DAT_23006e60)[param_1 * 0xc];
    }
    iVar5 = FUN_0e06ab70(piVar11);
    iVar6 = FUN_0e06ab70(piVar10);
    if (iVar5 != iVar6) {
      puVar7 = (undefined4 *)FUN_0e06abf4(piVar11);
      puVar8 = (undefined4 *)FUN_0e06abf4(piVar10);
      piVar10 = (int *)FUN_0e06ab80(*puVar7);
      piVar11 = (int *)FUN_0e06ab80(*puVar8);
      *(int *)(*piVar10 + 0x508) = iVar4;
      *(int *)(*piVar11 + 0x508) = iVar3;
    }
  }
  else {
    *(int *)(*piVar11 + 0x504) = iVar4;
    *(int *)(*piVar10 + 0x504) = iVar3;
    iVar5 = FUN_0e06a0d4(piVar11,piVar10);
    if (iVar5 == 0) {
      iVar5 = FUN_0e06ab70(piVar11);
      iVar6 = FUN_0e06ab70(piVar10);
      if (iVar6 != iVar5) {
LAB_0e06a18e:
        puVar7 = (undefined4 *)FUN_0e06abf4(piVar11);
        puVar8 = (undefined4 *)FUN_0e06abf4(piVar10);
        piVar10 = (int *)FUN_0e06ab80(*puVar7);
        piVar11 = (int *)FUN_0e06ab80(*puVar8);
        *(int *)(*piVar10 + 0x504) = iVar4;
        *(int *)(*piVar11 + 0x504) = iVar3;
        return;
      }
    }
    else {
      piVar9 = (int *)FUN_0e06ab78();
      *(int *)(*piVar9 + 0x504) = 1 << (uint)(byte)(&DAT_23006e60)[param_1 * 0xc];
      iVar5 = FUN_0e06ab70(piVar11);
      iVar6 = FUN_0e06ab70(piVar10);
      if (iVar5 != iVar6) goto LAB_0e06a18e;
    }
  }
  return;
}


