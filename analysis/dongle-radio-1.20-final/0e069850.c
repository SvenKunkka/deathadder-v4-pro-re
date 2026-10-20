/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069850. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e069850(uint param_1)

{
  uint uVar1;
  
  uVar1 = 1 << (param_1 & 0xff);
  if ((uVar1 & 0xe080) == 0) {
    return 0xbad0008;
  }
  if ((~DAT_23000ab4 & 0xe080 & uVar1) != 0) {
    DAT_23000ab8 = DAT_23000ab8 | uVar1;
    _DAT_5f99c354 = uVar1;
    return 0xbad0000;
  }
  return 0xbad0004;
}


