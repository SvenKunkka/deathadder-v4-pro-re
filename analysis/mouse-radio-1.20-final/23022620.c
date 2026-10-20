/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23022620. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23022620(void)

{
  undefined4 extraout_r1;
  
  if (DAT_230027ba._1_1_ == '\0') {
    if (DAT_2300297c == '\0') {
      return;
    }
    DAT_2300297c = DAT_230027ba._1_1_;
  }
  else {
    DAT_230027ba._1_1_ = '\0';
    DAT_23002a04 = 0;
    DAT_23002a4e = 0;
    DAT_23002a1a = 0;
  }
  DAT_23002978 = 0;
  DAT_23002794 = 0;
  FUN_23021af8(2);
  TIMER020_S_CC_0 = 0;
  TIMER020_S_CC_1 = 0;
  TIMER020_S_CC_2 = 0;
  TIMER020_S_CC_3 = 0;
  TIMER020_S_CC_4 = 0;
  TIMER020_S_CC_5 = 0;
  TIMER020_S_CC_6 = 0;
  TIMER020_S_CC_7 = 0;
  TIMER020_S_SHORTS = 1;
  TIMER020_S_INTENSET = 0x7f0000;
  TIMER020_S_INTENCLR = 0x800000;
  DAT_23002998 = 1000;
  DAT_2300298c = 0;
  DAT_23002990 = 0;
  DAT_23002a04 = 0x13;
  DAT_23002a4a = 0;
  DAT_23002844 = DAT_23002842;
  DAT_23002978 = 2;
  DAT_23002794 = 2;
  FUN_230218bc();
  thunk_FUN_0e089e48(0x28);
  _DAT_e000e284 = 0x100;
  TIMER020_S_TASKS_CLEAR = 1;
  thunk_FUN_0e089e2c(0x28);
  thunk_FUN_0e096a50(&DAT_23001540,extraout_r1,0x20,0,0x20,0);
  return;
}


