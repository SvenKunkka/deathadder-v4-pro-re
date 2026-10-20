/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020c1c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_23020c1c(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (_DAT_e0083404 << 0x1f < 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar2 = 0xffffffea;
    }
    else {
      uVar1 = param_1 & 0xffffffe0 | 0x10000000;
      do {
        do {
          _DAT_e0083410 = uVar1;
          uVar1 = _DAT_e0083410;
        } while ((int)(_DAT_e0083400 << 0x1f) < 0);
        _DAT_e0083018 = 1;
        uVar1 = _DAT_e0083410 + 0x20;
      } while (_DAT_e0083410 + 0x20 < (param_1 | 0x10000000) + param_2);
      do {
      } while ((_DAT_e0083400 & 1) != 0);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffff5;
  }
  return uVar2;
}


