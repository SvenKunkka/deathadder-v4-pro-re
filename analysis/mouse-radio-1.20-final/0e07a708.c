/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a708. Types and names are inferred; NOT original source. */

void FUN_0e07a708(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  uint uVar1;
  
  FUN_0e07a3b8();
  if (param_1 == 0) {
    FUN_0e092628(DAT_23007711,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_TXEN);
    uVar1 = 4;
  }
  else {
    FUN_0e092628(DAT_23007711,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_RXEN);
    uVar1 = 0x10;
  }
  DAT_230038a0 = DAT_230038a0 | uVar1;
  FUN_0e092568(DAT_23007711,&TIMER021_S_TASKS_START);
  DAT_230038a0 = DAT_230038a0 | 0x10000;
  FUN_0e0929f0(1 << DAT_23007711,extraout_r1,0,param_4);
  return;
}


