/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f064. Types and names are inferred; NOT original source. */

void FUN_0e07f064(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  pbVar1 = DAT_0e07f048;
  if (*DAT_0e07f070 == '\0') {
    return;
  }
  if (0xfa < *DAT_0e07f044) {
    *DAT_0e07f044 = 0;
    puVar2 = DAT_0e07f04c;
    uVar3 = (uint)*pbVar1;
    if (uVar3 < 5) {
                    /* WARNING: Could not recover jumptable at 0x0e07efce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07efce::switchdataD_0e07efd2 +
                (uint)(&switchD_0e07efce::switchdataD_0e07efd2)[uVar3] * 2))();
      return;
    }
    *pbVar1 = 0;
    *puVar2 = 0;
    return;
  }
  return;
}


