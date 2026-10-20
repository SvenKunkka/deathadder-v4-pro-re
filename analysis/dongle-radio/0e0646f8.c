/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0646f8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0646f8(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar1 = uVar1 + 0x10;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x10) + uVar1 * 4);
}


