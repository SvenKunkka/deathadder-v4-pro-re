/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026d78. Types and names are inferred; NOT original source. */

undefined4
ram_candidate_23026d78(undefined **param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  if (param_2 == 3) {
    if ((param_1 == &PTR_s_hid_dev_0_0e06f6a4) && (param_4 == 0x5a)) {
      thunk_FUN_0e06f35c(&DAT_23002d1d,param_5 + 1,0x59);
      DAT_23002d1c = 1;
      DAT_230071bb = 1;
      FUN_230205ec();
      return 0;
    }
  }
  else if ((param_2 == 2) &&
          (((param_1 == &PTR_s_hid_dev_2_0e06f67c && (param_4 == 1)) ||
           ((param_1 == &PTR_s_hid_dev_1_0e06f690 && (param_4 == 2)))))) {
    return 0;
  }
  return 0xffffff7a;
}


