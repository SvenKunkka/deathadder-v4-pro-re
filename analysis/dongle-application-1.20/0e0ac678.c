/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ac678. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0ac678(void)

{
  undefined4 uVar1;
  
  if ((_DAT_e000ed28 & 0x2000000) == 0) {
    uVar1 = 0x1d;
  }
  else {
    uVar1 = 0x1e;
  }
  if ((_DAT_e000ed28 & 0x1000000) != 0) {
    uVar1 = 0x1f;
  }
  if ((_DAT_e000ed28 & 0x100000) != 0) {
    uVar1 = 2;
  }
  if ((_DAT_e000ed28 & 0x80000) != 0) {
    uVar1 = 0x21;
  }
  if ((_DAT_e000ed28 & 0x40000) != 0) {
    uVar1 = 0x22;
  }
  if ((_DAT_e000ed28 & 0x20000) != 0) {
    uVar1 = 0x23;
  }
  if ((_DAT_e000ed28 & 0x10000) != 0) {
    uVar1 = 0x24;
  }
  _DAT_e000ed28 = ~(~(_DAT_e000ed28 << 0x10) >> 0x10);
  return uVar1;
}


