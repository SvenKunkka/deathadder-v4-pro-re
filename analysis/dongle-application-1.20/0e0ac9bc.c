/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac9bc. Types and names are inferred; NOT original source. */

void FUN_0e0ac9bc(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts(0);
  }
  FUN_0e0ac998();
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 0x20;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(&DAT_e000e100 + iVar2 * 4) = 0xffffffff;
  } while (iVar3 != 0x10);
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 0x60;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(&DAT_e000e100 + iVar2 * 4) = 0xffffffff;
  } while (iVar3 != 0x10);
  enableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


