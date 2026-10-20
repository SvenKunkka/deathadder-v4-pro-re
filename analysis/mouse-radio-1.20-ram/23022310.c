/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23022310. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_23022310(void)

{
  bool bVar1;
  short sVar2;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined4 local_14;
  
  if (0x17 < DAT_23002a04) goto joined_r0x2302237a;
  if (DAT_23002a04 < 0x16) {
    if (DAT_23002a04 == 0x13) {
      RADIO_S_EVENTS_ADDRESS = 0;
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
      TIMER020_S_TASKS_CLEAR = 1;
      TIMER020_S_TASKS_START = 1;
      TIMER020_S_SUBSCRIBE_CLEAR = DAT_230076ef | 0x80000000;
      FUN_2302253c();
      goto joined_r0x2302237a;
    }
    if (DAT_23002a04 != 0x14) goto joined_r0x2302237a;
    if ((DAT_23002a50 == 0) ||
       (sVar2 = DAT_23002a50 + -1, bVar1 = DAT_23002a50 != 1, DAT_23002a50 = sVar2, bVar1)) {
      FUN_2302253c();
      goto joined_r0x2302237a;
    }
  }
  else {
    DAT_23002a52 = DAT_23002a52 + 1;
    if (DAT_23002a52 < 5) goto joined_r0x2302237a;
  }
  FUN_23022c8c();
  DAT_23002a04 = 0x13;
  DAT_23002a4a = 0;
joined_r0x2302237a:
  DAT_23002998 = DAT_23002998 + -1;
  if (DAT_23002998 == 0) {
    RADIO_S_TASKS_DISABLE = 1;
    DAT_23002998 = 1000;
    FUN_230217f0();
    thunk_FUN_0e096ac4(&DAT_23001540);
    thunk_FUN_0e096ac4(&DAT_23001540);
    FUN_23022d88(0);
    if (DAT_23002796 != 1) {
      local_30 = DAT_230027ac;
      local_14 = 4;
      DAT_23002796 = 1;
      FUN_230218ec(auStack_34);
      FUN_23021528(0);
      DAT_230027ba._1_1_ = 1;
      thunk_FUN_0e0952ec(&DAT_23003858);
    }
  }
  if (DAT_2300774b == '\0') {
    return 1;
  }
  _DAT_5f9c200c = 1;
  _DAT_5f9c2000 = 1;
  return 1;
}


