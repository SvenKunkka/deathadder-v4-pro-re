/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23026b4c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23026b4c(void)

{
  ushort uVar1;
  undefined4 in_r3;
  
  DAT_23007785 = DAT_23007785 + 1;
  if (DAT_23007784 <= DAT_23007785) {
    DAT_23007785 = 0;
    uVar1 = (ushort)DAT_23007792;
    if ((DAT_23007792 != 0) ||
       (DAT_230076de = DAT_230076de + 1, uVar1 = DAT_230076de, 7 < DAT_230076de)) {
      FUN_230293e0(&DAT_0e0991b0,0x29,&DAT_23007785,uVar1,in_r3);
      if (DAT_2300774e != '\0') {
        _DAT_5f9b300c = 1;
        _DAT_5f9b3000 = 1;
      }
      DAT_230076de = 0;
      if ((DAT_23007792 != 0) && (DAT_230076dc = DAT_230076dc + 1, 1999 < DAT_230076dc)) {
        DAT_23007792 = 0;
        DAT_230076dc = 0;
      }
    }
  }
  return;
}


