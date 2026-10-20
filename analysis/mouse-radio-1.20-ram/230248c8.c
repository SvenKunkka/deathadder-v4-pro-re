/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230248c8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230248c8(void)

{
  if ((DAT_230027c5 != '\0') && (DAT_23002972 == DAT_23002a0a)) {
    DAT_230027c5 = '\0';
    FUN_2302227c();
  }
  if ((DAT_23002a0a & 0x1ff) == 0) {
    FUN_23022154();
  }
  if ((DAT_23002a0a & 0x7ff) == 0) {
    if (DAT_23002938 >> 3 < DAT_2300293a) {
      if (DAT_2300293c < 0x3c) {
        DAT_2300293c = DAT_2300293c + 1;
      }
    }
    else if (DAT_2300293c != 0) {
      DAT_2300293c = DAT_2300293c - 1;
    }
    DAT_230027c8 = 0xe < DAT_2300293c;
    _DAT_23002938 = 0;
    return;
  }
  return;
}


