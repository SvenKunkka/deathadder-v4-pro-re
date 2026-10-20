/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e074efc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e074efc(void)

{
  int iVar1;
  uint local_14;
  
  DAT_23007787 = DAT_23007787 + 1;
  DAT_23007786 = DAT_23007786 + 1;
  if (DAT_23007787 < DAT_23007783) {
LAB_0e074f62:
    if (DAT_23007786 < DAT_23007782) goto LAB_0e074f6a;
  }
  else {
    DAT_23007787 = 0;
    if (DAT_2300774c != '\0') {
      _DAT_5f9b200c = 1;
      _DAT_5f9b2000 = 1;
    }
    iVar1 = FUN_230263ac(&DAT_0e09782c,&local_14);
    if ((iVar1 == 0) && (((local_14 ^ DAT_2300707c) & 0x10) == 0)) {
      DAT_23007770 = '\x02';
LAB_0e074f50:
      thunk_FUN_0e0952ec(&DAT_23006778);
      DAT_23007786 = 0;
      DAT_23007770 = DAT_23007770 + -1;
      goto LAB_0e074f62;
    }
    if (DAT_23007770 != '\0') goto LAB_0e074f50;
    if (DAT_23007786 < DAT_23007782) goto LAB_0e074f6a;
  }
  thunk_FUN_0e0952ec(&DAT_23006778);
  DAT_23007786 = 0;
LAB_0e074f6a:
  DAT_23007785 = DAT_23007785 + 1;
  if ((DAT_23007784 <= DAT_23007785) &&
     ((DAT_23007785 = 0, DAT_23007792 != '\0' || (DAT_230076de = DAT_230076de + 1, 7 < DAT_230076de)
      ))) {
    FUN_0e075b7c(&DAT_0e0991b0,0x29);
    if (DAT_2300774e != '\0') {
      _DAT_5f9b300c = 1;
      _DAT_5f9b3000 = 1;
    }
    DAT_230076de = 0;
    if ((DAT_23007792 != '\0') && (DAT_230076dc = DAT_230076dc + 1, 1999 < DAT_230076dc)) {
      DAT_23007792 = '\0';
      DAT_230076dc = 0;
    }
  }
  DAT_2300776d = DAT_2300776d + 1;
  if (DAT_23007780 <= DAT_2300776d) {
    DAT_2300776d = 0;
    FUN_0e094f80(&DAT_230016a4);
    return;
  }
  return;
}


