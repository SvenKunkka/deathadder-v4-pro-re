/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084fa8. Types and names are inferred; NOT original source. */

void FUN_0e084fa8(int param_1)

{
  if (param_1 == 0) {
    if ((1 << (uint)DAT_2300066c & **(uint **)(DAT_23000668 + 0x10)) != 0) goto LAB_0e084fdc;
  }
  else {
    if (DAT_230077a2 == '\0') {
      return;
    }
    if ((1 << (uint)DAT_2300066c & **(uint **)(DAT_23000668 + 0x10)) == 0) {
LAB_0e084fdc:
      (**(code **)(*(int *)(DAT_23000668 + 8) + 0x10))();
      return;
    }
  }
  (**(code **)(*(int *)(DAT_23000668 + 8) + 0xc))();
  return;
}


