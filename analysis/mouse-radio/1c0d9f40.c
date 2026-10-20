/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d9f40. Types and names are inferred; NOT original source. */

void FUN_1c0d9f40(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = DAT_1c0d9f70;
  cVar1 = *DAT_1c0d9f70;
  if (param_3 == 0) {
    if (cVar1 != '\0') {
      *(undefined4 *)(DAT_1c0d9f74 + 0x44) = 1;
      *pcVar2 = '\0';
      return;
    }
  }
  else if (param_2 == 1) {
    if (cVar1 == '\0') {
      *(undefined4 *)(DAT_1c0d9f74 + 0x40) = 1;
      *pcVar2 = '\x01';
      return;
    }
  }
  else if (cVar1 != '\0') {
    *(undefined4 *)(DAT_1c0d9f74 + 0x44) = 1;
    *pcVar2 = '\0';
  }
  return;
}


