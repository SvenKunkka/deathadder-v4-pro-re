/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c7f4. Types and names are inferred; NOT original source. */

void FUN_0e05c7f4(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_23006620 & 0xfffeffff;
  iVar1 = DAT_23006620 << 0xf;
  DAT_23006620 = uVar2;
  if (iVar1 < 0) {
    FUN_0e06a708(DAT_230071df,&TIMER021_S_TASKS_START);
  }
  uVar2 = DAT_23006620 & 0xfffffffb;
  iVar1 = DAT_23006620 << 0x1d;
  DAT_23006620 = uVar2;
  if (iVar1 < 0) {
    FUN_0e06a8e0(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_TXEN);
  }
  uVar2 = DAT_23006620 & 0xffffffef;
  iVar1 = DAT_23006620 << 0x1b;
  DAT_23006620 = uVar2;
  if (iVar1 < 0) {
    FUN_0e06a8e0(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_RXEN);
  }
  uVar2 = DAT_23006620;
  DAT_23006620 = DAT_23006620 & 0xfffffeff;
  if ((int)(uVar2 << 0x17) < 0) {
    FUN_0e06a8e0(DAT_230071df,&TIMER021_S_EVENTS_COMPARE_0,&RADIO_S_TASKS_TXEN);
    return;
  }
  return;
}


