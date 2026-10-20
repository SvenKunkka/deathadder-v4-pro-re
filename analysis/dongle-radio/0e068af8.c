/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068af8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068af8(uint *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    if (uVar2 == 0) {
      return DAT_0e068b34;
    }
  } while (*param_1 != uVar2);
  *param_1 = uVar2 & ~(1 << (0x1fU - LZCOUNT(uVar2) & 0xff));
  uVar1 = DAT_0e068b30;
  *param_2 = (char)(0x1fU - LZCOUNT(uVar2));
  return uVar1;
}


