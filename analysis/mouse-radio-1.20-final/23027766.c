/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23027766. Types and names are inferred; NOT original source. */

void ram_candidate_23027766(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int unaff_r4;
  int in_r12;
  
  cVar1 = *(char *)(in_r12 + unaff_r4 + 6);
  if (cVar1 == '\t') {
    if (DAT_23007765 == '\0') {
      DAT_2300778a = DAT_2300778a + '\x01';
      ram_candidate_23027290();
      return;
    }
    if (0xaf63 < (ushort)DAT_23004a8c) {
      DAT_23004a8c._0_2_ = 0xaf64;
    }
    if (0xaf63 < DAT_23004a8c._2_2_) {
      DAT_23004a8c._2_2_ = 0xaf64;
    }
    sVar2 = (ushort)DAT_23004a8c + 100;
    uVar4 = (uint)DAT_23004477;
    sVar3 = DAT_23004a8c._2_2_ + 100;
    DAT_23004a8c._0_2_ = sVar2;
    DAT_23004a8c._2_2_ = sVar3;
    *(short *)(&DAT_230044ca + uVar4 * 0xf4) = sVar2;
    *(short *)(&DAT_230044cc + uVar4 * 0xf4) = sVar3;
  }
  else {
    if (cVar1 != '\n') {
      DAT_230076d2 = DAT_230076d2 | 1;
      DAT_230076b8 = (ushort)(1 << (uint)(byte)(cVar1 - 1)) | DAT_230076b8;
      ram_candidate_23027290();
      return;
    }
    if (DAT_23007765 == '\0') {
      DAT_2300778a = DAT_2300778a + -1;
      ram_candidate_23027290();
      return;
    }
    if ((ushort)DAT_23004a8c < 100) {
      DAT_23004a8c._0_2_ = 100;
    }
    if (DAT_23004a8c._2_2_ < 100) {
      DAT_23004a8c._2_2_ = 100;
    }
    sVar2 = (ushort)DAT_23004a8c - 100;
    uVar4 = (uint)DAT_23004477;
    sVar3 = DAT_23004a8c._2_2_ - 100;
    DAT_23004a8c._0_2_ = sVar2;
    DAT_23004a8c._2_2_ = sVar3;
    *(short *)(&DAT_230044ca + uVar4 * 0xf4) = sVar2;
    *(short *)(&DAT_230044cc + uVar4 * 0xf4) = sVar3;
  }
  thunk_FUN_0e08042c(sVar2,sVar3);
  thunk_FUN_0e07d4ac(8,DAT_23004477);
  return;
}


