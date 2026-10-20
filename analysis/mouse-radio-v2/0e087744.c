/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087744. Types and names are inferred; NOT original source. */

undefined4 FUN_0e087744(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(param_1 + 8);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e08774e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    return 0;
  }
  return 0xfffffffb;
}


