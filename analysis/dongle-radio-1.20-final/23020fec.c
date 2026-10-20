/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020fec. Types and names are inferred; NOT original source. */

void FUN_23020fec(char *param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  char cVar4;
  uint uVar5;
  byte *pbVar6;
  
  DAT_230031fa = *param_1 != '\0';
  DAT_230031fb = param_1[1];
  if (0x27 < DAT_230031fb - 1) {
    DAT_230031fa = 0;
    return;
  }
  pbVar3 = (byte *)(param_1 + 1);
  pcVar2 = (char *)&DAT_230031fb;
  pbVar6 = pbVar3 + DAT_230031fb;
  do {
    while( true ) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if (bVar1 - 2 < 0x7f) break;
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
      if (pbVar3 == pbVar6) {
        return;
      }
    }
    uVar5 = (short)(ushort)(bVar1 >> 4) * 10 + (bVar1 & 0xf);
    if (uVar5 == 2) {
      cVar4 = '%';
    }
    else if (uVar5 < 0x1a) {
      cVar4 = (char)((uVar5 - 4) * 0x800000 >> 0x18);
    }
    else if (uVar5 == 0x1a) {
      cVar4 = '&';
    }
    else if (uVar5 < 0x50) {
      cVar4 = (char)((int)(uVar5 - 0x1c) >> 1) + '\v';
    }
    else {
      cVar4 = '\'';
    }
    pcVar2 = pcVar2 + 1;
    *pcVar2 = cVar4;
  } while (pbVar3 != pbVar6);
  return;
}


