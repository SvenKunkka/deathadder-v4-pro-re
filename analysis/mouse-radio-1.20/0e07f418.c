/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f418. Types and names are inferred; NOT original source. */

void FUN_0e07f418(void)

{
  if ((((DAT_23007758 != '\0') || (DAT_2300772f != '\0')) || (DAT_2300775e != '\0')) ||
     (DAT_2300775d != '\0')) {
    return;
  }
  if ((char)DAT_23004a54 == '\x01') {
    if (((char)DAT_23004a50 != '\x01') && (DAT_23004a50._2_1_ != '\x01')) {
      DAT_23007755 = DAT_2300775d;
      return;
    }
    if (DAT_23007755 == '\0') {
      if (DAT_230077a2 != '\0') {
        return;
      }
      if (DAT_2300777f == '\0') {
        if ((char)DAT_23004a50 != '\x01') {
          return;
        }
      }
      else {
        if ((char)DAT_23004a50 != '\x01') {
          if (((char)DAT_23004a50 == '\0') && (DAT_23004a50._2_1_ == '\x01')) {
            DAT_23007755 = DAT_23004a50._2_1_;
            DAT_23007754 = 2;
          }
          DAT_23007694 = 0;
          return;
        }
        DAT_23007754 = 4;
        DAT_23007694 = 0;
        DAT_23007755 = (char)DAT_23004a50;
      }
      goto LAB_0e07f452;
    }
    FUN_0e07f278();
  }
  else {
    DAT_23007755 = DAT_2300775d;
  }
  if ((char)DAT_23004a50 != '\x01') {
    return;
  }
  if (DAT_230077a2 != '\0') {
    return;
  }
LAB_0e07f452:
  if (DAT_23007763 == '\0') {
    return;
  }
  if (DAT_23007694 <= DAT_230014fe) {
    return;
  }
  DAT_23007694 = 0;
  if (DAT_23007753 == '\0') {
    DAT_23007753 = 1;
    DAT_230014fe = 200;
    DAT_23007743 = 0xff;
    DAT_23007742 = 0x14;
    DAT_23007741 = 0x14;
    return;
  }
  if (DAT_23007753 != '\x01') {
    DAT_23007753 = 0;
    DAT_230014fe = 200;
    return;
  }
  DAT_23007753 = 0;
  DAT_23007743 = 0;
  DAT_23007742 = 0;
  DAT_23007741 = 0;
  DAT_230014fe = 1000;
  return;
}


