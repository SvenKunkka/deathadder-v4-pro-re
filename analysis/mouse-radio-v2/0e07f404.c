/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f404. Types and names are inferred; NOT original source. */

void FUN_0e07f404(void)

{
  ushort *puVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  pbVar2 = DAT_0e07f510;
  puVar1 = DAT_0e07f50c;
  if (*DAT_0e07f504 == '\0') {
    if (*DAT_0e07f50c < *DAT_0e07f508) {
      *DAT_0e07f508 = 0;
      puVar3 = DAT_0e07f528;
      uVar4 = (uint)*pbVar2;
      if (uVar4 < 5) {
                    /* WARNING: Could not recover jumptable at 0x0e07f424. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0e07f424::switchdataD_0e07f428 +
                  (uint)(&switchD_0e07f424::switchdataD_0e07f428)[uVar4] * 2))();
        return;
      }
      *pbVar2 = 0;
      *puVar3 = 0;
      *puVar1 = 200;
      return;
    }
  }
  return;
}


