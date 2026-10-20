/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08cac4. Types and names are inferred; NOT original source. */

uint FUN_0e08cac4(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = (int)(param_2 << 0x18) < 0;
  if (bVar1) {
    param_2 = param_2 & 0xffffff7f;
  }
  if (bVar1) {
    param_2 = param_2 + 0x10;
  }
  return *(uint *)(param_1 + 0x30) >> (param_2 & 0xff) & 1;
}


