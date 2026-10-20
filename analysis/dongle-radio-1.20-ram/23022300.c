/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022300. Types and names are inferred; NOT original source. */

void ram_candidate_23022300(void)

{
  dword dVar1;
  uint in_r3;
  int unaff_r4;
  
  if (0x1f < in_r3) {
    dVar1 = TIMER020_S_CC_0;
    TIMER020_S_CC_0 = dVar1 - 0x20;
  }
  *(undefined4 *)(unaff_r4 + 0x40) = 0;
  *(undefined4 *)(unaff_r4 + 0x48) = 0;
  return;
}


