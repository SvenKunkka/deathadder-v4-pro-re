/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f278. Types and names are inferred; NOT original source. */

void FUN_0e07f278(void)

{
  if ((DAT_23007763 == '\0') && (DAT_23001500 < DAT_23007694)) {
    DAT_23007694 = 0;
    switch(DAT_23007754) {
    case 0:
      if (DAT_230077a2 == '\0') {
        DAT_23001500 = 200;
        if ((char)DAT_23004a54 == '\x01') {
          if ((char)DAT_23004a50 == '\x01') {
            DAT_23007754 = 4;
            DAT_23007755 = (char)DAT_23004a50;
          }
          else if (((char)DAT_23004a50 == '\0') &&
                  (DAT_23007755 = DAT_23004a50._2_1_, DAT_23004a50._2_1_ == '\x01')) {
            DAT_23007754 = 2;
          }
          else {
            DAT_23007755 = '\0';
          }
        }
      }
      else {
        DAT_23001500 = 200;
        DAT_23007755 = '\0';
      }
      break;
    case 1:
      DAT_23007754 = 0;
      DAT_23007742 = 0;
      DAT_23007743 = 0;
      DAT_23007741 = 0;
      DAT_23001500 = 1000;
      break;
    case 2:
      DAT_23007743 = 0xff;
      DAT_23007742 = 0x80;
      DAT_23007741 = 0;
      DAT_23007754 = 1;
      DAT_23001500 = 200;
      break;
    case 3:
      DAT_23007743 = 0;
      DAT_23007742 = 0;
      DAT_23007741 = 0;
      if (DAT_23004a50._2_1_ == '\x01') {
        DAT_23007754 = 2;
        DAT_23001500 = 1000;
      }
      else {
        DAT_23007754 = 0;
        DAT_23001500 = 1000;
      }
      break;
    case 4:
      DAT_23007754 = 3;
      DAT_23007742 = 0;
      DAT_23007743 = 0xff;
      DAT_23007741 = 0xff;
      DAT_23001500 = 200;
      break;
    default:
      DAT_23007754 = 0;
      DAT_23007755 = '\0';
      DAT_23001500 = 200;
    }
    return;
  }
  return;
}


