/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302218c. Types and names are inferred; NOT original source. */

uint FUN_2302218c(undefined4 param_1,int param_2)

{
  if ((DAT_230027a2 == 0) || (DAT_230027a2 == 1)) {
    return (uint)*(byte *)((int)&DAT_230029d7 + param_2 * 4 + (uint)(byte)(&DAT_230029d5)[param_2]);
  }
  if ((DAT_230027a2 != 2) && (DAT_230027a2 != 3)) {
    return 0x962;
  }
  FUN_23021de0();
  DAT_23002792 = (ushort)DAT_230026c3;
  return (uint)(byte)(&DAT_0e098a14)[DAT_230026c3];
}


