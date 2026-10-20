/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fac8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fac8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 == (uint *)0x0) || (uVar1 = *param_1, uVar1 == 0)) {
    return 0xffffffea;
  }
  uVar3 = param_1[1];
  if ((uVar3 != 0) && (uVar4 = param_1[4], uVar4 != 0)) {
    uVar2 = param_1[2];
    if (uVar2 < 4) {
      uVar2 = 4;
    }
    if ((((uVar1 == uVar2 * (uVar1 / uVar2)) &&
         (uVar3 == uVar2 * (uVar3 / uVar2) && (uVar4 & 3) == 0)) && (0xb < param_1[3])) &&
       ((((param_1[3] & 3) == 0 && (uVar1 < uVar3)) && (uVar3 < uVar4)))) {
      if (uVar3 != uVar1 + uVar2) {
        return 0xffffffea;
      }
      return 0;
    }
  }
  return 0xffffffea;
}


