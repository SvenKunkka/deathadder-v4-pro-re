/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08abc0. Types and names are inferred; NOT original source. */

void FUN_0e08abc0(int param_1,code *UNRECOVERED_JUMPTABLE_00)

{
  int iVar1;
  
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE_00;
  if (-1 < (int)(DAT_23006d58 << 0x1e)) {
                    /* WARNING: Could not recover jumptable at 0x0e08abdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,(DAT_23006d58 & 3) >> 1);
    return;
  }
  iVar1 = FUN_0e092bac(*(undefined1 *)(param_1 + 0x20),1,param_1);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0e08abf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,0xfffffffb);
    return;
  }
  return;
}


