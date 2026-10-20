/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ffb7c. Types and names are inferred; NOT original source. */

void FUN_1c0ffb7c(undefined4 param_1,uint *param_2)

{
  int iVar1;
  bool bVar2;
  uint local_18 [2];
  
  bVar2 = *(char *)((int)param_2 + 3) < '\0';
  if (bVar2) {
    local_18[0] = ~*param_2;
    param_2 = local_18;
  }
  iVar1 = FUN_1c0ff324(param_2,4);
  FUN_1c0ff9a4(param_1,bVar2,param_2,iVar1 + -1);
  return;
}


