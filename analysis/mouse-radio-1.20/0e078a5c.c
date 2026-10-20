/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078a5c. Types and names are inferred; NOT original source. */

void FUN_0e078a5c(void)

{
  DAT_230076e4 = DAT_230076e4 + 1;
  if (300 < DAT_230076e4) {
    DAT_230076e4 = 0;
    DAT_23006b90 = thunk_FUN_0e084d3c();
    if (DAT_23006b90 != DAT_23006b8c) {
      DAT_23006b8c = DAT_23006b90;
      DAT_230076e2 = 1;
      DAT_2300779d = 1;
      return;
    }
  }
  if (DAT_2300779d == '\0') {
    return;
  }
  if ((ushort)(DAT_230076e2 + 1) < 0xbb9) {
    DAT_230076e2 = DAT_230076e2 + 1;
    return;
  }
  DAT_230076e2 = 0;
  DAT_2300779d = 0;
  if (DAT_23006b90 == 1) {
    if (DAT_230077a2 != '\0') {
      return;
    }
  }
  else if (DAT_230077a2 == '\0') {
    DAT_230076e2 = 0;
    DAT_2300779d = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_0e085ed0(0);
}


