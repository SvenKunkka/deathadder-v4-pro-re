/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b29b8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0b29b8(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_0e0ad450();
  if (iVar3 != 1) {
    return iVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(_DAT_2f013620);
  }
  setMainStackPointerLimit(_DAT_2f013624);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(_DAT_2f013628);
  }
  setProcStackPointerLimit(_DAT_2f01362c);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((_DAT_2f01363c & 1) == 1);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts((_DAT_2f013640 & 1) == 1);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(_DAT_2f013644);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setThreadModePrivileged((_DAT_2f013648 & 1) == 0);
    bVar1 = (bool)isThreadMode();
    if (bVar1) {
      cVar2 = isUsingMainStack();
      setStackMode(cVar2 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


