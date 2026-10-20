/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07cb6c. Types and names are inferred; NOT original source. */

void FUN_0e07cb6c(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)DAT_0e07cdb4[7];
  if (uVar1 < 0x12) {
    if ((uVar1 != 0) && (uVar1 - 1 < 0x11)) {
                    /* WARNING: Could not recover jumptable at 0x0e07cbac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0e07cbac::switchdataD_0e07cbb0)[uVar1 - 1])();
      return;
    }
  }
  else if (((uVar1 ^ 0x80) < 0xe) && (uVar1 - 0x80 < 0xe)) {
                    /* WARNING: Could not recover jumptable at 0x0e07cb88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0e07cb88::switchdataD_0e07cb8c +
              (uint)*(byte *)((int)&DAT_0e07cb0c + uVar1) * 2))();
    return;
  }
  *DAT_0e07cdb4 = 5;
  return;
}


