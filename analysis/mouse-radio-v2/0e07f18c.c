/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f18c. Types and names are inferred; NOT original source. */

void FUN_0e07f18c(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = DAT_0e07f1e4;
  if (*(byte *)(DAT_0e07f1dc + 6) < 5) {
                    /* WARNING: Could not recover jumptable at 0x0e07f196. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0e07f196::switchdataD_0e07f19a +
              (uint)(&switchD_0e07f196::switchdataD_0e07f19a)[*(byte *)(DAT_0e07f1dc + 6)] * 2))();
    return;
  }
  *DAT_0e07f1e0 = 0;
  puVar2 = DAT_0e07f1e8;
  *puVar1 = 0;
  *puVar2 = 0;
  return;
}


