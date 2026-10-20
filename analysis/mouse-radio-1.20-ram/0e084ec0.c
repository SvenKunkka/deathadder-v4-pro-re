/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084ec0. Types and names are inferred; NOT original source. */

void FUN_0e084ec0(void)

{
  int iVar1;
  code *pcVar2;
  
  if ((1 << (uint)DAT_23000664 & **(uint **)(DAT_23000660 + 0x10)) == 0) {
    pcVar2 = *(code **)(*(int *)(DAT_23000660 + 8) + 0x10);
  }
  else {
    pcVar2 = *(code **)(*(int *)(DAT_23000660 + 8) + 0xc);
  }
  (*pcVar2)();
  iVar1 = FUN_0e094560(&DAT_0e097854);
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097854);
  }
  else {
    DAT_23007094 = DAT_23007094 & 0xffffffef;
    FUN_23026030(&DAT_0e097854,4,0x10000);
    iVar1 = FUN_0e094560(&DAT_0e097854);
  }
  if (iVar1 == 0) {
    return;
  }
  DAT_23007094 = DAT_23007094 & 0xfffffffe;
  FUN_23026030(&DAT_0e097854,0,0x10000);
  return;
}


