/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e071fd4. Types and names are inferred; NOT original source. */

void FUN_0e071fd4(void)

{
  undefined4 in_r3;
  
  FUN_0e06e32c(&DAT_23002a04,&RADIO_S_TASKS_DISABLE,0,in_r3,in_r3);
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_START = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  TIMER020_S_SUBSCRIBE_CAPTURE_7 = 0;
  TIMER020_S_CC_6 = 0;
  TIMER020_S_TASKS_STOP = 1;
  FUN_0e06df7c();
  DAT_23002978 = 0;
  DAT_23002794 = 0;
  return;
}


