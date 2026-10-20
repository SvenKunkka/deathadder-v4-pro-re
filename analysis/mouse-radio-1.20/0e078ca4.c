/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078ca4. Types and names are inferred; NOT original source. */

uint thunk_FUN_0e07958c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 << 1 < 0x7f000000) {
    return 0;
  }
  uVar1 = (param_1 & 0x7fffffff) >> 0x17;
  uVar2 = 0x9e - uVar1;
  if (0x9e < uVar1 || uVar2 == 0) {
    if ((uVar2 == 0xffffff9f) && ((param_1 & 0x7fffff) != 0)) {
      return 0;
    }
    param_1 = param_1 & 0x80000000;
    if (param_1 == 0) {
      param_1 = 0x7fffffff;
    }
    return param_1;
  }
  uVar1 = (param_1 << 8 | 0x80000000) >> (uVar2 & 0xff);
  if ((param_1 & 0x80000000) != 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}


