/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027b40. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23027b40(void)

{
  if (((DAT_23007723 != '\x04') || (DAT_23006bb4 < 2)) && (DAT_23007769 == '\x01')) {
    DAT_23007767 = DAT_23007767 + '\x01';
    switch(DAT_23007767) {
    case '\x01':
      DAT_230066e0 = DAT_23007768;
      _DAT_230066e1 = 0;
      uRam230066e5 = 0;
      break;
    case '\x02':
      DAT_230066e0 = DAT_2300662d;
      break;
    case '\x03':
      DAT_230066e0 = DAT_23007768;
      break;
    case '\x04':
      DAT_23007769 = 0;
      DAT_230066e0 = DAT_2300662d;
      DAT_23007767 = 0;
      DAT_23007768 = 0;
      DAT_230076d2 = DAT_230076d2 | 1;
      return;
    }
    DAT_230076d2 = DAT_230076d2 | 1;
    return;
  }
  return;
}


