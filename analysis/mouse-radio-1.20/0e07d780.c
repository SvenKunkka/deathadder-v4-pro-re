/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07d780. Types and names are inferred; NOT original source. */

void FUN_0e07d780(void)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  bool bVar8;
  uint local_1c [2];
  
  DAT_2300769a = DAT_2300769a + 1;
  DAT_23007696 = DAT_23007696 + 1;
  DAT_230076cc = DAT_230076cc + 1;
  DAT_23007698 = DAT_23007698 + 1;
  DAT_23007694 = DAT_23007694 + 1;
  DAT_230076c2 = DAT_230076c2 + 1;
  DAT_23007778 = DAT_23007778 + '\x01';
  DAT_23007690 = DAT_23007690 + 1;
  if (DAT_230076ce != 0) {
    DAT_230076ce = DAT_230076ce + -1;
  }
  if (DAT_230076c0 != 0) {
    DAT_230076c0 = DAT_230076c0 + -1;
  }
  if ((DAT_23007764 != '\0') &&
     (cVar6 = DAT_23007764 + -1, bVar8 = DAT_23007764 == '\x01', DAT_23007764 = cVar6, bVar8)) {
    DAT_230066f0._0_2_ = 4;
    DAT_230076d2 = DAT_230076d2 | 0x40;
  }
  if (DAT_23007723 == '\x01') {
    cVar6 = DAT_23007723;
    DAT_2300769c = DAT_2300769c + 1;
    DAT_2300769e = DAT_2300769e + 1;
    if (DAT_2300777f == '\0') {
      if ((DAT_230077a2 == '\0') && (DAT_23007733 != '\0')) {
        DAT_230076c4 = DAT_230076c4 + 1;
        if (5999 < DAT_230076c4) {
          DAT_230076c4 = 0;
          FUN_0e0975a0();
          DAT_2300772b = cVar6;
        }
      }
      else {
        DAT_230076c4 = 1;
      }
    }
    else {
      DAT_230076c4 = 0;
    }
  }
  uVar7 = (uint)DAT_23001502;
  uVar2 = FUN_230263ac(&DAT_0e097840,local_1c);
  if (uVar2 == 0) {
    if (((DAT_23007088 ^ local_1c[0]) & 0x20) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  iVar3 = FUN_230263ac(&DAT_0e097840,local_1c);
  if (iVar3 == 0) {
    if (((local_1c[0] ^ DAT_23007088) & 0x10) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
  }
  iVar4 = FUN_230263ac(&DAT_0e097840,local_1c);
  if (iVar4 == 0) {
    if (((DAT_23007088 ^ local_1c[0]) & 0x400) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
    }
  }
  if (((uVar2 | iVar3 << 1 | iVar4 << 2) & uVar7) == 0) {
    DAT_230076d8 = DAT_230076d8 + 1;
  }
  if (DAT_230076ca != 0) {
    DAT_230076ca = DAT_230076ca + -1;
  }
  pcVar5 = (char *)0x230065a8;
  do {
    pcVar1 = pcVar5 + 1;
    if (*pcVar1 != '\0') {
      *(short *)(&DAT_230065a1 + (int)(pcVar5 + -0x23006598) * 2) =
           *(short *)(&DAT_230065a1 + (int)(pcVar5 + -0x23006598) * 2) + 1;
    }
    if (pcVar5[0x4c] != '\0') {
      *(short *)(&DAT_230065a4 + (int)(pcVar5 + -0x23006574) * 2) =
           *(short *)(&DAT_230065a4 + (int)(pcVar5 + -0x23006574) * 2) + 1;
    }
    pcVar5 = pcVar1;
  } while (pcVar1 != (char *)0x230065b0);
  FUN_0e0974f8();
  FUN_0e0975b8();
  FUN_0e07eb54();
  if (DAT_23006774 != '\0') {
    DAT_23006774 = DAT_23006774 + -1;
  }
  if (DAT_23006776 != '\0') {
    DAT_23006776 = DAT_23006776 + -1;
  }
  if ((DAT_23007761 != '\0') && (DAT_23007760 = DAT_23007760 + 1, 0x1d < DAT_23007760)) {
    DAT_23007761 = '\0';
    DAT_23007763 = 1;
  }
  if (DAT_23007795 != '\0') {
    if (DAT_2300679c == 0) {
      DAT_23007795 = 0;
      DAT_2300772b = 1;
      return;
    }
    DAT_2300679c = DAT_2300679c + -1;
  }
  return;
}


