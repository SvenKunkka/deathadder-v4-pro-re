/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23022c3c. Types and names are inferred; NOT original source. */

void FUN_23022c3c(void)

{
  dword dVar1;
  
  FUN_230214c4(0);
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x100;
  FUN_23021a04();
  DAT_23002798 = 2;
  FUN_23021af8();
  return;
}


