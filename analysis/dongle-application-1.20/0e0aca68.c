/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0aca68. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0aca68(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  _DAT_2f011ba0 = _DAT_2f011bb0;
  _DAT_e000ed04 = 0x8000000;
  _DAT_2f0119c8 = *(undefined4 *)(_DAT_2f011bb0 + 0x80);
  uVar3 = *(undefined4 *)(_DAT_2f011bb0 + 0x84);
  *(undefined4 *)(_DAT_2f011bb0 + 0x84) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


