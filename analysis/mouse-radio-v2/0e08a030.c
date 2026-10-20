/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a030. Types and names are inferred; NOT original source. */

void FUN_0e08a030(void)

{
  disableIRQinterrupts();
  if (*(int *)(DAT_0e08a04c + 0x14) == 0) {
    enableIRQinterrupts();
    return;
  }
  *(undefined4 *)(DAT_0e08a04c + 0x14) = 0;
  FUN_0e088754();
  enableIRQinterrupts();
  return;
}


