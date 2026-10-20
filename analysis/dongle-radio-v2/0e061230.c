/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061230. Types and names are inferred; NOT original source. */

void FUN_0e061230(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = DAT_0e061290;
  disableIRQinterrupts();
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts(0);
  }
  uVar2 = *(uint *)(DAT_0e061290 + 0x90);
  if ((uVar2 & 0xff00) != 0) {
    do {
      *(uint *)(iVar6 + 0x98) = uVar4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar6 + 0xa0) = 0;
    } while ((uVar2 & 0xffff) >> 8 != uVar4);
  }
  iVar6 = DAT_0e061294;
  iVar5 = 0;
  do {
    iVar3 = iVar5 + 0x20;
    iVar5 = iVar5 + 1;
    *(undefined4 *)(iVar6 + iVar3 * 4) = 0xffffffff;
    iVar3 = DAT_0e061294;
  } while (iVar5 != 0x10);
  iVar6 = 0;
  do {
    iVar5 = iVar6 + 0x60;
    iVar6 = iVar6 + 1;
    *(undefined4 *)(iVar3 + iVar5 * 4) = 0xffffffff;
  } while (iVar6 != 0x10);
  enableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


