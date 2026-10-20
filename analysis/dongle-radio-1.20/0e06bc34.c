/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc34. Types and names are inferred; NOT original source. */

int FUN_0e06bc34(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = param_2;
  iVar1 = FUN_0e06b11c(param_1,0);
  if (iVar1 != 0) {
    iVar1 = FUN_0e06b358(&local_c);
    iVar1 = FUN_0e06b9d8(param_1,4,&local_c,iVar1 + -1);
    if (iVar1 != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      return iVar1;
    }
  }
  return 0;
}


