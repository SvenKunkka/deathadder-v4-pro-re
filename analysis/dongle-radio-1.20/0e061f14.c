/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061f14. Types and names are inferred; NOT original source. */

void FUN_0e061f14(int param_1,code *UNRECOVERED_JUMPTABLE_00)

{
  int iVar1;
  
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE_00;
  if (-1 < (int)(DAT_23006958 << 0x1e)) {
                    /* WARNING: Could not recover jumptable at 0x0e061f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,(DAT_23006958 & 3) >> 1);
    return;
  }
  iVar1 = FUN_0e06ad08(*(undefined1 *)(param_1 + 0x20),1,param_1);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0e061f4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,0xfffffffb);
    return;
  }
  return;
}


