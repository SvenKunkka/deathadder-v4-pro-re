/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e2ebc. Types and names are inferred; NOT original source. */

void FUN_1c0e2ebc(void)

{
  int iVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = DAT_1c0e2ee8;
  iVar2 = thunk_EXT_FUN_0e094688(DAT_1c0e2ee8);
  if ((iVar2 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 8) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x1c0e2ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar1,4,0x1400000,0x2000000);
    return;
  }
  return;
}


