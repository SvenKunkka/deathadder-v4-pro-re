/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0960a8. Types and names are inferred; NOT original source. */

int FUN_0e0960a8(uint param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0 && param_2 == 0) {
    FUN_0e09600c();
  }
  else {
    if ((int)((param_2 + 1) - (uint)(param_1 < 0xfffffffe)) < 0 ==
        (SBORROW4(param_2,-1) != SBORROW4(param_2 + 1,(uint)(param_1 < 0xfffffffe)))) {
      iVar5 = FUN_0e0967b8();
      uVar6 = iVar5 + param_1;
    }
    else {
      uVar6 = -param_1 - 2;
    }
    piVar1 = DAT_23007654;
    uVar7 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar7 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    DAT_23007670 = DAT_23007654;
    if (*(char *)((int)DAT_23007654 + 0xd) < '\0') {
      *(byte *)((int)DAT_23007654 + 0xd) = *(byte *)((int)DAT_23007654 + 0xd) & 0x7f;
      iVar5 = *piVar1;
      piVar4 = (int *)piVar1[1];
      *piVar4 = iVar5;
      *(int **)(iVar5 + 4) = piVar4;
      *piVar1 = 0;
      piVar1[1] = 0;
      bVar2 = DAT_23007654 == piVar1;
    }
    else {
      bVar2 = true;
    }
    FUN_0e09587c(bVar2);
    FUN_0e096474(DAT_23007654 + 6,&LAB_0e0959a4_1,param_1,param_2);
    *(byte *)((int)DAT_23007654 + 0xd) = *(byte *)((int)DAT_23007654 + 0xd) | 0x10;
    FUN_0e089d4c(uVar7);
    uVar3 = FUN_0e0967b8();
    if ((int)(uint)(uVar6 - uVar3 == 0) <= (int)-(uint)(uVar6 < uVar3)) {
      return uVar6 - uVar3;
    }
  }
  return 0;
}


