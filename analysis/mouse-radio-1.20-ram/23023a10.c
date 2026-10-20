/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23023a10. Types and names are inferred; NOT original source. */

void FUN_23023a10(void)

{
  uint uVar1;
  
  if (2 < DAT_23002794) {
    DAT_23002a0c = DAT_23002a0c + 1;
    if ((byte)(&DAT_230029d1)[DAT_23002836] < 3) {
      (&DAT_230029d1)[DAT_23002836] = (&DAT_230029d1)[DAT_23002836] + 1;
    }
    DAT_23002a0a = DAT_23002a0a + 1;
    uVar1 = DAT_23002a10;
    if (DAT_23002a10 < 200) {
      uVar1 = DAT_23002a10 + 1;
    }
    if (DAT_23002a10 < 200) {
      DAT_23002a10 = uVar1;
    }
    DAT_23002836 = (ushort)(((uint)DAT_23002a0a << 0x1e) >> 0x1f);
    if (DAT_230029d0 != '\0') {
      DAT_230029d0 = DAT_230029d0 + -1;
    }
    if (DAT_230029cc != 0) {
      DAT_230029cc = DAT_230029cc + -1;
    }
    DAT_2300278c = FUN_2302218c();
    if ((DAT_230029ae != 0) && (DAT_230029b0 == DAT_23002a0a)) {
      DAT_230029ac = DAT_230029ae;
      DAT_230029bc = 0;
      DAT_230029c0 = 0;
      DAT_230029c4 = 0;
      DAT_230029c8 = 0;
      DAT_230029ae = 0;
      DAT_230029b0 = 0;
      DAT_230029b4 = 0;
      DAT_230029b8 = 0;
      DAT_230029cc = 0;
      return;
    }
  }
  return;
}


