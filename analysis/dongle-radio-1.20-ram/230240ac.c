/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230240ac. Types and names are inferred; NOT original source. */

void FUN_230240ac(int param_1)

{
  dword dVar1;
  
  if (DAT_23003468 == 0xb) {
    if (param_1 == 4) {
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      TIMER020_S_TASKS_CAPTURE_7 = 1;
      if (DAT_230032d0 == 0) {
        dVar1 = TIMER020_S_CC_7;
        if (0xc7f < dVar1) {
          DAT_23003468 = 0xc;
          return;
        }
      }
      else {
        if (DAT_230032d0 != 3) {
          DAT_23003050._0_1_ = 0;
          DAT_23003468 = 0xc;
          return;
        }
        dVar1 = TIMER020_S_CC_7;
        if (dVar1 < 0x1f41) {
          DAT_23003050._0_1_ = 0;
          DAT_23003468 = 0xc;
          return;
        }
      }
      FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_RXEN,0xc);
      return;
    }
    if (param_1 == 1) goto LAB_23024102;
    if (param_1 == 2) {
      RADIO_S_SUBSCRIBE_STOP = 0;
      dVar1 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar1 & 0xffffffdf;
      return;
    }
  }
  else {
    if (DAT_23003468 != 0xc) {
      return;
    }
    if (param_1 == 4) {
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      return;
    }
    if (param_1 == 1) {
LAB_23024102:
      RADIO_S_SUBSCRIBE_RXEN = 0;
      return;
    }
    if (param_1 == 2) {
      RADIO_S_SUBSCRIBE_STOP = 0;
      dVar1 = RADIO_S_SHORTS;
      DAT_23003468 = 0xb;
      RADIO_S_SHORTS = dVar1 & 0xffffffdf;
      return;
    }
  }
  return;
}


