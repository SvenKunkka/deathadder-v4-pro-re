
void FUN_0e05cc4c(dword param_1,dword param_2,undefined4 param_3,undefined4 param_4)

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
  RADIO_S_SHORTS = dVar1 | 0x21;
  RADIO_S_PACKETPTR = 0x23006630;
  FUN_0e05c9ec(param_1,param_3,0,&RADIO_S_TASKS_TXEN,param_4);
  if (param_1 == 0xf) {
    if (param_2 - 0xb < 0x10) {
      param_2 = param_2 * 5 - 0x32;
    }
    else {
      param_2 = 5;
    }
  }
  RADIO_S_FREQUENCY = param_2;
  DAT_23006628 = 0;
  DAT_23006624 = 0;
  RADIO_S_INTENSET00 = 0x800;
  if ((DAT_230071e0 != '\0') && (FUN_0e05cb44(1), DAT_230071e0 != '\0')) {
    EGU020_S_TASKS_TRIGGER_0 = 1;
    return;
  }
  RADIO_S_TASKS_RXEN = 1;
  return;
}


