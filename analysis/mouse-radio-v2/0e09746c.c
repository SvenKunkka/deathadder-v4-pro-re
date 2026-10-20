/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09746c. Types and names are inferred; NOT original source. */

undefined1 FUN_0e09746c(int param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = param_2 & 0x7fffffff;
  if (uVar2 == 0) {
    if (param_1 == 0) {
      return 2;
    }
    if ((DAT_0e0974ac & param_2) == 0) {
      uVar1 = 3;
    }
    else {
      uVar1 = 4;
    }
    return uVar1;
  }
  if ((param_2 & DAT_0e0974ac) == 0) {
    return 3;
  }
  if (uVar2 <= DAT_0e0974b0) {
    return 4;
  }
  if (uVar2 != DAT_0e0974ac) {
    return false;
  }
  return param_1 == 0;
}


