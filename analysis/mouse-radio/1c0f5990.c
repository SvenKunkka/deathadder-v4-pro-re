/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f5990. Types and names are inferred; NOT original source. */

int FUN_1c0f5990(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
LAB_1c0f5a08:
    iVar1 = -0x16;
  }
  else {
    if ((param_3 == 0) || (param_4 == 0)) {
      iVar1 = -0x16;
    }
    else if (*DAT_1c0f5a10 == '\0') {
      iVar1 = -0x10;
    }
    else {
      iVar1 = FUN_1c100474(DAT_1c0f5a14,DAT_1c0f5a18,param_1,param_2,param_3,param_4);
      if (iVar1 == -0x16) goto LAB_1c0f5a08;
      if (iVar1 < -0x15) {
        if (iVar1 == -0x72) {
          return -0x78;
        }
        if (iVar1 == -0x4d) {
          return -0x4d;
        }
        return -5;
      }
      if (iVar1 != -0xe) {
        if (iVar1 == -5) {
          return -5;
        }
        if (iVar1 == 0) {
          return 0;
        }
        return -5;
      }
    }
    FUN_1c100664(DAT_1c0f5a14,param_1);
  }
  return iVar1;
}


