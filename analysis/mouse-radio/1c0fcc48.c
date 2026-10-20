/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fcc48. Types and names are inferred; NOT original source. */

void FUN_1c0fcc48(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_1c1010f0(DAT_1c0fcc84,param_2,0xffffffff,0xffffffff);
  do {
    uVar1 = *DAT_1c0fcc88;
  } while (*DAT_1c0fcc88 != uVar1);
  *DAT_1c0fcc88 = uVar1 & ~(0x80000000U >> LZCOUNT(uVar1));
  return;
}


