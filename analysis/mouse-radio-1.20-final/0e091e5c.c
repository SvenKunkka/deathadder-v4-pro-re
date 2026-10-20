/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091e5c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e091e5c(void)

{
  if (_DAT_53013100 == 0) {
    if (_DAT_53013104 == 0) {
      return;
    }
    _DAT_53013104 = _DAT_53013100;
  }
  else {
    _DAT_53013100 = 0;
    if (_DAT_53013104 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0e091e92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_2300732c)(0x100);
      return;
    }
    _DAT_53013104 = 0;
    (*DAT_2300732c)(0x100,_DAT_53013404,DAT_23007330,0);
  }
  DAT_23007328 = 1;
                    /* WARNING: Could not recover jumptable at 0x0e091eb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_2300732c)(0x104,0,DAT_23007330);
  return;
}


