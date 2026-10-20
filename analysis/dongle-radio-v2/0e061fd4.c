/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061fd4. Types and names are inferred; NOT original source. */

void FUN_0e061fd4(int param_1,code *UNRECOVERED_JUMPTABLE_00)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = DAT_0e062010;
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE_00;
  if (-1 < (int)(*puVar1 << 0x1e)) {
                    /* WARNING: Could not recover jumptable at 0x0e061ff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,(*puVar1 & 3) >> 1);
    return;
  }
  iVar2 = FUN_0e06ada4(*(undefined1 *)(param_1 + 0x20),0,param_1);
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0e06200c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,0xfffffffb);
    return;
  }
  return;
}


