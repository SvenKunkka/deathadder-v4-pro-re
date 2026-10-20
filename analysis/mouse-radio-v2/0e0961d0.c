/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0961d0. Types and names are inferred; NOT original source. */

int FUN_0e0961d0(uint param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  
  if (param_1 == 0 && param_2 == 0) {
    FUN_0e096134();
  }
  else {
    if ((int)((param_2 + 1) - (uint)(param_1 < 0xfffffffe)) < 0 ==
        (SBORROW4(param_2,-1) != SBORROW4(param_2 + 1,(uint)(param_1 < 0xfffffffe)))) {
      iVar5 = FUN_0e0968e0();
      uVar8 = iVar5 + param_1;
    }
    else {
      uVar8 = -param_1 - 2;
    }
    iVar5 = DAT_0e096280;
    uVar9 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar9 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    piVar7 = *(int **)(DAT_0e096280 + 8);
    cVar1 = *(char *)((int)piVar7 + 0xd);
    *DAT_0e096284 = piVar7;
    if (cVar1 < '\0') {
      *(byte *)((int)piVar7 + 0xd) = *(byte *)((int)piVar7 + 0xd) & 0x7f;
      iVar6 = *piVar7;
      piVar4 = (int *)piVar7[1];
      *piVar4 = iVar6;
      *(int **)(iVar6 + 4) = piVar4;
      *piVar7 = 0;
      piVar7[1] = 0;
      bVar2 = *(int **)(iVar5 + 8) == piVar7;
    }
    else {
      bVar2 = true;
    }
    FUN_0e0959a4(bVar2);
    FUN_0e09659c(*(int *)(iVar5 + 8) + 0x18,DAT_0e096288,param_1,param_2);
    *(byte *)(*(int *)(iVar5 + 8) + 0xd) = *(byte *)(*(int *)(iVar5 + 8) + 0xd) | 0x10;
    FUN_0e089ed8(uVar9);
    uVar3 = FUN_0e0968e0();
    if ((int)(uint)(uVar8 - uVar3 == 0) <= (int)-(uint)(uVar8 < uVar3)) {
      return uVar8 - uVar3;
    }
  }
  return 0;
}


