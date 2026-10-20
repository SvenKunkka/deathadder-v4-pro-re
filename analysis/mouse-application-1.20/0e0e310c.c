/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e310c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e310c(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((_DAT_e000ed28 & 0x10) == 0) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x11;
  }
  if ((_DAT_e000ed28 & 8) != 0) {
    uVar1 = 0x12;
  }
  if ((int)(_DAT_e000ed28 << 0x1e) < 0) {
    if (((int)(_DAT_e000ed28 << 0x18) < 0) && (param_1 != 0)) {
      _DAT_e000ed28 = _DAT_e000ed28 & 0xffffff7f;
    }
    uVar1 = 0x13;
  }
  if ((_DAT_e000ed28 & 1) != 0) {
    uVar1 = 0x14;
  }
  if ((_DAT_e000ed28 & 0x20) != 0) {
    uVar1 = 0x15;
  }
  if ((int)(_DAT_e000ed28 << 0x1a) < 0) {
    _DAT_e000ed24 = _DAT_e000ed24 & 0xffffdfff;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff;
  *param_2 = 0;
  return uVar1;
}


