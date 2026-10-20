/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024e38. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23024e38(void)

{
  undefined4 extraout_r1;
  uint auStack_48 [3];
  undefined4 uStack_3c;
  uint uStack_38;
  
  do {
    thunk_FUN_0e06cc94(&DAT_23001bb4,&uStack_3c,0xffffffff,0xffffffff);
    switch(uStack_3c) {
    case 1:
      auStack_48[0] = uStack_38;
      auStack_48[1] = 4;
      FUN_2302206c(auStack_48);
      FUN_23020108(auStack_48[0] & 0xffff);
      ram_candidate_23024e46();
      return;
    case 4:
      FUN_23021f88(0);
      FUN_23022008();
      DAT_230065e2._2_2_ = 5;
      ram_candidate_23024e46();
      return;
    case 8:
      FUN_23020fcc(0,uStack_38);
      FUN_23020108(uStack_38 & 0xffff);
      ram_candidate_23024e46();
      return;
    case 9:
      FUN_23021094(0,uStack_38);
      ram_candidate_23024e46();
      return;
    case 10:
    case 0x28:
      _DAT_23006592 = 0;
      FUN_23024d54();
      ram_candidate_23024e46();
      return;
    case 0x29:
      _DAT_23006592 = 0x101;
      FUN_230221f8(1);
      FUN_23022008();
      thunk_FUN_0e06ebe0(&DAT_23001b10,extraout_r1,100000,0,1000000,0);
      DAT_230065e2._2_2_ = 5;
      ram_candidate_23024e46();
      return;
    case 0x2b:
      _DAT_23006592 = (ushort)DAT_23006593 << 8;
      FUN_23024cd4();
      FUN_230221f8(0);
      ram_candidate_23024e46();
      return;
    case 0x2c:
      _DAT_23006592 = CONCAT11(DAT_23006593,1);
      FUN_23024d54();
      FUN_230221f8(1);
      if (DAT_23006593 != '\0') {
        FUN_23022008();
        DAT_230065e2._2_2_ = 5;
        ram_candidate_23024e46();
        return;
      }
    }
  } while( true );
}


