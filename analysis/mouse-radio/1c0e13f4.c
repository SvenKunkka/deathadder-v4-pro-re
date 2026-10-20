/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e13f4. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0e13f4(uint *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    if (uVar2 == 0) {
      return DAT_1c0e1430;
    }
  } while (*param_1 != uVar2);
  *param_1 = uVar2 & ~(1 << (0x1fU - LZCOUNT(uVar2) & 0xff));
  uVar1 = DAT_1c0e142c;
  *param_2 = (char)(0x1fU - LZCOUNT(uVar2));
  return uVar1;
}


