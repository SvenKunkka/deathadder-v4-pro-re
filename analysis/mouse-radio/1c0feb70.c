/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0feb70. Types and names are inferred; NOT original source. */

uint * FUN_1c0feb70(uint param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  if ((param_1 & 0xfffffff) >> 0x18 == 0xf) {
    iVar2 = 7;
    puVar1 = DAT_1c0febb8;
  }
  else {
    iVar2 = 1;
    puVar1 = DAT_1c0febbc;
  }
  puVar3 = puVar1 + iVar2 * 6;
  do {
    if ((*puVar1 & -puVar1[5] & 0xffffff) >> 0x10 == (param_1 & -puVar1[5] & 0xffffff) >> 0x10) {
      return puVar1;
    }
    puVar1 = puVar1 + 6;
  } while (puVar3 != puVar1);
  return (uint *)0x0;
}


