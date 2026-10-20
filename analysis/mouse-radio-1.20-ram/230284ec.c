/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230284ec. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230284ec(void)

{
  int iVar1;
  uint local_14;
  
  DAT_23007787 = DAT_23007787 + 1;
  DAT_23007786 = DAT_23007786 + 1;
  if (DAT_23007783 <= DAT_23007787) {
    DAT_23007787 = 0;
    if (DAT_2300774c != '\0') {
      _DAT_5f9b200c = 1;
      _DAT_5f9b2000 = 1;
    }
    iVar1 = FUN_230263ac(&DAT_0e09782c,&local_14);
    if ((iVar1 == 0) && (((local_14 ^ DAT_2300707c) & 0x10) == 0)) {
      DAT_23007770 = '\x02';
    }
    else if (DAT_23007770 == '\0') {
      if (DAT_23007786 < DAT_23007782) {
        return;
      }
      goto LAB_2302856e;
    }
    thunk_FUN_0e0952ec(&DAT_23006778);
    DAT_23007786 = 0;
    DAT_23007770 = DAT_23007770 + -1;
  }
  if (DAT_23007786 < DAT_23007782) {
    return;
  }
LAB_2302856e:
  thunk_FUN_0e0952ec(&DAT_23006778);
  DAT_23007786 = 0;
  return;
}


