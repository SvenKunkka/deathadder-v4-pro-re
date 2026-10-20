/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230268c8. Types and names are inferred; NOT original source. */

void ram_candidate_230268c8(void)

{
  DAT_2300772e = DAT_2300772e + '\x01';
  if ((DAT_23007723 == '\x01') && (DAT_230077a2 == '\0')) {
    DAT_230076c8 = DAT_230076c8 + 1;
    if (DAT_230076c6 != 0) {
      DAT_230076c6 = DAT_230076c6 + -1;
    }
    if (DAT_23004960 < DAT_230076c8) {
      if (DAT_2300776f != '\0') {
        thunk_FUN_0e096ac4(&DAT_23001b80);
        DAT_2300776f = '\0';
      }
      DAT_2300772b = 1;
      return;
    }
  }
  return;
}


