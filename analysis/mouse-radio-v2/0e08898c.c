/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08898c. Types and names are inferred; NOT original source. */

bool FUN_0e08898c(uint param_1,uint param_2)

{
  int iVar1;
  
  if (*DAT_0e0889d8 == param_1) {
    if ((DAT_0e0889d8[1] == param_2) || (param_2 == 0xff)) {
      iVar1 = 4;
      goto LAB_0e0889aa;
    }
    if ((uint)DAT_0e0889d8[8] != (uint)*DAT_0e0889d8) {
      return false;
    }
    if (DAT_0e0889d8[9] != param_2) {
      return false;
    }
  }
  else if ((DAT_0e0889d8[8] != param_1) || ((DAT_0e0889d8[9] != param_2 && (param_2 != 0xff)))) {
    return false;
  }
  iVar1 = 0xc;
LAB_0e0889aa:
  return *(int *)(DAT_0e0889d8 + iVar1) != 0;
}


