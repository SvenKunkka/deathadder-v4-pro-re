/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302c0f8. Types and names are inferred; NOT original source. */

undefined4
ram_candidate_2302c0f8
          (undefined **param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  if (param_2 == 3) {
    if ((param_1 == &PTR_s_hid_dev_0_0e097958) && (param_4 == 0x5a)) {
      thunk_FUN_0e09739c(&DAT_23003efc,param_5);
      DAT_23003efc = 1;
      DAT_23007715 = 1;
      return 0;
    }
  }
  else if ((param_2 == 2) &&
          (((param_1 == &PTR_s_hid_dev_2_0e097930 && (param_4 == 1)) ||
           ((param_1 == &PTR_s_hid_dev_1_0e097944 && (param_4 == 2)))))) {
    return 0;
  }
  return 0xffffff7a;
}


