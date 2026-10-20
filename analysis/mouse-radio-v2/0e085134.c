/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085134. Types and names are inferred; NOT original source. */

void FUN_0e085134(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = *(int *)(DAT_0e085174 + 0xc);
    if ((1 << (uint)*(byte *)(DAT_0e085174 + 0x10) & **(uint **)(iVar1 + 0x10)) != 0)
    goto LAB_0e085168;
  }
  else {
    if (*DAT_0e085170 == '\0') {
      return;
    }
    iVar1 = *(int *)(DAT_0e085174 + 0xc);
    if ((1 << (uint)*(byte *)(DAT_0e085174 + 0x10) & **(uint **)(iVar1 + 0x10)) == 0) {
LAB_0e085168:
                    /* WARNING: Could not recover jumptable at 0x0e08516c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)(iVar1 + 8) + 0x10))();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0e085154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(iVar1 + 8) + 0xc))();
  return;
}


