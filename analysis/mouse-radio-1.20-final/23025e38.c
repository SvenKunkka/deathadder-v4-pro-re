/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025e38. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23025e38(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar5;
  char cVar6;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  char *pcVar4;
  
  if (DAT_2300779b == '\x03') {
    if ((DAT_230067d0 == -0x54) && (iVar2 = FUN_23025948(&DAT_230067d0), iVar2 != 0)) {
      return;
    }
    uVar5 = (uint)DAT_2300779c;
    if (uVar5 != 0) {
      cVar6 = '\0';
      pcVar4 = &DAT_230067d0;
      do {
        pcVar3 = pcVar4 + 1;
        cVar6 = cVar6 + *pcVar4;
        pcVar4 = pcVar3;
      } while (&DAT_230067d0 + uVar5 != pcVar3);
joined_r0x23025e92:
      if (cVar6 != '\0') {
        return;
      }
    }
  }
  else {
    uVar5 = (uint)DAT_2300779c;
    if (uVar5 != 0) {
      cVar6 = '\0';
      pcVar4 = &DAT_230067d0;
      do {
        pcVar3 = pcVar4 + 1;
        cVar6 = cVar6 + *pcVar4;
        pcVar4 = pcVar3;
      } while (pcVar3 != &DAT_230067d0 + uVar5);
      goto joined_r0x23025e92;
    }
  }
  if (DAT_2300779b != '\x03') {
    if ((DAT_2300779b == '\x05') && (DAT_230067d0 == 'Z')) {
      uVar1 = thunk_FUN_0e0973ea(&DAT_23003efc,0,0x5a,&DAT_23003efc,unaff_r4,unaff_r5);
      iVar2 = thunk_FUN_0e09739c(uVar1,&DAT_230067d2,(uVar5 - 1 & 0xffff) - 2);
      *(char *)(iVar2 + 0x58) = DAT_230067d1;
      DAT_23007715 = 1;
      DAT_23007797 = 1;
    }
LAB_23020f22:
    if ((char)DAT_23001508 == DAT_23007796) {
      return;
    }
    if (DAT_23007796 != '\0') {
      DAT_23007795 = 0;
      DAT_23001508._0_1_ = DAT_23007796;
      return;
    }
    DAT_23001508._0_1_ = DAT_23007796;
    DAT_2300679c = 15000;
    DAT_23007795 = 1;
    return;
  }
  if (DAT_230067d0 == -0x5d) {
    DAT_2300777f = 0;
    thunk_FUN_0e07ec54();
    DAT_230076e0 = 0;
    DAT_2300777f = 0;
    _DAT_5f9c2004 = 1;
    _DAT_5f9c200c = 1;
    DAT_23007796 = '\0';
    DAT_2300771f = '\0';
    FUN_2302b70c();
    if (DAT_23007723 == '\x01') {
      thunk_FUN_0e07eee8();
    }
    goto LAB_23020f22;
  }
  if (DAT_230067d0 != -0x4f) goto LAB_23020f22;
  if (DAT_230076e0 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_0e085ed0();
  }
  DAT_23007724 = DAT_230067d1;
  if (DAT_230067d1 == '\x01') {
    if (DAT_23004a5f < 8) {
      DAT_23007774 = DAT_23004a5f;
      DAT_23007775 = DAT_230067d1;
      DAT_23007781 = 8;
      DAT_23007776 = DAT_230067d1;
      if (DAT_230067d4 == '\0') goto LAB_23020f76;
    }
    else if (DAT_230067d4 == '\0') goto LAB_23020f86;
  }
  else {
    if (DAT_23007775 != '\0') {
      DAT_23007781 = DAT_23007774;
      DAT_23007775 = '\0';
      DAT_23007776 = '\x01';
    }
    if (DAT_230067d4 == '\0') {
      if (7 < DAT_23004a5f) goto LAB_23020f86;
LAB_23020f76:
      DAT_23007772 = DAT_23004a5f;
      DAT_23007781 = 8;
      DAT_23007773 = '\x01';
      DAT_23007776 = '\x01';
      goto LAB_23020f86;
    }
  }
  if (DAT_23007773 != '\0') {
    DAT_23007781 = DAT_23007772;
    DAT_23007776 = '\x01';
    DAT_23007773 = '\0';
  }
LAB_23020f86:
  DAT_23007771 = DAT_230067d4;
  DAT_23007796 = DAT_230067d5;
  ram_candidate_23021278();
  if ((DAT_23007776 != '\0') && (DAT_2300771f != '\0')) {
    FUN_23026ce0(1,DAT_23007781);
    DAT_23007776 = '\0';
  }
  if (DAT_23007796 != '\0') {
    if (DAT_2300773f == '\x01') {
      DAT_2300773f = '\0';
    }
    if ((char)DAT_23001508 != DAT_23007796) {
      DAT_23001508._0_1_ = DAT_23007796;
      DAT_23007795 = 0;
      return;
    }
    return;
  }
  if (DAT_2300773f == '\x01') {
    DAT_230076d6 = 1;
    DAT_230076d2 = DAT_230076d2 | 1;
  }
  if ((char)DAT_23001508 == '\0') {
    return;
  }
  DAT_23001508._0_1_ = 0;
  DAT_2300679c = 15000;
  DAT_23007795 = 1;
  return;
}


