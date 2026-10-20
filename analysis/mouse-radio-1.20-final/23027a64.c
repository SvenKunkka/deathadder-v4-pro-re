/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027a64. Types and names are inferred; NOT original source. */

void ram_candidate_23027a64(void)

{
  char cVar1;
  int unaff_r4;
  int in_r12;
  
  cVar1 = *(char *)(unaff_r4 + in_r12 + 7);
  if ((cVar1 != '\t') && ((&DAT_2300450c)[in_r12] != '\n')) {
    DAT_230076d2 = DAT_230076d2 | 1;
    DAT_230076b8 = DAT_230076b8 & ~(ushort)(1 << (uint)(byte)(cVar1 - 1));
    ram_candidate_23027290();
    return;
  }
  return;
}


