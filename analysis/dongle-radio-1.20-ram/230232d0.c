/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230232d0. Types and names are inferred; NOT original source. */

void FUN_230232d0(void)

{
  dword dVar1;
  
  if (DAT_2300341c != 1) {
    RADIO_S_FREQUENCY = (uint)DAT_23003222;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    if (DAT_230032d0 == 0) {
      RADIO_S_SUBSCRIBE_RXEN = DAT_230071c6 | 0x80000000;
      return;
    }
    if ((DAT_230032d0 != 1) && (DAT_230032d0 == 2)) {
      RADIO_S_SUBSCRIBE_RXEN = DAT_230071c4 | 0x80000000;
      return;
    }
    RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
    return;
  }
  if (DAT_230032d0 == 0) {
    RADIO_S_FREQUENCY = (uint)DAT_23003222;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    RADIO_S_SUBSCRIBE_RXEN = DAT_230071c6 | 0x80000000;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x20;
    return;
  }
  if (DAT_230032d0 != 4) {
    return;
  }
  RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 & 0xffffffdf;
  return;
}


