/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0844c0. Types and names are inferred; NOT original source. */

void FUN_0e0844c0(void)

{
  if (DAT_230077aa == '\0') {
    return;
  }
  if (DAT_23007723 != '\x04') {
    if (DAT_23007723 != '\x01') {
      return;
    }
    if (1 < DAT_23004a5f) {
      if (DAT_23004a5f == 2) {
        if (((ushort)DAT_23004a8c < 0x2711) && (DAT_23004a8c._2_2_ < 0x2711)) {
          if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
            if (DAT_230077bc != '\b') {
              FUN_0e082170();
              DAT_230077bc = '\b';
            }
          }
          else if (DAT_230077bc != '\t') {
            FUN_0e0825dc();
            DAT_230077bc = '\t';
          }
        }
        else if (DAT_230077bc != '\n') {
          FUN_0e082a48();
          DAT_230077bc = '\n';
        }
      }
      else if (DAT_23004a5f < 5) {
        if (((ushort)DAT_23004a8c < 0x2711) && (DAT_23004a8c._2_2_ < 0x2711)) {
          if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
            if (DAT_230077bc != '\x05') {
              FUN_0e08142c();
              DAT_230077bc = '\x05';
            }
          }
          else if (DAT_230077bc != '\x06') {
            FUN_0e081898();
            DAT_230077bc = '\x06';
          }
        }
        else if (DAT_230077bc != '\a') {
          FUN_0e081d04();
          DAT_230077bc = '\a';
        }
      }
      else if (((ushort)DAT_23004a8c < 0x2711) && (DAT_23004a8c._2_2_ < 0x2711)) {
        if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
          if (DAT_230077bc != '\x02') {
            FUN_0e0806e8();
            DAT_230077bc = '\x02';
          }
        }
        else if (DAT_230077bc != '\x03') {
          FUN_0e080b54();
          DAT_230077bc = '\x03';
        }
      }
      else if (DAT_230077bc != '\x04') {
        FUN_0e080fc0();
        DAT_230077bc = '\x04';
      }
      goto LAB_0e084504;
    }
  }
  if (((ushort)DAT_23004a8c < 0x2711) && (DAT_23004a8c._2_2_ < 0x2711)) {
    if (((ushort)DAT_23004a8c < 0xfa1) && (DAT_23004a8c._2_2_ < 0xfa1)) {
      if (DAT_230077bc != '\v') {
        FUN_0e083794();
        DAT_230077bc = '\v';
      }
    }
    else if (DAT_230077bc != '\f') {
      FUN_0e083bf8();
      DAT_230077bc = '\f';
    }
  }
  else if (DAT_230077bc != '\r') {
    FUN_0e08405c();
    DAT_230077bc = 0xd;
    FUN_0e0802e4(1);
    return;
  }
LAB_0e084504:
  FUN_0e0802e4(1);
  return;
}


