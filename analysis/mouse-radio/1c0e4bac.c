/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e4bac. Types and names are inferred; NOT original source. */

void FUN_1c0e4bac(void)

{
  ushort uVar1;
  char *pcVar2;
  ushort *puVar3;
  
  puVar3 = DAT_1c0e4c0c;
  pcVar2 = DAT_1c0e4c08;
  if (((*DAT_1c0e4bf8 == '\x04') && (*DAT_1c0e4bfc != '\0')) && (*DAT_1c0e4c00 != '\0')) {
    if (*DAT_1c0e4c04 == '\0') {
      *DAT_1c0e4c08 = '\0';
      *puVar3 = 0;
      return;
    }
    if (*DAT_1c0e4c08 == '\0') {
      uVar1 = *DAT_1c0e4c0c;
      *DAT_1c0e4c0c = uVar1 + 1;
      if (500 < (ushort)(uVar1 + 1)) {
        *puVar3 = 0;
        *pcVar2 = '\x01';
        return;
      }
    }
  }
  return;
}


