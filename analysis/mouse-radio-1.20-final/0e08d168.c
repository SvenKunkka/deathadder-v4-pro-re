/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d168. Types and names are inferred; NOT original source. */

uint FUN_0e08d168(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar1 = uVar1 + 0x10;
  }
  return (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + uVar1 * 4) + 0x14) & 0x1f) >> 4;
}


