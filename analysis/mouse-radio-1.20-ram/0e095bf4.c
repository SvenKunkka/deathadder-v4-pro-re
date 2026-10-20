/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095bf4. Types and names are inferred; NOT original source. */

void FUN_0e095bf4(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1d) < 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfb;
    FUN_0e0958bc();
    if (iVar3 == 0) {
      uVar2 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar2 = getCurrentExceptionNumber();
        uVar2 = uVar2 & 0x1ff;
      }
      if ((uVar2 == 0) && (DAT_23007664 != DAT_23007654)) {
        FUN_0e089d4c();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


