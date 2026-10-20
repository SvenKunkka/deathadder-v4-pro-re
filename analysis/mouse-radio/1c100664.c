/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c100664. Types and names are inferred; NOT original source. */

void FUN_1c100664(int param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 0xc);
  if ((UNRECOVERED_JUMPTABLE != (code *)0x0) && (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x1c100676. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),param_2 + -5);
    return;
  }
  return;
}


