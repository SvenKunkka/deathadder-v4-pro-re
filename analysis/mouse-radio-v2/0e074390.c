/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074390. Types and names are inferred; NOT original source. */

void FUN_0e074390(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  
  pcVar1 = DAT_0e0743f4;
  if (DAT_0e0743f4[1] != '\0') {
    if (*DAT_0e0743f4 == '\0') {
      FUN_0e073ab0(0,6,param_3,DAT_0e0743f4[1],param_4);
      pcVar1[1] = '\0';
    }
  }
  if (pcVar1[3] != '\0') {
    if (pcVar1[2] == '\0') {
      FUN_0e073ab0(0,7);
      pcVar1[3] = '\0';
    }
  }
  pbVar2 = DAT_0e0743fc;
  if (0x31 < *DAT_0e0743f8) {
    *DAT_0e0743f8 = 0;
    uVar3 = (uint)*pbVar2;
    if (uVar3 != 0) {
      if ((int)(uVar3 << 0x1f) < 0) {
        *DAT_0e074400 = *DAT_0e074400 + -1;
      }
      else if ((int)(uVar3 << 0x1e) < 0) {
        *DAT_0e074400 = *DAT_0e074400 + '\x01';
      }
      *DAT_0e074404 = *DAT_0e074404 | 2;
    }
  }
  return;
}


