/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065394. Types and names are inferred; NOT original source. */

undefined4 FUN_0e065394(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  uVar1 = FUN_0e0646f8(param_1,0);
  iVar2 = thunk_FUN_0e064c00(param_1,0,param_2);
  if (iVar2 != 0) {
    thunk_FUN_0e06d0a4(uVar1,iVar2);
    FUN_0e06ee5c(iVar3 + 0x9c,0x10000);
    FUN_0e06ee5c(iVar3 + 0x90,2);
    return 0;
  }
  return 0xfffffff4;
}


