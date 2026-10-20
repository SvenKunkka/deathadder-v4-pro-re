/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089fb8. Types and names are inferred; NOT original source. */

void FUN_0e089fb8(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(DAT_0e089fd0 + (uVar1 >> 5) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


