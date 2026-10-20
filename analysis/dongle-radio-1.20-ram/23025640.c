/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025640. Types and names are inferred; NOT original source. */

void FUN_23025640(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 local_30;
  
  if ((DAT_2300659a._2_2_ != 0) &&
     (bVar1 = DAT_2300659a._2_2_ == 1, DAT_2300659a._2_2_ = DAT_2300659a._2_2_ - 1, bVar1)) {
    DAT_2300659e = (ushort)DAT_2300659a >> 1;
    DAT_2300659a._2_2_ = (ushort)DAT_2300659a;
    if (DAT_230065a8 == 0) {
      DAT_230065b0._0_1_ = 0;
    }
    else {
      DAT_230065b0._0_1_ = (undefined1)(DAT_230065a0 / DAT_230065a8);
    }
    DAT_230065a0 = 0;
    DAT_230065a8 = 0;
    DAT_230065b0._1_1_ = 0;
    if (DAT_230065ac != 0) {
      DAT_230065b0._1_1_ = (undefined1)(DAT_230065a4 / DAT_230065ac);
    }
    DAT_230065a4 = 0;
    DAT_230065ac = 0;
    local_30 = CONCAT31(CONCAT12(local_30._3_1_,
                                 (ushort)DAT_2300659a << 8 | (ushort)DAT_2300659a >> 8),0xac);
    FUN_230251e4(0,3,&local_30);
  }
  if ((DAT_2300659e != 0) &&
     (uVar2 = DAT_2300659e - 1, bVar1 = DAT_2300659e == 1, DAT_2300659e = uVar2, bVar1)) {
    local_30 = CONCAT13(DAT_230065b0._3_1_,
                        CONCAT12(DAT_230065b0._1_1_,
                                 CONCAT11(DAT_230065b0._2_1_,(undefined1)DAT_230065b0)));
    FUN_230203fc(1,&local_30,4);
    return;
  }
  return;
}


