/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23024408. Types and names are inferred; NOT original source. */

ushort FUN_23024408(void)

{
  ushort uVar1;
  int iVar2;
  
  if (DAT_230029ac == 1) {
    if (DAT_2300283c != 0) {
      if (DAT_2300283c == 1) {
LAB_23024460:
        if (DAT_23002671 != '\0') {
          return 1;
        }
        if (DAT_23002a26 == '\x01') {
          return 0;
        }
        uVar1 = FUN_230216e0(0,1);
        return (uVar1 ^ 1) & 0xff;
      }
      if (DAT_2300283c == 2) {
        if (DAT_23002671 != '\0') {
          return 1;
        }
        if (DAT_23002a26 == '\x01') {
          return 1;
        }
        uVar1 = FUN_230216b0();
        return (uVar1 ^ 1) & 0xff;
      }
      if (DAT_2300283c == 3) goto LAB_23024460;
      goto LAB_2302442e;
    }
    if (DAT_23002671 != '\0') {
      return 1;
    }
  }
  iVar2 = FUN_230216b0(0);
  if (iVar2 == 0) {
    return 1;
  }
LAB_2302442e:
  if (DAT_230029d0 != '\0') {
    return 1;
  }
  if (DAT_23002794 == 3) {
    if ((DAT_2300283c == 0) && (2 < (byte)(&DAT_230029d1)[DAT_23002836])) {
      return ~DAT_23002a0a & 1;
    }
  }
  else if (DAT_2300283c == 0) {
    return (ushort)((DAT_23002a0a & 0x1d) == 0);
  }
  return 0;
}


