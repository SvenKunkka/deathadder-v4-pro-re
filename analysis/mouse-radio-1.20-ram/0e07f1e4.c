/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f1e4. Types and names are inferred; NOT original source. */

void FUN_0e07f1e4(void)

{
  if (DAT_2300777c != '\0') {
    if (0xfa < DAT_230076cc) {
      DAT_230076cc = 0;
      switch(DAT_23007756) {
      case '\0':
      case '\x02':
        FUN_0e07f000();
        DAT_23007756 = DAT_23007756 + '\x01';
        break;
      case '\x01':
        DAT_23007743 = 0;
        DAT_23007741 = 0;
        DAT_23007742 = 0;
        DAT_23007756 = 2;
        return;
      case '\x03':
        DAT_2300777c = 0;
        thunk_FUN_23026b2c();
        FUN_0e07eda0();
        return;
      default:
        DAT_23007756 = 0;
        return;
      }
    }
    return;
  }
  return;
}


