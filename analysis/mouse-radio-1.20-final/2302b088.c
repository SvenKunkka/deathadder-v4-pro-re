/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302b088. Types and names are inferred; NOT original source. */

void FUN_2302b088(void)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint local_24;
  uint local_20 [2];
  
  if (DAT_2300772b != '\0') {
    iVar1 = FUN_230263ac(&DAT_0e097840,local_20);
    if (iVar1 == 0) {
      if (((DAT_23007088 ^ local_20[0]) & 8) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
    if ((iVar1 == 1) && (DAT_23004962 == '\0')) {
      DAT_2300771f = DAT_23004962;
      DAT_23001508._2_1_ = 1;
      FUN_2302133c();
      thunk_FUN_0e096164(0x271,0);
      FUN_2302b944();
      FUN_2302b678();
      FUN_2302b864();
      FUN_2302b74c();
      FUN_23026974();
      thunk_FUN_0e07d6d8(0);
      FUN_2302a400();
      FUN_2302a8a8(0x16,local_20,6);
      thunk_FUN_0e094554(1000);
      thunk_FUN_0e084820();
      thunk_FUN_0e07eda0();
      FUN_2302a6a4();
      FUN_230266b0(0);
      thunk_FUN_0e085598(1);
      thunk_FUN_0e08543c();
      thunk_FUN_0e084ec0();
      iVar1 = FUN_230263ac(&DAT_0e09782c,&local_24);
      if ((iVar1 != 0) || (((local_24 ^ DAT_2300707c) & 0x10) != 0)) {
        FUN_230285ac();
        thunk_FUN_0e07e010(1);
        thunk_FUN_0e0908ec();
        DAT_2300773f = 1;
        thunk_FUN_0e094fc8(&DAT_230016c4,extraout_r1,0,0);
        DAT_2300772a = 1;
        thunk_FUN_0e094fc8(&DAT_230016c4,extraout_r1_00,0xffffffff,0xffffffff);
        thunk_FUN_0e07e010(0);
        thunk_FUN_0e07e04c();
      }
      DAT_23007723 = 0;
      DAT_23001508._2_1_ = 0;
      DAT_23007721 = 0xff;
      DAT_2300777f = 0;
      DAT_23007795 = 0;
      DAT_23007724 = 0;
      DAT_23001508._0_1_ = 0xff;
      DAT_2300772a = 0;
      thunk_FUN_0e0847f0();
      thunk_FUN_0e07f608();
      FUN_2302a56c();
      thunk_FUN_0e0854b4();
      thunk_FUN_0e084f38();
      thunk_FUN_0e07eb80();
      thunk_FUN_0e07ec9c();
      FUN_230266c0();
      FUN_2302a3e0();
      thunk_FUN_0e085598(0);
      FUN_2302b70c();
      FUN_23026940();
      DAT_2300772b = '\0';
    }
  }
  return;
}


