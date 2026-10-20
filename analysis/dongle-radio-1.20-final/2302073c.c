/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302073c. Types and names are inferred; NOT original source. */

void FUN_2302073c(int param_1,int param_2)

{
  char cVar1;
  
  param_2 = param_2 + param_1 * 0xf84;
  disableIRQinterrupts();
  cVar1 = *(char *)((int)&DAT_230033e8 + param_2 + 0x15a) + '\x01';
  if (*(char *)((int)&DAT_230033e8 + param_2 + 0x160) == cVar1) {
    cVar1 = '\0';
  }
  *(char *)((int)&DAT_230033e8 + param_2 + 0x15a) = cVar1;
  enableIRQinterrupts();
  return;
}


