/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084f5c. Types and names are inferred; NOT original source. */

void FUN_0e084f5c(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_0e094560(&DAT_0e0979bc);
  if (iVar1 != 0) {
    if ((1 << (uint)DAT_23000664 & **(uint **)(DAT_23000660 + 0x10)) == 0) {
      pcVar2 = *(code **)(*(int *)(DAT_23000660 + 8) + 0xc);
    }
    else {
      pcVar2 = *(code **)(*(int *)(DAT_23000660 + 8) + 0x10);
    }
    (*pcVar2)();
    iVar1 = (uint)DAT_2300065d * 0xe;
    DAT_2300065e = (&DAT_230049e2)[iVar1];
    (&DAT_230049e0)[iVar1] = 1;
    (&DAT_230049e2)[iVar1] = DAT_2300065e + '\x01';
    return;
  }
  return;
}


