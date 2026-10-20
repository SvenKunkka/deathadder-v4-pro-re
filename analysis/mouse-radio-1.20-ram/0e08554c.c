/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08554c. Types and names are inferred; NOT original source. */

void FUN_0e08554c(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_0e094560(&DAT_0e0979a8);
  if (iVar1 != 0) {
    if ((1 << (uint)DAT_23000e10 & **(uint **)(DAT_23000e0c + 0x10)) == 0) {
      pcVar2 = *(code **)(*(int *)(DAT_23000e0c + 8) + 0xc);
    }
    else {
      pcVar2 = *(code **)(*(int *)(DAT_23000e0c + 8) + 0x10);
    }
    (*pcVar2)();
    iVar1 = (uint)DAT_23000e09 * 0xe;
    DAT_23000e0a = (&DAT_230049e2)[iVar1];
    (&DAT_230049e0)[iVar1] = 1;
    (&DAT_230049e2)[iVar1] = DAT_23000e0a + '\x01';
    return;
  }
  return;
}


