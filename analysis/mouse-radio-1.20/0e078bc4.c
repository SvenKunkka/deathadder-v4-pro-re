/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078bc4. Types and names are inferred; NOT original source. */

void thunk_FUN_0e07eb80(void)

{
  int iVar1;
  
  iVar1 = FUN_0e094560(&DAT_0e097818);
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097818);
  }
  else {
    DAT_23007070 = DAT_23007070 & 0xffffffdf;
    FUN_23026030(&DAT_0e097818,5,0x60000);
    iVar1 = FUN_0e094560(&DAT_0e097818);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097818);
  }
  else {
    DAT_23007070 = DAT_23007070 & 0xfffffffb;
    FUN_23026030(&DAT_0e097818,2,0x60000);
    iVar1 = FUN_0e094560(&DAT_0e097818);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097818);
  }
  else {
    DAT_23007070 = DAT_23007070 & 0xfffffff7;
    FUN_23026030(&DAT_0e097818,3,0x60000);
    iVar1 = FUN_0e094560(&DAT_0e097818);
  }
  if (iVar1 != 0) {
    DAT_23007070 = DAT_23007070 & 0xffffffef;
    FUN_23026030(&DAT_0e097818,4,0x60000);
  }
  if (-1 < (int)(DAT_23007070 << 0x1a)) {
    FUN_230263bc(&DAT_0e097818,0x20);
    return;
  }
  FUN_23026368(&DAT_0e097818,0x20);
  return;
}


