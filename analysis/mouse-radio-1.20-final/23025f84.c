/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025f84. Types and names are inferred; NOT original source. */

undefined4
ram_candidate_23025f84(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(*(int *)(param_1 + 4) + 0x10) != 0) {
    iVar2 = *(int *)(param_1 + 4) + 0x10;
    iVar1 = FUN_23029168(iVar2);
    if (iVar1 == 0) {
      iVar1 = FUN_230290e4(iVar2,0);
      if (iVar1 != 0xbad0000) {
        return 0xfffffffb;
      }
      FUN_230290c0(iVar2,0x230264a1,0,0xbad0000,param_4);
      thunk_FUN_0e089e70(0x69,1,0);
    }
  }
  return 0;
}


