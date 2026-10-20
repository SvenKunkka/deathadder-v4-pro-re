/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e763c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0e763c(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_0e0e3e1c();
  if (iVar3 != 1) {
    return iVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(_DAT_2f013158);
  }
  setMainStackPointerLimit(_DAT_2f01315c);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(_DAT_2f013160);
  }
  setProcStackPointerLimit(_DAT_2f013164);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((_DAT_2f013174 & 1) == 1);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts((_DAT_2f013178 & 1) == 1);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(_DAT_2f01317c);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setThreadModePrivileged((_DAT_2f013180 & 1) == 0);
    bVar1 = (bool)isThreadMode();
    if (bVar1) {
      cVar2 = isUsingMainStack();
      setStackMode(cVar2 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


