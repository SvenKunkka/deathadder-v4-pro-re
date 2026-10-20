/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d9a90. Types and names are inferred; NOT original source. */

void FUN_1c0d9a90(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_1c0d9acc;
  if (*DAT_1c0d9acc == '\0') {
    FUN_1c0de4b8();
    *pcVar1 = '\x01';
    thunk_EXT_FUN_0e09628c(0x271,0);
  }
  pcVar1 = DAT_1c0d9ad4;
  if (*DAT_1c0d9ad0 != '\0') {
    if (*DAT_1c0d9ad4 == '\0') {
      FUN_1c0de42c(1,2000);
      *pcVar1 = '\x01';
      return;
    }
  }
  return;
}


