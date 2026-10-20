/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d23c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07d23c(void)

{
  uint uVar1;
  uint uVar2;
  
  DAT_230077a5 = 1;
  DAT_23007721 = 0xff;
  DAT_23007724 = 0;
  DAT_23007720 = 0;
  DAT_2300771f = 0;
  DAT_2300772b = 0;
  DAT_2300772a = 0;
  DAT_23007723 = 0;
  DAT_2300778c = 0;
  DAT_23007726 = 0;
  DAT_2300768e = 0;
  FUN_0e07de2c(0,0xa001,&DAT_230049ac,0x29);
  if (_DAT_230049ac != 0x29) {
    _DAT_230049ac = 0x29;
    ram0x230049b0 = 0;
    ram0x230049b4 = 0xffffff00;
    ram0x230049b8 = 0xffffffff;
    ram0x230049bc = 0xffffffff;
    ram0x230049c0 = 0xffffffff;
    ram0x230049c4 = 0xffffffff;
    ram0x230049c8 = 0xffffffff;
    DAT_230049cb._1_1_ = 0xff;
    DAT_230049cb._2_1_ = 0xff;
    DAT_230049cb._3_1_ = 0xff;
    DAT_230049cf._0_1_ = 0;
    ram0x230049d0 = 0;
    DAT_230049d3._1_1_ = 0;
  }
  FUN_0e07de2c(1,0xa002,&DAT_23004958,0x54);
  if ((DAT_23004958 != 0x54) ||
     (uVar2 = (uint)DAT_230049aa, uVar1 = FUN_0e07f944(&DAT_23004958,0x52), uVar2 != uVar1)) {
    FUN_0e09739c(&DAT_23004958,&DAT_0e099058,0x54);
  }
  FUN_0e07de2c(2,0xa003,&DAT_23004474,0x4e4);
  if ((DAT_23004474 != 0x4e4) ||
     (uVar2 = (uint)DAT_23004956, uVar1 = FUN_0e07f944(&DAT_23004474,0x4e2), uVar2 != uVar1)) {
    FUN_0e09739c(&DAT_23004474,&DAT_0e098b74,0x4e4);
    DAT_23007726 = DAT_23007726 | 4;
    DAT_2300768e = 0;
  }
  FUN_0e09739c(&DAT_23005fc0,&DAT_0e09a650,0x5de);
  FUN_0e09739c(&DAT_230059e0,&DAT_0e09a070,0x5de);
  FUN_0e09739c(&DAT_23005400,&DAT_0e099a90,0x5de);
  FUN_0e07de2c(4,0xa006,&DAT_23004e20,0x5de);
  uVar2 = (uint)DAT_230053fc;
  uVar1 = FUN_0e07f944(&DAT_23004e20,0x5dc);
  if (uVar2 != uVar1) {
    FUN_0e09739c(&DAT_23004e20,&DAT_0e0994b0,0x5de);
  }
  _DAT_23006774 = 0;
  FUN_0e07e650();
  FUN_0e097658(0);
  FUN_0e07ec9c();
  if ((char)DAT_230049cb == -1) {
    if ((DAT_230049cb._1_1_ & DAT_230049cb._2_1_ & DAT_230049cb._3_1_) == 0xff) goto LAB_0e07d3d8;
  }
  else if ((((char)DAT_230049cb == '\0' && DAT_230049cb._1_1_ == 0) && DAT_230049cb._2_1_ == 0) &&
           DAT_230049cb._3_1_ == 0) {
LAB_0e07d3d8:
    ram0x230049c8 = CONCAT13((char)((uint)_DAT_0fffe010 >> 0x18),ram0x230049c8);
    DAT_230049cb._1_1_ = (byte)((uint)_DAT_0fffe010 >> 0x10);
    DAT_230049cb._2_1_ = (byte)((uint)_DAT_0fffe010 >> 8);
    DAT_230049cb._3_1_ = (byte)_DAT_0fffe010;
  }
  if ((char)DAT_2300497b == -1) {
    if ((DAT_2300497b._3_1_ & DAT_2300497b._1_1_ & DAT_2300497b._2_1_) != 0xff) goto LAB_0e07d39c;
  }
  else if (DAT_2300497b._3_1_ != 0 ||
           (DAT_2300497b._2_1_ != 0 || ((char)DAT_2300497b != '\0' || DAT_2300497b._1_1_ != 0)))
  goto LAB_0e07d39c;
  DAT_2300497b = CONCAT13(DAT_230049cb._3_1_,
                          CONCAT12(DAT_230049cb._2_1_,
                                   CONCAT11(DAT_230049cb._1_1_,(char)DAT_230049cb)));
LAB_0e07d39c:
  if ((char)DAT_2300497f == -1) {
    if ((DAT_2300497f._3_1_ & DAT_2300497f._1_1_ & DAT_2300497f._2_1_) != 0xff) {
      return;
    }
  }
  else if (DAT_2300497f._3_1_ != 0 ||
           (DAT_2300497f._2_1_ != 0 || ((char)DAT_2300497f != '\0' || DAT_2300497f._1_1_ != 0))) {
    return;
  }
  DAT_2300497f = CONCAT13(DAT_230049cb._3_1_,
                          CONCAT12(DAT_230049cb._2_1_,
                                   CONCAT11(DAT_230049cb._1_1_,(char)DAT_230049cb)));
  return;
}


