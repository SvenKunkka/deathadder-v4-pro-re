/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020e84. Types and names are inferred; NOT original source. */

void FUN_23020e84(int param_1)

{
  int iVar1;
  
  if (param_1 == 2) {
    RADIO_S_MODE = 4;
  }
  else if (param_1 == 4) {
    RADIO_S_MODE = 9;
  }
  iVar1 = DAT_5302c8a0;
  if ((iVar1 == -0x80000000) || (iVar1 = DAT_5302c8a0, iVar1 == 0x58120e)) {
    DAT_5302c8a0 = 0x58090e;
  }
  DAT_5302c8a4 = 0xf8aa5f;
  DAT_5302c8a8 = 0xc00030;
  DAT_5302c8ac = 0xa80030;
  DAT_5302c7ac = 0x8672827a;
  DAT_5302c7b0 = 0x7e768672;
  DAT_5302c7b4 = 0x406007e;
  DAT_5302c7e4 = 0x412c384;
  return;
}


