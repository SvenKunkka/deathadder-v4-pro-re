/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089994. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e089994(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((_DAT_e000ed28 & 0x1000) == 0) {
    uVar1 = 0x16;
  }
  else {
    uVar1 = 0x17;
  }
  if ((_DAT_e000ed28 & 0x800) != 0) {
    uVar1 = 0x18;
  }
  if ((int)(_DAT_e000ed28 << 0x16) < 0) {
    if (((int)(_DAT_e000ed28 << 0x10) < 0) && (param_1 != 0)) {
      _DAT_e000ed28 = _DAT_e000ed28 & 0xffff7fff;
    }
    uVar1 = 0x19;
  }
  if ((_DAT_e000ed28 & 0x400) != 0) {
    uVar1 = 0x1a;
  }
  if ((int)(_DAT_e000ed28 << 0x17) < 0) {
    uVar1 = 0x1b;
  }
  else if ((_DAT_e000ed28 & 0x2000) != 0) {
    uVar1 = 0x1c;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff00;
  *param_2 = 0;
  return uVar1;
}


