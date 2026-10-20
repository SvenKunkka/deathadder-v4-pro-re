/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c504. Types and names are inferred; NOT original source. */

void FUN_0e05c504(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  DAT_230071da = param_1[1];
  DAT_230071d9 = param_1[2];
  DAT_230071d8 = param_1[3];
  DAT_230071d7 = param_1[4];
  DAT_230071d6 = param_1[5];
  DAT_230071d5 = param_1[6];
  DAT_230071d4 = param_1[7];
  DAT_230071d3 = param_1[8];
  DAT_230071d2 = param_1[9];
  DAT_230071db = cVar1;
  if (cVar1 == '\0') {
    DAT_230071dd = 0;
    if (DAT_230071c7 != '\0') {
      DAT_230071dd = cVar1;
      ram_candidate_23021db0();
      FUN_0e05d230();
      DAT_230071c7 = cVar1;
      return;
    }
  }
  else {
    if ((DAT_230071dd == '\0') && (DAT_230071c7 == '\0')) {
      ram_candidate_23021d9c();
      FUN_0e05d1ac(&DAT_230065e8);
      DAT_230071c7 = '\x01';
    }
    DAT_230071dd = 1;
    DAT_230071dc = 1;
  }
  return;
}


