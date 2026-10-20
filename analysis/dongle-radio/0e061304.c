/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061304. Types and names are inferred; NOT original source. */

void FUN_0e061304(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = DAT_0e061344;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar5 = *(int *)(DAT_0e061340 + 0x14);
  *(int *)(DAT_0e061340 + 8) = iVar5;
  *(undefined4 *)(iVar3 + 4) = 0x8000000;
  *DAT_0e061348 = *(undefined4 *)(iVar5 + 0x84);
  uVar4 = *(undefined4 *)(iVar5 + 0x88);
  *(undefined4 *)(iVar5 + 0x88) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


