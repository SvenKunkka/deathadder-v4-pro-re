/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020e7c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23020e7c(undefined4 param_1,int param_2)

{
  DAT_230076e0 = (undefined2)param_2;
  if (param_2 == 1) {
    DAT_2300771f = 1;
    FUN_2302b74c();
    DAT_23007788 = 2;
    DAT_2300777f = 1;
    thunk_FUN_0e07efac();
    DAT_2300772c = 1;
    if (DAT_23007736 != '\0') {
      DAT_2300772d = 1;
      DAT_23007690 = 0;
      DAT_2300772c = 0;
      return;
    }
  }
  else {
    DAT_2300777f = 0;
    _DAT_5f9c2004 = 1;
    _DAT_5f9c200c = 1;
    DAT_2300771f = 0;
    FUN_2302b70c();
    if (DAT_23007723 == '\x01') {
      thunk_FUN_0e07eee8();
      return;
    }
  }
  return;
}


