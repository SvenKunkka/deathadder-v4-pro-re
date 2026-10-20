/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07abec. Types and names are inferred; NOT original source. */

void FUN_0e07abec(void)

{
  dword dVar1;
  int iVar2;
  
  FUN_0e0976d8(&DAT_0e098b6c);
  FUN_0e0976a8(&DAT_0e098b6c);
  DAT_23007712 = 0;
  iVar2 = FUN_0e092994(DAT_23007711);
  if (iVar2 != 0) {
    FUN_0e092a14(1 << (uint)DAT_23007711);
  }
  FUN_0e07a3b8();
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


