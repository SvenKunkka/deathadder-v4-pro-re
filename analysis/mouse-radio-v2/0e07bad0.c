/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07bad0. Types and names are inferred; NOT original source. */

void FUN_0e07bad0(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)DAT_0e07bd90[7];
  if (uVar1 < 7) {
    if (uVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x0e07bb04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07bb04::switchdataD_0e07bb08 +
                (&switchD_0e07bb04::switchdataD_0e07bb08)[uVar1]))();
      return;
    }
  }
  else if (((uVar1 ^ 0x80) < 7) && (uVar1 - 0x80 < 7)) {
                    /* WARNING: Could not recover jumptable at 0x0e07baee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0e07baee::switchdataD_0e07baf2 +
              (&switchD_0e07baee::switchdataD_0e07baf2)[uVar1 - 0x80]))();
    return;
  }
  *DAT_0e07bd90 = 3;
  return;
}


