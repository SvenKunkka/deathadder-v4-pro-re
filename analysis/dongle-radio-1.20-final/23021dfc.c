/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021dfc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23021dfc(int param_1)

{
  dword dVar1;
  
  DAT_23003234 = 2;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x100;
  FUN_23020e84(2);
  FUN_23020d5c();
  if ((DAT_23003468 < 0xb) && (DAT_230043ec < 0xb)) {
    _DAT_23005349 = 0;
    DAT_23005380 = 0;
    DAT_23005370 = 0xb;
  }
  (&DAT_2300353c)[param_1 * 0xf84] = 0;
  (&DAT_23003542)[param_1 * 0xf84] = 0;
  return;
}


