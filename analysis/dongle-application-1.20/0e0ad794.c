/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ad794. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0ad794(uint param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short sVar6;
  ushort uVar7;
  
  if ((param_1 < 5) && (iVar3 = *(int *)(&DAT_0e0b3b88 + param_1 * 4), iVar3 != 0)) {
    if (_DAT_2f0119f0 << 0x1d < 0) {
      return 0xfffffffb;
    }
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar7 = *(ushort *)(iVar3 + 0x18) & 7;
    if (uVar7 == 2) {
      sVar6 = *(short *)(iVar3 + 0x1a) + -1;
      *(short *)(iVar3 + 0x1a) = sVar6;
      uVar4 = 2;
      if (sVar6 == 0) {
        FUN_0e0abb44(iVar3,2,uVar5);
        return 2;
      }
    }
    else if (uVar7 == 1) {
      uVar4 = 0xfffffffb;
    }
    else {
      uVar4 = 0xffffff7a;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar4;
  }
  return 0xffffffea;
}


