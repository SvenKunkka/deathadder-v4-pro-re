/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302635c. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_2302635c(void)

{
  int iVar1;
  undefined1 *unaff_r4;
  
  if ((byte)unaff_r4[1] >> 5 == 7) {
    DAT_230071bd = unaff_r4[8];
    if (((DAT_230071bd == '\0') || (DAT_230071bd == '\x03')) && (DAT_230071b2 != '\0')) {
      iVar1 = FUN_230204ac();
      if (iVar1 == 0) {
        FUN_23025954();
      }
      else {
        FUN_23025a44();
      }
      DAT_230071b2 = '\0';
    }
    *unaff_r4 = 2;
  }
  return 1;
}


