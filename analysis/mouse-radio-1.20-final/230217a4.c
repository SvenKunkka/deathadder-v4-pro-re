/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230217a4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230217a4(undefined4 param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    if (DAT_230076ee != '\0') {
      _DAT_5302e044 = 1;
      DAT_230076ee = 0;
      return;
    }
  }
  else if (param_2 == 1) {
    if (DAT_230076ee == '\0') {
      _DAT_5302e040 = param_2;
      DAT_230076ee = 1;
      return;
    }
  }
  else if (DAT_230076ee != '\0') {
    _DAT_5302e044 = 1;
    DAT_230076ee = '\0';
  }
  return;
}


