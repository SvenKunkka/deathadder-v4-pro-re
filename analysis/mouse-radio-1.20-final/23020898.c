/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020898. Types and names are inferred; NOT original source. */

void ram_candidate_23020898(void)

{
  uint uVar1;
  
  if (DAT_23007736 == '\0') {
    uVar1 = (uint)DAT_23006c2e;
    DAT_23007735 = 0;
    if (uVar1 == 100) {
      DAT_23007733 = 0xff;
    }
    else if (uVar1 == 0) {
      DAT_23007735 = 100;
      DAT_23007733 = DAT_23006c2e;
    }
    else {
      DAT_23007733 = (char)((uVar1 * 0xff) / 100) + 1;
    }
    DAT_23007736 = 1;
    DAT_23007734 = DAT_23007735;
    if (DAT_2300772c != '\0') {
      DAT_2300772d = 1;
      DAT_23007690 = 0;
      DAT_2300772c = '\0';
    }
    return;
  }
  return;
}


