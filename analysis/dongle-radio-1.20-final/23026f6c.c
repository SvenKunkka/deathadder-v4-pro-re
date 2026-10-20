/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026f6c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23026f6c(void)

{
  uint uVar1;
  uint uVar2;
  
  FUN_230258fc(0,0xa001,&DAT_23002db0,0x46);
  if ((DAT_23002db0 != 0x46) ||
     (uVar2 = (uint)DAT_23002df4, uVar1 = ram_candidate_23020000(&DAT_23002db0,0x44,0),
     uVar2 != uVar1)) {
    thunk_FUN_0e06f35c(&DAT_23002db0,&DAT_0e06fa28,0x46);
  }
  FUN_230258fc(1,0xa002,&DAT_23002d80,0x2f);
  if ((DAT_23002d80 & 0xffff) == 0x2f) {
    uVar2 = (uint)ram0x23002dad;
    uVar1 = ram_candidate_23020000(&DAT_23002d80,0x2d,0);
    if (uVar2 == uVar1) goto LAB_23027002;
  }
  DAT_23002d80 = 0xffff002f;
  DAT_23002d84 = 0x102ffff;
  DAT_23002d88 = 0xff000101;
  DAT_23002d8c = 0xffffff;
  DAT_23002d90 = 0x3010200;
  _DAT_23002dac = 0x46;
  DAT_23002da8 = CONCAT22(0x3c32,(short)DAT_23002da8);
LAB_23027002:
  if (0xfffffffd < DAT_23002dcf - 1U) {
    DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                            CONCAT12((char)((uint)_DAT_0fffe010 >> 8),
                                     CONCAT11((char)((uint)_DAT_0fffe010 >> 0x10),
                                              (char)((uint)_DAT_0fffe010 >> 0x18))));
    DAT_230071ba = DAT_230071ba | 2;
    DAT_2300719e = 0;
  }
  if (0xfffffffd < CONCAT31((undefined3)DAT_23002d8c,DAT_23002d88._3_1_) - 1U) {
    DAT_23002d88._3_1_ = (undefined1)DAT_23002dcf;
    DAT_23002d8c._0_3_ = (undefined3)((uint)DAT_23002dcf >> 8);
    DAT_2300719e = 0;
    DAT_230071ba = DAT_230071ba | 1;
  }
  if (((_DAT_0fffe014 == 0xc000) && (_DAT_0fffe010 == -0x80000000)) && (DAT_23002dcf == 0x80)) {
    thunk_FUN_0e0621b8(&DAT_23002dcf,4);
    DAT_2300719e = 0;
    DAT_230071ba = DAT_230071ba | 2;
  }
  FUN_23026ea4();
  return;
}


