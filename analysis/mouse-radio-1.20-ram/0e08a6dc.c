/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a6dc. Types and names are inferred; NOT original source. */

int FUN_0e08a6dc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    *(char *)(param_2 + 8) = *(char *)(param_2 + 8) + '\x01';
    return param_2;
  }
  do {
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar1 + 4);
  } while (iVar2 != 0);
  *(int *)(iVar1 + 4) = param_2;
  return param_1;
}


