/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230266b0. Types and names are inferred; NOT original source. */

void FUN_230266b0(int param_1)

{
  int iVar1;
  
  iVar1 = (uint)(DAT_230013dc >> 0xd) * 4;
  *(uint *)(iVar1 + 0x5f934510) =
       *(uint *)(iVar1 + 0x5f934510) & 0xffefffff | (uint)(param_1 != 0) << 0x14;
  return;
}


