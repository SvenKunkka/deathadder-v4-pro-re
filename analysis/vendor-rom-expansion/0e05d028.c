
void FUN_0e05d028(void)

{
  dword dVar1;
  int iVar2;
  
  FUN_0e069f5c(&DAT_0e06fd14);
  FUN_0e069f7c(&DAT_0e06fd14);
  DAT_230071e0 = 0;
  iVar2 = FUN_0e06aacc(DAT_230071df);
  if (iVar2 != 0) {
    FUN_0e06ab4c(1 << (uint)DAT_230071df);
  }
  FUN_0e05c7f4();
  RADIO_S_SHORTS = 0;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  RADIO_S_TASKS_DISABLE = 1;
  do {
    dVar1 = RADIO_S_EVENTS_DISABLED;
  } while (dVar1 == 0);
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  return;
}


