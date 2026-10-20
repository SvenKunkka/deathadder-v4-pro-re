/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025778. Types and names are inferred; NOT original source. */

void FUN_23025778(void)

{
  dword dVar1;
  
  DAT_23002978 = 3;
  DAT_23002794 = 3;
  DAT_23002a0a = DAT_23002a0a + 5;
  DAT_23002a1f = 0xff;
  DAT_23002a10 = 0;
  DAT_23002a14 = 0;
  DAT_23002a0c = 0;
  DAT_230029a8 = 0;
  DAT_23002a00 = 0x18;
  DAT_230029fa = 5;
  FUN_23021744(0);
  FUN_230218a0();
  TIMER020_S_SUBSCRIBE_CAPTURE_7 = DAT_230076ef | 0x80000000;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 1;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x140;
  FUN_23021af8(4);
  FUN_23022264();
  DAT_230029b4 = 0;
  DAT_230029b8 = 0;
  DAT_230029bc = 0;
  DAT_230029c0 = 0;
  DAT_230029c4 = 0;
  DAT_230029c8 = 0;
  DAT_23002a04 = 0x18;
  DAT_2300283c = 5;
  DAT_230029cc = 0;
  TIMER020_S_CC_2 = 0x19f;
  return;
}


