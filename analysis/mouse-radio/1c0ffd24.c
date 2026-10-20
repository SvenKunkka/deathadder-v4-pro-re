/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ffd24. Types and names are inferred; NOT original source. */

void FUN_1c0ffd24(int param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 0x10);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      FUN_1c1010a8(*(int *)(param_1 + 8) + 4);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x1c0ffd38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),param_2 + -5);
      return;
    }
  }
  return;
}


