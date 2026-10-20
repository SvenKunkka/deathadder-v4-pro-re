/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a3b8. Types and names are inferred; NOT original source. */

void FUN_0e07a3b8(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_230038a0 & 0xfffeffff;
  iVar1 = DAT_230038a0 << 0xf;
  DAT_230038a0 = uVar2;
  if (iVar1 < 0) {
    FUN_0e0925d0(DAT_23007711,&TIMER021_S_TASKS_START);
  }
  uVar2 = DAT_230038a0 & 0xfffffffb;
  iVar1 = DAT_230038a0 << 0x1d;
  DAT_230038a0 = uVar2;
  if (iVar1 < 0) {
    FUN_0e0927a8(DAT_23007711,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_TXEN);
  }
  uVar2 = DAT_230038a0 & 0xffffffef;
  iVar1 = DAT_230038a0 << 0x1b;
  DAT_230038a0 = uVar2;
  if (iVar1 < 0) {
    FUN_0e0927a8(DAT_23007711,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_RXEN);
  }
  uVar2 = DAT_230038a0;
  DAT_230038a0 = DAT_230038a0 & 0xfffffeff;
  if ((int)(uVar2 << 0x17) < 0) {
    FUN_0e0927a8(DAT_23007711,&TIMER021_S_EVENTS_COMPARE_0,&RADIO_S_TASKS_TXEN);
    return;
  }
  return;
}


