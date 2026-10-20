/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230221ec. Types and names are inferred; NOT original source. */

ushort FUN_230221ec(int param_1)

{
  ushort uVar1;
  
  if ((DAT_230027a2 == 0) || (DAT_230027a2 == 1)) {
    uVar1 = *(ushort *)((int)&DAT_23002a14 + param_1 * 2);
    if (0xe < uVar1) {
      uVar1 = 0xf;
    }
    return uVar1 & 0xff;
  }
  if ((DAT_230027a2 != 2) && (DAT_230027a2 != 3)) {
    return 0;
  }
  uVar1 = *(ushort *)(&DAT_2300289e + (uint)DAT_23002792 * 2);
  if (0xe < uVar1) {
    uVar1 = 0xf;
  }
  return uVar1 & 0xff;
}


