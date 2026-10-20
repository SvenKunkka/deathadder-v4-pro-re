/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06aeb0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06aeb0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0e06aecc;
  if (*(char *)(DAT_0e06aecc + 1) == '\0') {
    *DAT_0e06aecc = param_1;
    *(undefined1 *)(puVar1 + 1) = 1;
    return 0;
  }
  return 1;
}


