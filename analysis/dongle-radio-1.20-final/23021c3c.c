/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021c3c. Types and names are inferred; NOT original source. */

void ram_candidate_23021c3c(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  
  cVar1 = DAT_23003251;
  do {
    do {
      while( true ) {
        DAT_23003251 = cVar1;
        thunk_FUN_0e06d118(&DAT_23001c54,param_2,0xffffffff,0xffffffff);
        cVar1 = DAT_23003251;
        param_2 = extraout_r1;
        if ((char)DAT_23003252 == '\0') break;
        DAT_23003252 = (ushort)DAT_23003252._1_1_ << 8;
      }
    } while ((((DAT_23003250 != '\0') || (DAT_23003258 == '\0')) ||
             (cVar1 = DAT_23003250, DAT_23003251 != '\0')) ||
            ((uVar2 = (uint)DAT_23003257, cVar1 = DAT_23003251, uVar2 != 0 || (DAT_23003259 == '\0')
             )));
    if (DAT_23003252._1_1_ == 0) {
      if (DAT_23003254 == 0) {
        if (DAT_230033ec == 0) {
          if (DAT_23004370 != '\0') {
            DAT_23004370 = '\0';
            FUN_23021eb8();
            FUN_230221c0(1);
            cVar1 = DAT_23003251;
            param_2 = extraout_r1_00;
          }
        }
        else {
          DAT_230033ec = DAT_23003254;
          FUN_23021eb8();
          FUN_230221c0(0);
          cVar1 = DAT_23003251;
          param_2 = extraout_r1_02;
        }
      }
      else {
        DAT_23003254 = DAT_23003252._1_1_;
        DAT_230032d4 = 8;
        DAT_23003252 = 1;
        FUN_23021f04();
        cVar1 = DAT_23003251;
        param_2 = extraout_r1_03;
      }
    }
    else {
      DAT_23003252 = (ushort)DAT_23003257 << 8;
      DAT_230034b4 = (ushort)DAT_23003257;
      DAT_230033e8 = uVar2;
      DAT_23003468 = uVar2;
      DAT_2300347e = uVar2;
      DAT_2300436c = uVar2;
      DAT_230043ec = uVar2;
      DAT_23004402 = uVar2;
      DAT_23004438 = DAT_230034b4;
      DAT_230052f0 = uVar2;
      DAT_23005370 = uVar2;
      DAT_23005386 = uVar2;
      DAT_230053bc = DAT_230034b4;
      FUN_23021eb8();
      FUN_230221c0(0);
      FUN_230221c0(1);
      cVar1 = DAT_23003251;
      param_2 = extraout_r1_01;
    }
  } while( true );
}


