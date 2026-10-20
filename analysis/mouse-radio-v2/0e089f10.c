/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089f10. Types and names are inferred; NOT original source. */

void FUN_0e089f10(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = DAT_0e089f50;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar5 = *(int *)(DAT_0e089f4c + 0x18);
  *(int *)(DAT_0e089f4c + 8) = iVar5;
  *(undefined4 *)(iVar3 + 4) = 0x8000000;
  *DAT_0e089f54 = *(undefined4 *)(iVar5 + 0x84);
  uVar4 = *(undefined4 *)(iVar5 + 0x88);
  *(undefined4 *)(iVar5 + 0x88) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


