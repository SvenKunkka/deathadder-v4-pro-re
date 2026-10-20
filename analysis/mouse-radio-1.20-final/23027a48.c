/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027a48. Types and names are inferred; NOT original source. */

void ram_candidate_23027a48(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  uint uVar5;
  int in_r3;
  int unaff_r4;
  int in_r12;
  
  uVar5 = 0;
  bVar3 = *(byte *)(in_r12 + unaff_r4 + 7);
  pcVar4 = &DAT_23006754;
  iVar1 = (in_r3 + 0x18) * 2;
  do {
    if (((int)(uint)bVar3 >> (uVar5 & 0xff)) << 0x1f < 0) {
      cVar2 = *pcVar4;
      if ((cVar2 == '\0') || (*pcVar4 = cVar2 + -1, cVar2 == '\x01')) {
        (&DAT_230065a2)[iVar1] = (&DAT_230065a2)[iVar1] & ~(byte)(1 << (uVar5 & 0xff));
      }
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 != 8);
  iVar1 = (in_r3 + 8) * 2;
  (&DAT_230065d3)[in_r3 * 2] = 0;
  (&DAT_230065a1)[iVar1] = 0;
  (&DAT_230065a2)[iVar1] = 0;
  (&DAT_230065a9)[in_r3] = 3;
  ram_candidate_23027290();
  return;
}


