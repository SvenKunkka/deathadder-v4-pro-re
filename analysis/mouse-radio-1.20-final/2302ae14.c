/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302ae14. Types and names are inferred; NOT original source. */

void FUN_2302ae14(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  
  do {
    do {
      thunk_FUN_0e094fc8(&DAT_230016a4,param_2,0xffffffff,0xffffffff,param_4);
      thunk_FUN_0e07e09c();
      FUN_23026704();
      thunk_FUN_0e07d780();
      FUN_23026ec8();
      FUN_2302c2c0();
      param_2 = extraout_r1;
    } while (DAT_2300777c == '\0');
    cVar1 = DAT_2300772b;
    if ((DAT_23007728 != '\0') && (DAT_2300771a = DAT_2300771a + 1, 0x31 < DAT_2300771a)) {
      DAT_2300771a = 0;
      DAT_23007728 = '\0';
      cVar1 = DAT_23007723;
      if ((DAT_23007723 != '\x01') && (cVar1 = DAT_2300772b, DAT_23007723 == '\x04')) {
        DAT_2300779f = '\x01';
      }
    }
    DAT_2300772b = cVar1;
    FUN_2302b088();
    FUN_2302c25c();
    if (DAT_2300779f != '\0') {
      FUN_2302af6c();
    }
    FUN_23026a00();
    thunk_FUN_0e07d170();
    FUN_23027bf8();
    FUN_23020954();
    thunk_FUN_0e07d6d8(1);
    FUN_230264e0();
    FUN_23027ebc();
    thunk_FUN_0e07eadc();
    param_2 = extraout_r1_00;
  } while( true );
}


