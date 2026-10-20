/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0646c8. Types and names are inferred; NOT original source. */

void FUN_0e0646c8(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0x10) + 0xa0);
  if (param_2 != 0) {
    *puVar1 = *puVar1 | 4;
    return;
  }
  *puVar1 = *puVar1 & 0xfffffffb;
  return;
}


