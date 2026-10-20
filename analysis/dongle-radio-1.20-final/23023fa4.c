/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023fa4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23023fa4(void)

{
  dword dVar1;
  
  if (DAT_230032d0 == 0) {
    DAT_2300322c = DAT_23003224;
    _DAT_23003222 = _DAT_23003226;
    RADIO_S_FREQUENCY = _DAT_23003226 & 0xffff;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    RADIO_S_SUBSCRIBE_RXEN = DAT_230071c6 | 0x80000000;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 & 0xfff7ffff;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x20;
  }
  else {
    switch(DAT_230032d0) {
    case 1:
    case 4:
      RADIO_S_SUBSCRIBE_STOP = DAT_230071c2 | 0x80000000;
      return;
    case 2:
    case 5:
      if (DAT_23003484 == '\x01') {
        RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 | 0x80000;
        return;
      }
      DAT_2300325e = 1;
      return;
    case 3:
      RADIO_S_FREQUENCY = _DAT_23003222 & 0xffff;
      RADIO_S_BASE1 = DAT_23003244;
      RADIO_S_SUBSCRIBE_RXEN = DAT_230071c4 | 0x80000000;
      dVar1 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar1 & 0xfff7ffff;
      dVar1 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar1 | 0x20;
      return;
    }
  }
  return;
}


