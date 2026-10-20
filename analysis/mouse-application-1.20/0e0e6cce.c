/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6cce. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vector_2(void)

{
  uint uVar1;
  uint uVar2;
  
  FUN_0e0e2fd4();
  if (-1 < *(char *)(_DAT_2f0118dc + 0xe)) {
    uVar2 = _DAT_2f0118dc;
    uVar1 = _DAT_2f0118ec;
    if (_DAT_2f0118dc != _DAT_2f0118ec) {
      uVar1 = 0xe000ed00;
      uVar2 = _DAT_e000ed04 | 0x10000000;
    }
    if (_DAT_2f0118dc != _DAT_2f0118ec) {
      *(uint *)(uVar1 + 4) = uVar2;
    }
  }
  return;
}


