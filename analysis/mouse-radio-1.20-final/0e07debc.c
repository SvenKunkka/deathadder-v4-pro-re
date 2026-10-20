/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07debc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e07debc(void)

{
  int iVar1;
  
  _DAT_5f9856d4 = 0;
  iVar1 = FUN_0e094560(&DAT_0e097818);
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097840);
  }
  else {
    DAT_23007070 = DAT_23007070 & 0xfffffffd;
    FUN_23026030(&DAT_0e097818,1,0x60000);
    iVar1 = FUN_0e094560(&DAT_0e097840);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_0e094560(&DAT_0e097840);
  }
  else {
    DAT_23007088 = DAT_23007088 & 0xfffffeff;
    FUN_23026030(&DAT_0e097840,8,0x60000);
    iVar1 = FUN_0e094560(&DAT_0e097840);
  }
  if (iVar1 != 0) {
    DAT_23007088 = DAT_23007088 & 0xfffff7ff;
    FUN_23026030(&DAT_0e097840,0xb,0x60000);
  }
  FUN_0e084c78();
  FUN_0e08537c();
  thunk_FUN_2302a56c();
  FUN_0e07eb80();
  return;
}


