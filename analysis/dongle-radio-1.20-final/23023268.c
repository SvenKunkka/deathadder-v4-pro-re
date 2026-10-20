/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023268. Types and names are inferred; NOT original source. */

void FUN_23023268(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_230032d0;
  if (DAT_2300341c == 1) {
    if (uVar1 == 0) {
      DAT_23006274 = uVar1;
      RADIO_S_SUBSCRIBE_RXEN = 0;
      return;
    }
    if ((uVar1 < 3) || (uVar1 == 3)) {
      return;
    }
    if (uVar1 != 4) {
      return;
    }
  }
  else if ((uVar1 == 0) || ((uVar1 != 1 && (uVar1 == 2)))) {
    DAT_23006274 = 0;
    RADIO_S_SUBSCRIBE_RXEN = 0;
    return;
  }
  RADIO_S_SUBSCRIBE_TXEN = 0;
  DAT_23006274 = 2;
  return;
}


