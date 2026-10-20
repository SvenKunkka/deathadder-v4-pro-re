/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089ea4. Types and names are inferred; NOT original source. */

void FUN_0e089ea4(void)

{
  disableIRQinterrupts();
  if (DAT_23007660 == 0) {
    enableIRQinterrupts();
    return;
  }
  DAT_23007660 = 0;
  FUN_0e0885c8();
  enableIRQinterrupts();
  return;
}


