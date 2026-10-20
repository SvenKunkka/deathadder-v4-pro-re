/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ae84. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08ae84(uint param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  undefined4 uVar6;
  ushort uVar7;
  
  if ((param_1 < 5) && (iVar4 = *(int *)(DAT_0e08aeac + param_1 * 4), iVar4 != 0)) {
    if (*DAT_0e08aeb0 << 0x1d < 0) {
      return 0xfffffffb;
    }
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar7 = *(ushort *)(iVar4 + 0x18) & 7;
    if (uVar7 == 2) {
      sVar5 = *(short *)(iVar4 + 0x1a) + -1;
      *(short *)(iVar4 + 0x1a) = sVar5;
      if (sVar5 == 0) {
        FUN_0e08647c(iVar4,2,uVar6);
        return 2;
      }
      uVar3 = 2;
    }
    else if (uVar7 == 1) {
      uVar3 = 0xfffffffb;
    }
    else {
      uVar3 = 0xffffff7a;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar3;
  }
  return 0xffffffea;
}


