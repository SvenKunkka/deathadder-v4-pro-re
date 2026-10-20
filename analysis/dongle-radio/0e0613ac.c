/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0613ac. Types and names are inferred; NOT original source. */

void FUN_0e0613ac(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(DAT_0e0613c4 + (uVar1 >> 5) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


