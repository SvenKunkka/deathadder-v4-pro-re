/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cac4. Types and names are inferred; NOT original source. */

void FUN_0e05cac4(int param_1,int param_2,int param_3)

{
  FUN_0e05c9ec();
  if (param_1 == 0xf) {
    DAT_23006730 = 0x7e;
  }
  else if (param_3 == 0) {
    DAT_23006730 = 0xff;
  }
  else {
    DAT_23006730 = (undefined1)param_3;
  }
  if (param_2 == 1) {
    FUN_0e06f3aa(&DAT_23006731,0xf0,0xff);
    RADIO_S_PACKETPTR = 0x23006730;
    return;
  }
  if (param_2 == 2) {
    FUN_0e06f3aa(&DAT_23006731,0xcc,0xff);
    RADIO_S_PACKETPTR = 0x23006730;
    return;
  }
  if (param_2 != 0) {
    FUN_0e06f3aa(&DAT_23006731,param_2,0xff);
    RADIO_S_PACKETPTR = 0x23006730;
    return;
  }
  FUN_0e0621b8(&DAT_23006731,0xff);
  RADIO_S_PACKETPTR = 0x23006730;
  return;
}


