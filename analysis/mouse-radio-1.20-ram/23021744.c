/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23021744. Types and names are inferred; NOT original source. */

void FUN_23021744(int param_1)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = DAT_23002798;
  (&DAT_230029f9)[param_1 * 0xee0] = 0;
  if ((sVar2 == 4) || (sVar2 == 8)) {
    if (((&DAT_230029ac)[param_1 * 0x770] == 4) || (7 < (ushort)(&DAT_230029ac)[param_1 * 0x770])) {
      (&DAT_230029f9)[param_1 * 0xee0] = 1;
      return;
    }
  }
  else {
    uVar1 = (&DAT_230029ac)[param_1 * 0x770];
    if ((((uVar1 == 1) || (uVar1 == 2)) || (uVar1 == 4)) || (7 < uVar1)) {
      (&DAT_230029f9)[param_1 * 0xee0] = 1;
    }
  }
  return;
}


