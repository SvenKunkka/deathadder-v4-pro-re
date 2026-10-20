/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230253c4. Types and names are inferred; NOT original source. */

void FUN_230253c4(void)

{
  undefined2 local_48 [2];
  int local_44;
  ushort local_40;
  
  do {
    while( true ) {
      thunk_FUN_0e06cc94(&DAT_23001b8c,&local_44,0xffffffff,0xffffffff);
      if (local_44 == 1) break;
      if ((local_44 == 2) && (local_40 == 0 && (short)DAT_230065e2 == 0)) {
        thunk_FUN_0e06ebe0(&DAT_23001a30,2,2000000,0,0,0);
        DAT_230065e2 = CONCAT22(DAT_230065e2._2_2_,4);
        DAT_230065de = 0;
      }
    }
    DAT_23006590 = (ushort)(1 << (local_40 & 0xff)) | DAT_23006590;
    DAT_230065e6 = 5;
    if (local_40 == 0) {
      FUN_230201b4(1);
      local_48[0] = 4;
      FUN_230203fc(2,local_48);
      thunk_FUN_0e06ec54(&DAT_23001a30);
      DAT_230065e2 = 0;
    }
  } while( true );
}


