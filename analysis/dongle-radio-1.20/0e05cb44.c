/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cb44. Types and names are inferred; NOT original source. */

void FUN_0e05cb44(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  uint uVar1;
  
  FUN_0e05c7f4();
  if (param_1 == 0) {
    FUN_0e06a760(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_TXEN);
    uVar1 = 4;
  }
  else {
    FUN_0e06a760(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_RXEN);
    uVar1 = 0x10;
  }
  DAT_23006620 = DAT_23006620 | uVar1;
  FUN_0e06a6a0(DAT_230071df,&TIMER021_S_TASKS_START);
  DAT_23006620 = DAT_23006620 | 0x10000;
  FUN_0e06ab28(1 << DAT_230071df,extraout_r1,0,param_4);
  return;
}


