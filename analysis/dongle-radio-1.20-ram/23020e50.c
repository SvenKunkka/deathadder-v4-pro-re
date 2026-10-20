/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020e50. Types and names are inferred; NOT original source. */

void FUN_23020e50(void)

{
  dword dVar1;
  
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x100;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  return;
}


