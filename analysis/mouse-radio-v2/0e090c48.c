/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090c48. Types and names are inferred; NOT original source. */

void FUN_0e090c48(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_0e0950f0(DAT_0e090c84,param_2,0xffffffff,0xffffffff);
  do {
    uVar1 = *DAT_0e090c88;
  } while (*DAT_0e090c88 != uVar1);
  *DAT_0e090c88 = uVar1 & ~(0x80000000U >> LZCOUNT(uVar1));
  return;
}


