/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8400. Types and names are inferred; NOT original source. */

void FUN_1c0f8400(int param_1,int param_2,uint param_3)

{
  code *pcVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    piVar2 = *(int **)(param_1 + 0x50);
    if (piVar2 == (int *)0x0) {
      return;
    }
  }
  else {
    if (param_2 != 1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0x1c0f840a);
      (*pcVar1)();
    }
    piVar2 = *(int **)(param_1 + 0x58);
    if (piVar2 == (int *)0x0) {
      return;
    }
  }
  do {
    if (*(byte *)(piVar2[1] + 5) == param_3) {
      return;
    }
    piVar2 = (int *)*piVar2;
  } while (piVar2 != (int *)0x0);
  return;
}


