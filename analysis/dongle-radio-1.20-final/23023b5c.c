/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023b5c. Types and names are inferred; NOT original source. */

void FUN_23023b5c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (2 < (uint)(&DAT_230033e8)[param_1 * 0x3e1]) {
    uVar1 = (&DAT_23003474)[param_1 * 0x3e1];
    uVar2 = uVar1;
    if (uVar1 < 200) {
      uVar2 = uVar1 + 1;
    }
    (&DAT_2300346e)[param_1 * 0x7c2] = (&DAT_2300346e)[param_1 * 0x7c2] + 1;
    (&DAT_23003470)[param_1 * 0x7c2] = (&DAT_23003470)[param_1 * 0x7c2] + 1;
    if (uVar1 < 200) {
      (&DAT_23003474)[param_1 * 0x3e1] = uVar2;
    }
  }
  if (param_1 != 2) {
    return;
  }
  DAT_230032ca = (ushort)(((uint)DAT_23005376 << 0x1e) >> 0x1f);
  DAT_23003222 = FUN_23021654();
  return;
}


