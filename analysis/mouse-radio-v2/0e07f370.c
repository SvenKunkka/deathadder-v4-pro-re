/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f370. Types and names are inferred; NOT original source. */

void FUN_0e07f370(void)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = DAT_0e07f35c;
  if (*DAT_0e07f37c == '\0') {
    return;
  }
  if (0xfa < *DAT_0e07f358) {
    *DAT_0e07f358 = 0;
    uVar2 = (uint)*pbVar1;
    if (uVar2 < 4) {
                    /* WARNING: Could not recover jumptable at 0x0e07f316. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07f316::switchdataD_0e07f31a +
                (uint)(&switchD_0e07f316::switchdataD_0e07f31a)[uVar2] * 2))();
      return;
    }
    *pbVar1 = 0;
    return;
  }
  return;
}


