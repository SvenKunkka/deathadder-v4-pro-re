/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088960. Types and names are inferred; NOT original source. */

uint FUN_0e088960(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*DAT_0e088988 == 0) {
    return 0xffffffff;
  }
  iVar3 = *(int *)(*DAT_0e088988 + 4);
  if (iVar3 != 0) {
    iVar1 = FUN_0e0977a0();
    uVar2 = iVar3 - iVar1;
    return (uVar2 & ~((int)uVar2 >> 0x1f)) >> 5;
  }
  return 0xffffffff;
}


