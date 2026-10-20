/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074d48. Types and names are inferred; NOT original source. */

void FUN_0e074d48(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_23007740 == '\0') {
    return;
  }
  FUN_0e076eb8();
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e097840,10,0x1400000,0x2000000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e09782c);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e09782c,10,0x1400000,0x2000000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e09782c);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e09782c,0xb,0x1400000,0x2000000);
  }
  iVar1 = thunk_FUN_0e094560(&DAT_0e097840);
  if (iVar1 != 0) {
    FUN_2302624c(&DAT_0e097840,3,0x1400000,0x2000000);
  }
  if (((DAT_230077c1 != '\0') && (iVar1 = thunk_FUN_0e094560(DAT_23000e14), iVar1 != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(DAT_23000e14 + 8) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0e074db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(DAT_23000e14,DAT_23000e18,0x1400000,0x2000000);
    return;
  }
  return;
}


