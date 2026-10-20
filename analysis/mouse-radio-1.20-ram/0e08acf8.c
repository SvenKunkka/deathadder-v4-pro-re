/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08acf8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08acf8(uint param_1)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  if ((param_1 < 5) && (puVar5 = (&PTR_DAT_0e09b058)[param_1], puVar5 != (undefined *)0x0)) {
    if (DAT_23006d58 << 0x1d < 0) {
      return 0xfffffffb;
    }
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    if ((*(ushort *)(puVar5 + 0x18) & 7) == 2) {
      sVar1 = *(short *)(puVar5 + 0x1a);
      *(short *)(puVar5 + 0x1a) = sVar1 + -1;
      if ((short)(sVar1 + -1) == 0) {
        FUN_0e0862f0(puVar5,2,uVar6);
        return 2;
      }
      uVar4 = 2;
    }
    else if ((*(ushort *)(puVar5 + 0x18) & 7) == 1) {
      uVar4 = 0xfffffffb;
    }
    else {
      uVar4 = 0xffffff7a;
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar4;
  }
  return 0xffffffea;
}


