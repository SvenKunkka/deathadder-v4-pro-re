/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0850c4. Types and names are inferred; NOT original source. */

void FUN_0e0850c4(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0e0850e4 + 4);
  if ((1 << (uint)*(byte *)(DAT_0e0850e4 + 8) & **(uint **)(iVar1 + 0x10)) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0e0850da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(iVar1 + 8) + 0xc))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0e0850e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(iVar1 + 8) + 0x10))();
  return;
}


