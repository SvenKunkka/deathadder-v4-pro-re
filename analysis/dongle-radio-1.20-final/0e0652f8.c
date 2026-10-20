/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0652f8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0652f8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  uVar1 = FUN_0e06465c(param_1,0);
  iVar2 = thunk_FUN_0e064b64(param_1,0,param_2);
  if (iVar2 != 0) {
    thunk_FUN_0e06d008(uVar1,iVar2);
    FUN_0e06edc0(iVar3 + 0x9c,0x10000);
    FUN_0e06edc0(iVar3 + 0x90,2);
    return 0;
  }
  return 0xfffffff4;
}


