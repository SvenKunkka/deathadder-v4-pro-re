/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093ad8. Types and names are inferred; NOT original source. */

int FUN_0e093ad8(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = param_2;
  iVar1 = FUN_0e092fc0(param_1,0);
  if (iVar1 != 0) {
    iVar1 = FUN_0e0931fc(&local_c);
    iVar1 = FUN_0e09387c(param_1,4,&local_c,iVar1 + -1);
    if (iVar1 != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      return iVar1;
    }
  }
  return 0;
}


