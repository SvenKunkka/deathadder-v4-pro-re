/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06af8c. Types and names are inferred; NOT original source. */

void FUN_0e06af8c(ushort *param_1,int param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((*param_1 & 0x8000) == 0) {
    uVar1 = (*param_1 & 0x3fff) >> 8;
    if (uVar1 < 10) {
      UNRECOVERED_JUMPTABLE = *(code **)(DAT_0e06afbc + uVar1 * 4);
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e06afb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
    }
  }
  else {
    FUN_0e06af88(param_1 + 3,param_2 + -6);
  }
  return;
}


