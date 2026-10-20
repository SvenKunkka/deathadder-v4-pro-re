/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302b3d0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * ram_candidate_2302b3d0(void)

{
  if ((_DAT_5f9c2140 != 0) && (_DAT_5f9c2140 = 0, DAT_23004a5f - 1 < 2)) {
    DAT_23007749 = 1;
  }
  if ((_DAT_5f9c2144 != 0) && (_DAT_5f9c2144 = 0, DAT_23004a5f == 1)) {
    DAT_23007749 = DAT_23004a5f;
  }
  if (_DAT_5f9c2148 == 0) {
LAB_2302b42e:
    if (_DAT_5f9c214c != 0) {
LAB_2302b436:
      _DAT_5f9c214c = 0;
      DAT_23007749 = 1;
      if (DAT_2300774a == '\0') goto LAB_2302b44c;
      FUN_2302ba74();
      DAT_2300774a = '\0';
    }
    if (DAT_23007749 == 0) goto LAB_2302b456;
  }
  else {
    _DAT_5f9c2148 = 0;
    if (DAT_23004a5f != 1) goto LAB_2302b42e;
    DAT_23007749 = DAT_23004a5f;
    if (_DAT_5f9c214c != 0) goto LAB_2302b436;
  }
LAB_2302b44c:
  if (DAT_2300771f == '\0') {
    DAT_23007749 = 0;
  }
  else {
    FUN_23028760();
    DAT_23007749 = 0;
  }
LAB_2302b456:
  thunk_FUN_0e089ea4();
  thunk_FUN_0e089908();
  return &stack0x00000000;
}


