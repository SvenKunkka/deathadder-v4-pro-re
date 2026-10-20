/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0687ac. Types and names are inferred; NOT original source. */

void FUN_0e0687ac(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_0e06d1b4(DAT_0e0687e8,param_2,0xffffffff,0xffffffff);
  do {
    uVar1 = *DAT_0e0687ec;
  } while (*DAT_0e0687ec != uVar1);
  *DAT_0e0687ec = uVar1 & ~(0x80000000U >> LZCOUNT(uVar1));
  return;
}


