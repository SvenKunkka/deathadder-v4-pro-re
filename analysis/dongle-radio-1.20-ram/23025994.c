/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025994. Types and names are inferred; NOT original source. */

void FUN_23025994(void)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  
  if (DAT_230071b9 != '\0') {
    DAT_2300719c = DAT_2300719c + 1;
    if (DAT_23000b52 <= DAT_2300719c) {
      bVar1 = DAT_230071b1 & 1;
      if ((DAT_230071b1 & 1) == 0) {
        pcVar3 = &DAT_23002cb4;
        do {
          if (*pcVar3 == '\x01') {
            FUN_23025ce0(bVar1,0xff,0);
          }
          bVar1 = bVar1 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar1 != 3);
      }
      else {
        cVar2 = '\0';
        pcVar3 = &DAT_23002cb4;
        do {
          if (*pcVar3 == '\x01') {
            FUN_23025ce0(cVar2,0,0);
          }
          cVar2 = cVar2 + '\x01';
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\x03');
      }
      DAT_230071b1 = DAT_230071b1 + 1;
      if (DAT_230071b1 < 4) {
        DAT_23000b52 = 1;
      }
      else {
        DAT_230071b1 = 0;
        DAT_23000b52 = 10;
      }
      DAT_2300719c = 0;
    }
    return;
  }
  DAT_2300719c = 0;
  DAT_230071b1 = DAT_230071b9;
  DAT_23000b52 = 1;
  return;
}


