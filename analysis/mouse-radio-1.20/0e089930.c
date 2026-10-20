/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089930. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e089930(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = _DAT_e000ed28;
  if ((_DAT_e000ed28 & 0x2000000) == 0) {
    uVar2 = 0x1d;
  }
  else {
    uVar2 = 0x1e;
  }
  if ((_DAT_e000ed28 & 0x1000000) != 0) {
    uVar2 = 0x1f;
  }
  if ((_DAT_e000ed28 & 0x100000) != 0) {
    uVar2 = 2;
  }
  if ((_DAT_e000ed28 & 0x80000) != 0) {
    uVar2 = 0x21;
  }
  if ((_DAT_e000ed28 & 0x40000) != 0) {
    uVar2 = 0x22;
  }
  if ((_DAT_e000ed28 & 0x20000) != 0) {
    uVar2 = 0x23;
  }
  _DAT_e000ed28 = ~(~(_DAT_e000ed28 << 0x10) >> 0x10);
  if ((uVar1 & 0x10000) != 0) {
    uVar2 = 0x24;
  }
  return uVar2;
}


