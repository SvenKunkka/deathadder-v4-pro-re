/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07ec68. Types and names are inferred; NOT original source. */

void FUN_0e07ec68(void)

{
  byte bVar1;
  byte *pbVar2;
  
  if ((*DAT_0e07eccc == '\0') && (*DAT_0e07ecd0 == '\0')) {
    if (*DAT_0e07ecd4 == '\0') {
      if ((int)((uint)*DAT_0e07ecd8 << 0x1e) < 0) {
        FUN_0e07e81c();
      }
      FUN_0e07f674();
      FUN_0e07e254();
      FUN_0e07f1ec();
      FUN_0e07f0dc();
      FUN_0e07f064();
      FUN_0e07f5a4();
      FUN_0e07f2d0();
    }
    else {
      FUN_0e07f370();
      FUN_0e07f2d0();
    }
  }
  pbVar2 = DAT_0e07ecdc;
  bVar1 = *DAT_0e07ecdc;
  *DAT_0e07ecdc = bVar1 + 1;
  if ((byte)(bVar1 + 1) < 0x14) {
    return;
  }
  FUN_0e079b78();
  *pbVar2 = 0;
  return;
}


