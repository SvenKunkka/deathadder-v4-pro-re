/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e278. Types and names are inferred; NOT original source. */

int FUN_0e06e278(uint param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0 && param_2 == 0) {
    FUN_0e06e1dc();
  }
  else {
    if ((int)((param_2 + 1) - (uint)(param_1 < 0xfffffffe)) < 0 ==
        (SBORROW4(param_2,-1) != SBORROW4(param_2 + 1,(uint)(param_1 < 0xfffffffe)))) {
      iVar5 = FUN_0e06e968();
      uVar6 = iVar5 + param_1;
    }
    else {
      uVar6 = -param_1 - 2;
    }
    piVar1 = DAT_23007170;
    uVar7 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar7 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    DAT_23007188 = DAT_23007170;
    if (*(char *)((int)DAT_23007170 + 0xd) < '\0') {
      *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) & 0x7f;
      iVar5 = *piVar1;
      piVar4 = (int *)piVar1[1];
      *piVar4 = iVar5;
      *(int **)(iVar5 + 4) = piVar4;
      *piVar1 = 0;
      piVar1[1] = 0;
      bVar2 = DAT_23007170 == piVar1;
    }
    else {
      bVar2 = true;
    }
    FUN_0e06d9cc(bVar2);
    FUN_0e06e648(DAT_23007170 + 6,&LAB_0e06daf4_1,param_1,param_2);
    *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) | 0x10;
    FUN_0e0611cc(uVar7);
    uVar3 = FUN_0e06e968();
    if ((int)(uint)(uVar6 - uVar3 == 0) <= (int)-(uint)(uVar6 < uVar3)) {
      return uVar6 - uVar3;
    }
  }
  return 0;
}


