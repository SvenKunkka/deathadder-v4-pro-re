/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07c98c. Types and names are inferred; NOT original source. */

void FUN_0e07c98c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_23003f03 == -0x7f) {
    uVar1 = 1;
    uVar2 = 0;
    DAT_23003f04 = 1;
    uVar3 = (uint)DAT_23004478;
    do {
      if (((int)uVar3 >> (uVar2 & 0xff)) << 0x1f < 0) {
        (&DAT_23003f04)[uVar1] = (char)uVar2;
        uVar1 = uVar1 + 1 & 0xff;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 8);
    DAT_23003f01 = (char)uVar1;
    return;
  }
  if ((DAT_23003f03 != -0x76) && (DAT_23003f03 != -0x80)) {
    DAT_23003efc = 3;
    return;
  }
  DAT_23003f04 = 1;
  return;
}


