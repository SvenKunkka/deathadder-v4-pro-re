/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07e690. Types and names are inferred; NOT original source. */

void FUN_0e07e690(void)

{
  int iVar1;
  ushort uVar2;
  
  if (DAT_23004d22 <= (ushort)DAT_23004d44) {
    DAT_23004d44._0_2_ = 0;
    if (DAT_23004d21 == '\x01') {
      uVar2 = DAT_23004d2a;
      if ((uint)DAT_23004d34 <= (uint)DAT_23004d44._2_2_) {
        uVar2 = DAT_23004d2c;
      }
      if ((int)(uint)uVar2 < (int)(0xffff - (uint)DAT_23004d44._2_2_)) {
        DAT_23004d44._2_2_ = DAT_23004d44._2_2_ + uVar2;
        DAT_23004d22 = DAT_23004d28;
        return;
      }
      DAT_23004d44._2_2_ = 0xffff;
      DAT_23004d22 = DAT_23004d24;
      DAT_23004d21 = 3;
      return;
    }
    if (DAT_23004d21 == '\x03') {
      uVar2 = DAT_23004d30;
      if (DAT_23004d34 <= DAT_23004d44._2_2_) {
        uVar2 = DAT_23004d32;
      }
      if (DAT_23004d44._2_2_ <= uVar2) {
        DAT_23004d22 = DAT_23004d26;
        DAT_23004d21 = 1;
        DAT_23004d44._2_2_ = 0;
        iVar1 = FUN_0e07f9ac(0,0xf);
        DAT_23004d3e = *(undefined4 *)(&DAT_0e099470 + iVar1 * 4);
        if (DAT_230077a2 != '\0') {
          FUN_0e07f234();
        }
        if (DAT_23004d43 != '\0') {
          DAT_23004d43 = 0;
          return;
        }
        DAT_23004d43 = 1;
        return;
      }
      DAT_23004d44._2_2_ = DAT_23004d44._2_2_ - uVar2;
      DAT_23004d22 = DAT_23004d2e;
    }
  }
  return;
}


