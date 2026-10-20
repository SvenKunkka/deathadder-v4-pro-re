/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23024590. Types and names are inferred; NOT original source. */

void FUN_23024590(void)

{
  undefined4 in_r3;
  
  FUN_23021b90(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0,in_r3,in_r3);
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  TIMER020_S_SUBSCRIBE_CAPTURE_7 = 0;
  TIMER020_S_TASKS_STOP = 1;
  FUN_230217e0();
  DAT_23002978 = 0;
  DAT_23002794 = 0;
  return;
}


