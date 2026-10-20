/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060d84. Types and names are inferred; NOT original source. */

int FUN_0e060d84(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
LAB_0e060dfc:
    iVar1 = -0x16;
  }
  else {
    if ((param_3 == 0) || (param_4 == 0)) {
      iVar1 = -0x16;
    }
    else if (*DAT_0e060e04 == '\0') {
      iVar1 = -0x10;
    }
    else {
      iVar1 = FUN_0e06c548(DAT_0e060e08,DAT_0e060e0c,param_1,param_2,param_3,param_4);
      if (iVar1 == -0x16) goto LAB_0e060dfc;
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
    FUN_0e06c738(DAT_0e060e08,param_1);
  }
  return iVar1;
}


