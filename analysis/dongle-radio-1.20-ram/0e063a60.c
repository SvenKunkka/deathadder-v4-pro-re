/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063a60. Types and names are inferred; NOT original source. */

void FUN_0e063a60(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0e063754();
  if (iVar1 != 0) {
    for (piVar2 = *(int **)(iVar1 + 0xc);
        (piVar2 != (int *)0x0 && ((1 << (param_2 & 0xff) & piVar2[4]) == 0));
        piVar2 = (int *)*piVar2) {
    }
  }
  return;
}


