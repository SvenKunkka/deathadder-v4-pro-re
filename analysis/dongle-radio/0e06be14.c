/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06be14. Types and names are inferred; NOT original source. */

void FUN_0e06be14(int param_1,int *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  uint local_14 [2];
  
  *param_2 = 0;
  if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
    pcVar2 = *(code **)(**(int **)(param_1 + 0xc) + 8);
    if (((pcVar2 != (code *)0x0) &&
        (local_14[0] = param_3 + 5U, iVar1 = (*pcVar2)(*(int **)(param_1 + 0xc),local_14),
        iVar1 != 0)) && (param_3 + 5U <= local_14[0])) {
      *param_2 = iVar1 + 5;
    }
  }
  return;
}


