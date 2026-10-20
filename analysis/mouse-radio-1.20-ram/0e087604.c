/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087604. Types and names are inferred; NOT original source. */

undefined4 FUN_0e087604(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0xfffffffe;
  }
  if (*(int *)(iVar1 + 8) == 0) {
    return 0xfffffffb;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 8) + 8);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e087622. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar1,param_1[1],param_2,param_3);
    return uVar2;
  }
  return 0xfffffffb;
}


