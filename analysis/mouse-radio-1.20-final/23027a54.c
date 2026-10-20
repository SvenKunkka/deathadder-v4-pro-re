/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027a54. Types and names are inferred; NOT original source. */

void ram_candidate_23027a54(void)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int unaff_r4;
  uint uVar7;
  int in_r12;
  
  bVar2 = *(byte *)(unaff_r4 + in_r12 + 7);
  uVar7 = (uint)DAT_23006720;
  uVar5 = 0;
  bVar3 = false;
  pcVar4 = &DAT_2300675c;
  do {
    if (((int)(uint)bVar2 >> (uVar5 & 0xff)) << 0x1f < 0) {
      cVar1 = *pcVar4;
      if ((cVar1 == '\0') || (*pcVar4 = cVar1 + -1, cVar1 == '\x01')) {
        bVar3 = true;
        uVar7 = uVar7 & ~(1 << (uVar5 & 0xff));
      }
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 != 8);
  if (bVar3) {
    DAT_23006720 = (byte)uVar7;
  }
  iVar6 = 2;
  pcVar4 = &DAT_23006721;
  do {
    pcVar4 = pcVar4 + 1;
    if (*pcVar4 == *(char *)(in_r12 + unaff_r4 + 9)) {
      (&DAT_23006720)[iVar6] = 0;
      DAT_230076d2 = DAT_230076d2 | 8;
      ram_candidate_23027290();
      return;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 8);
  ram_candidate_23027290();
  return;
}


