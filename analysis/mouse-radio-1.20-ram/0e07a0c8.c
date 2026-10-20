/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a0c8. Types and names are inferred; NOT original source. */

void FUN_0e07a0c8(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  DAT_2300770c = param_1[1];
  DAT_2300770b = param_1[2];
  DAT_2300770a = param_1[3];
  DAT_23007709 = param_1[4];
  DAT_23007708 = param_1[5];
  DAT_23007707 = param_1[6];
  DAT_23007706 = param_1[7];
  DAT_23007705 = param_1[8];
  DAT_23007704 = param_1[9];
  DAT_2300770d = cVar1;
  if (cVar1 == '\0') {
    DAT_2300770f = 0;
    if (DAT_230076f9 != '\0') {
      DAT_2300770f = cVar1;
      ram_candidate_23022ba8();
      FUN_0e07adf4();
      DAT_230076f9 = cVar1;
      return;
    }
  }
  else {
    if ((DAT_2300770f == '\0') && (DAT_230076f9 == '\0')) {
      ram_candidate_23022b80();
      FUN_0e07ad70(&DAT_23003868);
      DAT_230076f9 = '\x01';
    }
    DAT_2300770f = 1;
    DAT_2300770e = 1;
  }
  return;
}


