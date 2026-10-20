/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e9638. Types and names are inferred; NOT original source. */

void FUN_1c0e9638(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_1c0e96cc;
  if (param_1 < 0x21) {
    switch(param_1) {
    case 2:
      bVar1 = *DAT_1c0e96cc;
      *DAT_1c0e96d0 = 0;
      *pbVar2 = bVar1 | 1;
      return;
    case 4:
      bVar1 = *DAT_1c0e96cc;
      *DAT_1c0e96d0 = 0;
      *pbVar2 = bVar1 | 2;
      return;
    case 8:
      bVar1 = *DAT_1c0e96cc;
      *DAT_1c0e96d0 = 0;
      *pbVar2 = bVar1 | 4;
      return;
    case 0x20:
      bVar1 = *DAT_1c0e96cc;
      *DAT_1c0e96d0 = 100;
      *pbVar2 = bVar1 | 8;
      return;
    }
  }
  else {
    if (param_1 != 0x40) {
      return;
    }
    bVar1 = *DAT_1c0e96cc;
    *DAT_1c0e96d0 = 100;
    *pbVar2 = bVar1 | 0x10;
  }
  return;
}


