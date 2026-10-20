/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d9bf8. Types and names are inferred; NOT original source. */

void FUN_1c0d9bf8(int param_1,int param_2)

{
  char cVar1;
  
  param_2 = param_2 + param_1 * 0xee0 + DAT_1c0d9c20;
  disableIRQinterrupts();
  cVar1 = *(char *)(param_2 + 0x164) + '\x01';
  if (*(char *)(param_2 + 0x16a) == cVar1) {
    cVar1 = '\0';
  }
  *(char *)(param_2 + 0x164) = cVar1;
  enableIRQinterrupts();
  return;
}


