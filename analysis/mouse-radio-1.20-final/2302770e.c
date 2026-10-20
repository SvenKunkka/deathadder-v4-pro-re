/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302770e. Types and names are inferred; NOT original source. */

void ram_candidate_2302770e(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int unaff_r4;
  int in_r12;
  
  bVar1 = *(byte *)(unaff_r4 + in_r12 + 6);
  uVar3 = (uint)DAT_23006720;
  uVar5 = 0;
  bVar2 = false;
  pcVar4 = &DAT_2300675c;
  do {
    if (((int)(uint)bVar1 >> (uVar5 & 0xff)) << 0x1f < 0) {
      bVar2 = true;
      *pcVar4 = *pcVar4 + '\x01';
      uVar3 = uVar3 | 1 << (uVar5 & 0xff) & 0xffU;
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 != 8);
  if (bVar2) {
    DAT_23006720 = (byte)uVar3;
  }
  iVar6 = 2;
  pcVar4 = &DAT_23006721;
  do {
    pcVar4 = pcVar4 + 1;
    if (*pcVar4 == '\0') {
      (&DAT_23006720)[iVar6] = *(undefined1 *)(unaff_r4 + in_r12 + 8);
      DAT_230076d2 = DAT_230076d2 | 8;
      ram_candidate_23027290();
      return;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 8);
  ram_candidate_23027290();
  return;
}


