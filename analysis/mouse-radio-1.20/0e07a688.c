/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a688. Types and names are inferred; NOT original source. */

void FUN_0e07a688(int param_1,int param_2,int param_3)

{
  FUN_0e07a5b0();
  if (param_1 == 0xf) {
    DAT_230039b0 = 0x7e;
  }
  else if (param_3 == 0) {
    DAT_230039b0 = 0xff;
  }
  else {
    DAT_230039b0 = (undefined1)param_3;
  }
  if (param_2 == 1) {
    FUN_0e0973ea(&DAT_230039b1,0xf0,0xff);
    RADIO_S_PACKETPTR = 0x230039b0;
    return;
  }
  if (param_2 == 2) {
    FUN_0e0973ea(&DAT_230039b1,0xcc,0xff);
    RADIO_S_PACKETPTR = 0x230039b0;
    return;
  }
  if (param_2 != 0) {
    FUN_0e0973ea(&DAT_230039b1,param_2,0xff);
    RADIO_S_PACKETPTR = 0x230039b0;
    return;
  }
  FUN_0e0976d0(&DAT_230039b1,0xff);
  RADIO_S_PACKETPTR = 0x230039b0;
  return;
}


