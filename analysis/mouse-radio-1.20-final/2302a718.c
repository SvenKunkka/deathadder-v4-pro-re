/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a718. Types and names are inferred; NOT original source. */

void thunk_FUN_23026da0(void)

{
  if (DAT_230077aa == '\0') {
    return;
  }
  FUN_23028290();
  if ((char)DAT_23004a50 == '\0') {
    if (DAT_23007723 == '\x01') {
      if (DAT_2300777f != '\0') {
        if (DAT_23007788 != '\0') {
          DAT_23007788 = DAT_23007788 + -1;
          DAT_230076ea = 0;
          DAT_230076e8 = 0;
        }
        DAT_230076d6 = DAT_230076ea + DAT_230076d6;
        DAT_230076d4 = DAT_230076e8 + DAT_230076d4;
      }
    }
    else {
      DAT_230076d6 = DAT_230076d6 + DAT_230076ea;
      DAT_230076d4 = DAT_230076d4 + DAT_230076e8;
    }
  }
  else if (((char)DAT_23004a50 == '\x01') && (DAT_230076ea != 0 || DAT_230076e8 != 0)) {
    ram_candidate_23020000();
    DAT_230076d6 = DAT_230076d6 + DAT_230076a2;
    DAT_230076d4 = DAT_230076d4 + DAT_230076a0;
  }
  DAT_230076ea = 0;
  DAT_230076a2 = 0;
  DAT_230076e8 = 0;
  DAT_230076a0 = 0;
  if (DAT_23001504._1_1_ == 'U') {
    if (DAT_230076d6 != 0 || DAT_230076d4 != 0) {
      DAT_230076d2 = DAT_230076d2 | 4;
      return;
    }
  }
  else {
    DAT_230076d4 = 0;
    DAT_230076d6 = 0;
  }
  return;
}


