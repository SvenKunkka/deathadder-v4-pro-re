/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ffc00. Types and names are inferred; NOT original source. */

int FUN_1c0ffc00(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = param_2;
  iVar1 = FUN_1c0ff0e8(param_1,0);
  if (iVar1 != 0) {
    iVar1 = FUN_1c0ff324(&local_c);
    iVar1 = FUN_1c0ff9a4(param_1,4,&local_c,iVar1 + -1);
    if (iVar1 != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      return iVar1;
    }
  }
  return 0;
}


