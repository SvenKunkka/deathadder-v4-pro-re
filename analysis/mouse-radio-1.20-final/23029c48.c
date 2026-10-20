/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23029c48. Types and names are inferred; NOT original source. */

void ram_candidate_23029c48(void)

{
  dword dVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0x40;
  do {
    while (*(int *)(&UNK_53029100 + uVar3) != 0) {
      *(undefined4 *)(&UNK_53029100 + uVar3) = 0;
      uVar2 = uVar3 >> 2;
      uVar3 = uVar3 + 4;
      uVar4 = uVar4 | 1 << (uVar2 & 0xff);
      if (uVar3 == 0x60) goto LAB_23029c08;
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 != 0x60);
LAB_23029c08:
  uVar3 = 0x40;
  dVar1 = TIMER021_S_INTENSET;
  do {
    uVar2 = 1 << (uVar3 >> 2 & 0xff);
    if (((uVar2 & dVar1 & 0xff0000) != 0) && ((uVar2 & uVar4) != 0)) {
      if (DAT_230072cc != (code *)0x0) {
        (*DAT_230072cc)(uVar3 + 0x100 & 0xffff,DAT_230072d0);
      }
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 != 0x60);
  return;
}


