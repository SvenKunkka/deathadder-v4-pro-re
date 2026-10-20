/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e0390. Types and names are inferred; NOT original source. */

void FUN_1c0e0390(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  
  pcVar1 = DAT_1c0e03f4;
  if (DAT_1c0e03f4[1] != '\0') {
    if (*DAT_1c0e03f4 == '\0') {
      FUN_1c0dfab0(0,6,param_3,DAT_1c0e03f4[1],param_4);
      pcVar1[1] = '\0';
    }
  }
  if (pcVar1[3] != '\0') {
    if (pcVar1[2] == '\0') {
      FUN_1c0dfab0(0,7);
      pcVar1[3] = '\0';
    }
  }
  pbVar2 = DAT_1c0e03fc;
  if (0x31 < *DAT_1c0e03f8) {
    *DAT_1c0e03f8 = 0;
    uVar3 = (uint)*pbVar2;
    if (uVar3 != 0) {
      if ((int)(uVar3 << 0x1f) < 0) {
        *DAT_1c0e0400 = *DAT_1c0e0400 + -1;
      }
      else if ((int)(uVar3 << 0x1e) < 0) {
        *DAT_1c0e0400 = *DAT_1c0e0400 + '\x01';
      }
      *DAT_1c0e0404 = *DAT_1c0e0404 | 2;
    }
  }
  return;
}


