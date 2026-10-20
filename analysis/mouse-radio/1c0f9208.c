/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f9208. Types and names are inferred; NOT original source. */

uint FUN_1c0f9208(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  param_2 = param_2 & 3;
  uVar1 = (param_1 & 0xffffff) >> 0x10;
  if (param_2 == 2) {
    return (uVar1 & 7) >> 2;
  }
  if (param_2 == 3) {
    uVar2 = uVar1 & 2;
  }
  else {
    if (param_2 != 1) {
      return uVar1 & 1;
    }
    uVar2 = uVar1 & 8;
  }
  if (uVar2 != 0) {
    if ((param_3 & 0x1800) == 0) {
      return 1;
    }
    return (uVar1 & 0x1f) >> 4;
  }
  return 0;
}


