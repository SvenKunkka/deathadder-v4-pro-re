/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230264e0. Types and names are inferred; NOT original source. */

void FUN_230264e0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_24 [2];
  
  if (DAT_2300778c != '\x01') {
    return;
  }
  uVar4 = (uint)DAT_23001502;
  uVar1 = FUN_230263ac(&DAT_0e097840,local_24);
  if (uVar1 == 0) {
    if (((local_24[0] ^ DAT_23007088) & 0x20) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  iVar2 = FUN_230263ac(&DAT_0e097840,local_24);
  if (iVar2 == 0) {
    if (((local_24[0] ^ DAT_23007088) & 0x10) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  iVar3 = FUN_230263ac(&DAT_0e097840,local_24);
  if (iVar3 == 0) {
    if (((local_24[0] ^ DAT_23007088) & 0x400) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
  }
  if (((uVar1 | iVar2 << 1 | iVar3 << 2) & uVar4) == 0) {
    if (DAT_2300778d == '\0') {
      DAT_2300778d = '\x01';
      DAT_230076d8 = 0;
    }
    else if (6999 < DAT_230076d8) {
      DAT_2300778e = 0;
      goto LAB_230265c8;
    }
    DAT_2300778e = 1;
  }
  else {
    if (DAT_230077b6 != '\x01') {
      if (6999 < DAT_230076d8) {
        return;
      }
      DAT_2300778d = 0;
      DAT_2300778e = 0;
      return;
    }
LAB_230265c8:
    DAT_230076d8 = 0;
    DAT_2300778b = 0;
    DAT_2300778d = '\0';
    DAT_23007719 = 1;
    DAT_23001504._1_1_ = 0x55;
    DAT_23007717 = 0x8f;
    thunk_FUN_0e080538();
    FUN_2302c430();
    if (DAT_230077b6 == '\0') {
      thunk_FUN_0e0803e4(10,3);
    }
    DAT_2300778c = '\0';
    DAT_230077b6 = '\0';
  }
  return;
}


