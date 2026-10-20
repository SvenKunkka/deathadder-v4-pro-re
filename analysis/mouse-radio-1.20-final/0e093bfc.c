/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093bfc. Types and names are inferred; NOT original source. */

void FUN_0e093bfc(int param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 0x10);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      FUN_0e094f80(*(int *)(param_1 + 8) + 4);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0e093c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),param_2 + -5);
      return;
    }
  }
  return;
}


