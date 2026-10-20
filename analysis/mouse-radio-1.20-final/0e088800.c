/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088800. Types and names are inferred; NOT original source. */

bool FUN_0e088800(uint param_1,uint param_2)

{
  int iVar1;
  
  if (DAT_23000e8c == param_1) {
    if ((DAT_23000e8d == param_2) || (param_2 == 0xff)) {
      iVar1 = 4;
      goto LAB_0e08881e;
    }
    if ((uint)DAT_23000e94 != (uint)DAT_23000e8c) {
      return false;
    }
    if (DAT_23000e95 != param_2) {
      return false;
    }
  }
  else if ((DAT_23000e94 != param_1) || ((DAT_23000e95 != param_2 && (param_2 != 0xff)))) {
    return false;
  }
  iVar1 = 0xc;
LAB_0e08881e:
  return *(int *)(&DAT_23000e8c + iVar1) != 0;
}


