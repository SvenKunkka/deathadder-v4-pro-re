/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a1b0. Types and names are inferred; NOT original source. */

void FUN_0e07a1b0(undefined1 *param_1)

{
  char cVar1;
  
  cVar1 = DAT_23007703;
  if (DAT_23007703 == '\0') {
    if (DAT_2300770f == '\x01') {
      if (DAT_230076f9 == '\0') {
        DAT_2300770f = DAT_230076f9;
      }
      else {
        ram_candidate_23022ba8();
        FUN_0e07adf4();
        DAT_230076f9 = cVar1;
        DAT_2300770f = cVar1;
      }
    }
    else if (DAT_230076f9 != '\0') goto LAB_0e07a1de;
  }
  else if (DAT_230076f9 != '\0') {
    ram_candidate_23022ba8();
    FUN_0e07adf4();
    DAT_230076f9 = '\0';
  }
  ram_candidate_23022b80();
  FUN_0e07ad70(&DAT_23003868);
  DAT_230076f9 = '\x01';
LAB_0e07a1de:
  DAT_23007703 = 1;
  DAT_23007701 = *param_1;
  DAT_23007700 = param_1[1];
  DAT_230076ff = param_1[2];
  DAT_230076fe = param_1[3];
  DAT_230076fd = param_1[4];
  DAT_230076fc = param_1[5];
  DAT_2300768a = *(ushort *)(param_1 + 6) << 8 | *(ushort *)(param_1 + 6) >> 8;
  DAT_23007688 = *(ushort *)(param_1 + 8) << 8 | *(ushort *)(param_1 + 8) >> 8;
  DAT_23007686 = *(ushort *)(param_1 + 10) << 8 | *(ushort *)(param_1 + 10) >> 8;
  DAT_23007684 = *(ushort *)(param_1 + 0xc) << 8 | *(ushort *)(param_1 + 0xc) >> 8;
  DAT_23007702 = 1;
  return;
}


