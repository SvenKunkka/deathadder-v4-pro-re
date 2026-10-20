/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c9ec. Types and names are inferred; NOT original source. */

void FUN_0e05c9ec(uint param_1,int param_2,uint param_3)

{
  short sVar1;
  dword dVar2;
  dword dVar3;
  
  RADIO_S_TIMING = 1;
  RADIO_S_CRCCNF = 0;
  RADIO_S_CRCPOLY = 0;
  RADIO_S_TXADDRESS = 0;
  RADIO_S_RXADDRESSES = 1;
  if (param_2 == 1) {
LAB_0e05ca16:
    RADIO_S_PREFIX0 = 0x6a;
    RADIO_S_BASE0 = 0x58fe811b;
  }
  else if (param_2 == 2) {
    RADIO_S_PREFIX0 = 0xcc;
    RADIO_S_BASE0 = 0xcccccccc;
  }
  else {
    if (param_2 != 0) goto LAB_0e05ca16;
    RADIO_S_PREFIX0 = 0xab;
    RADIO_S_BASE0 = 0xabababab;
  }
  if (param_3 == 0) {
    param_3 = 0xff;
  }
  param_3 = param_3 & 0xff;
  sVar1 = (short)param_3;
  if (param_1 < 7) {
    if (4 < param_1) {
      RADIO_S_CRCCNF = 0x103;
      dVar2 = 0x63800008;
      DAT_230071ae = sVar1 + 0x17;
      dVar3 = param_3 | 0x2030000;
      RADIO_S_CRCPOLY = 0;
      goto LAB_0e05ca42;
    }
    if (param_1 == 4) {
      dVar2 = 0x1000008;
      DAT_230071ae = sVar1 + 8;
      dVar3 = param_3 | 0x3040000;
      goto LAB_0e05ca42;
    }
  }
  else if (param_1 == 0xf) {
    DAT_230071ae = 0x85;
    dVar3 = 0x7f;
    dVar2 = 0x2000008;
    goto LAB_0e05ca42;
  }
  dVar2 = 8;
  DAT_230071ae = sVar1 + 7;
  dVar3 = param_3 | 0x3040000;
LAB_0e05ca42:
  RADIO_S_PCNF0 = dVar2;
  RADIO_S_PCNF1 = dVar3;
  return;
}


