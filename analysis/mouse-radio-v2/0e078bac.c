/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078bac. Types and names are inferred; NOT original source. */

void FUN_0e078bac(void)

{
  ushort uVar1;
  char *pcVar2;
  ushort *puVar3;
  
  puVar3 = DAT_0e078c0c;
  pcVar2 = DAT_0e078c08;
  if (((*DAT_0e078bf8 == '\x04') && (*DAT_0e078bfc != '\0')) && (*DAT_0e078c00 != '\0')) {
    if (*DAT_0e078c04 == '\0') {
      *DAT_0e078c08 = '\0';
      *puVar3 = 0;
      return;
    }
    if (*DAT_0e078c08 == '\0') {
      uVar1 = *DAT_0e078c0c;
      *DAT_0e078c0c = uVar1 + 1;
      if (500 < (ushort)(uVar1 + 1)) {
        *puVar3 = 0;
        *pcVar2 = '\x01';
        return;
      }
    }
  }
  return;
}


