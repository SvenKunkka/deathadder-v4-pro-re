/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d4ac. Types and names are inferred; NOT original source. */

void FUN_0e07d4ac(uint param_1)

{
  if (param_1 < 0x21) {
    switch(param_1) {
    case 2:
      DAT_2300768e = 0;
      DAT_23007726 = DAT_23007726 | 1;
      return;
    case 4:
      DAT_2300768e = 0;
      DAT_23007726 = DAT_23007726 | 2;
      return;
    case 8:
      DAT_2300768e = 0;
      DAT_23007726 = DAT_23007726 | 4;
      return;
    case 0x20:
      DAT_2300768e = 100;
      DAT_23007726 = DAT_23007726 | 8;
      return;
    }
  }
  else {
    if (param_1 != 0x40) {
      return;
    }
    DAT_2300768e = 100;
    DAT_23007726 = DAT_23007726 | 0x10;
  }
  return;
}


