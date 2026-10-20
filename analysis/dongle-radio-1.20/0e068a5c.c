/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068a5c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068a5c(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  
  do {
    uVar1 = *param_1;
    if (uVar1 == 0) {
      return 0xbad0002;
    }
  } while (*param_1 != uVar1);
  *param_1 = uVar1 & ~(1 << (0x1fU - LZCOUNT(uVar1) & 0xff));
  *param_2 = (char)(0x1fU - LZCOUNT(uVar1));
  return 0xbad0000;
}


