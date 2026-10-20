/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089804. Types and names are inferred; NOT original source. */

int FUN_0e089804(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
LAB_0e08987c:
    iVar1 = -0x16;
  }
  else {
    if ((param_3 == 0) || (param_4 == 0)) {
      iVar1 = -0x16;
    }
    else if (DAT_230077c4 == '\0') {
      iVar1 = -0x10;
    }
    else {
      iVar1 = FUN_0e09434c(&DAT_0e09d120,0x10042,param_1,param_2,param_3,param_4);
      if (iVar1 == -0x16) goto LAB_0e08987c;
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
    FUN_0e09453c(&DAT_0e09d120,param_1);
  }
  return iVar1;
}


