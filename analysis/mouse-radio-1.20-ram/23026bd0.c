/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23026bd0. Types and names are inferred; NOT original source. */

void FUN_23026bd0(void)

{
  if (DAT_23007723 == 4) {
    if (DAT_2300779e != '\0') {
      DAT_23007783 = DAT_23004a5d;
      DAT_23007782 = 0x50;
      DAT_23007784 = DAT_23007723;
      DAT_23007780 = 8;
      return;
    }
    DAT_23007783 = DAT_23004a5c;
    DAT_23007784 = 1;
    DAT_23007782 = 10;
    DAT_23007780 = 1;
    return;
  }
  if (DAT_23007723 == 1) {
    if (DAT_23004a5f == 1) {
      DAT_23007783 = DAT_23004a5f;
      DAT_23007780 = 8;
      DAT_23007782 = 0x50;
      DAT_23007784 = 4;
    }
    else if (DAT_23004a5f == 2) {
      DAT_23007783 = DAT_23007723;
      DAT_23007784 = DAT_23004a5f;
      DAT_23007782 = 0x28;
      DAT_23007780 = 4;
    }
    else {
      if (DAT_23004a5f == 4) {
        DAT_23007780 = 2;
        DAT_23007782 = 0x14;
        DAT_23007783 = DAT_23007723;
        DAT_23007784 = DAT_23007723;
        return;
      }
      DAT_23007783 = DAT_23004a5f >> 2;
      DAT_23007782 = 0x14;
      DAT_23007780 = 2;
      DAT_23007784 = DAT_23007723;
    }
  }
  return;
}


