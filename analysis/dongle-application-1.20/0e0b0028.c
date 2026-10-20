/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0028. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0b0028(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 == 0 && param_2 == 0) {
    FUN_0e0affac();
  }
  else {
    if ((int)((param_2 + 1) - (uint)(param_1 < 0xfffffffe)) < 0 ==
        (SBORROW4(param_2,-1) != SBORROW4(param_2 + 1,(uint)(param_1 < 0xfffffffe)))) {
      iVar2 = FUN_0e0b272c();
      uVar4 = param_1 + iVar2;
    }
    else {
      uVar4 = -param_1 - 2;
    }
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    _DAT_2f011bc4 = _DAT_2f011ba0;
    FUN_0e0afbe4();
    FUN_0e0b02bc(_DAT_2f011ba0 + 0x18,&LAB_0e0b258e_1,param_1,param_2);
    *(byte *)(_DAT_2f011ba0 + 0xd) = *(byte *)(_DAT_2f011ba0 + 0xd) | 0x10;
    FUN_0e0aca34(uVar5);
    uVar3 = FUN_0e0b272c();
    if ((int)(uint)(uVar4 - uVar3 == 0) <= (int)-(uint)(uVar4 < uVar3)) {
      return uVar4 - uVar3;
    }
  }
  return 0;
}


