/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078bb4. Types and names are inferred; NOT original source. */

void thunk_FUN_0e08543c(void)

{
  int iVar1;
  code *pcVar2;
  
  if ((1 << (uint)DAT_23000e10 & **(uint **)(DAT_23000e0c + 0x10)) == 0) {
    pcVar2 = *(code **)(*(int *)(DAT_23000e0c + 8) + 0x10);
  }
  else {
    pcVar2 = *(code **)(*(int *)(DAT_23000e0c + 8) + 0xc);
  }
  (*pcVar2)();
  iVar1 = FUN_0e094560(&DAT_0e097854);
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097854);
  }
  else {
    DAT_23007094 = DAT_23007094 & 0xffffffbf;
    FUN_23026030(&DAT_0e097854,6,0x10000);
    iVar1 = FUN_0e094560(&DAT_0e097854);
  }
  if (iVar1 != 0) {
    DAT_23007094 = DAT_23007094 & 0xfffffffb;
    FUN_23026030(&DAT_0e097854,2,0x10000);
    return;
  }
  return;
}


