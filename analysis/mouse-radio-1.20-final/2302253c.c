/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302253c. Types and names are inferred; NOT original source. */

void FUN_2302253c(void)

{
  dword dVar1;
  undefined4 in_r3;
  
  DAT_23002a4e = DAT_23002a4e + 1;
  if (DAT_23002a4e == 1) {
    dVar1 = FUN_230221e0((&DAT_0e098a3c)[DAT_23002a4c]);
    RADIO_S_FREQUENCY = dVar1;
    RADIO_S_PACKETPTR = 0x23002a56;
    FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_RXEN,0x14);
    TIMER020_S_TASKS_CLEAR = 1;
    TIMER020_S_TASKS_START = 1;
  }
  else if (7 < DAT_23002a4e) {
    DAT_23002a4e = 0;
    DAT_23002a4c = DAT_23002a4c + 1;
    if (3 < DAT_23002a4c) {
      DAT_23002a4c = 0;
    }
    FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0x13,in_r3);
    return;
  }
  return;
}


