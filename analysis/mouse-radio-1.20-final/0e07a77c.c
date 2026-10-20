/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a77c. Types and names are inferred; NOT original source. */

void FUN_0e07a77c(dword param_1,undefined4 param_2,dword param_3)

{
  dword dVar1;
  
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
  RADIO_S_MODE = param_1;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 1;
  FUN_0e07a4c0(param_2);
  if (param_1 == 0xf) {
    if (param_3 - 0xb < 0x10) {
      param_3 = param_3 * 5 - 0x32;
    }
    else {
      param_3 = 5;
    }
  }
  RADIO_S_FREQUENCY = param_3;
  if ((DAT_23007712 != '\0') && (FUN_0e07a708(0), DAT_23007712 != '\0')) {
    EGU020_S_TASKS_TRIGGER_0 = 1;
    return;
  }
  RADIO_S_TASKS_TXEN = 1;
  return;
}


