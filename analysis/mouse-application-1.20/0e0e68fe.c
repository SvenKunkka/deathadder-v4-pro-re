/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e68fe. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0e68fe(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 0xffffffea;
  }
  else {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      uVar2 = 0xfffffffe;
    }
    else {
      if ((*(int *)(iVar1 + 8) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 8) + 8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0e0e691a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar1,param_1[1],param_2,param_3);
        return uVar2;
      }
      uVar2 = 0xfffffffb;
    }
  }
  return uVar2;
}


