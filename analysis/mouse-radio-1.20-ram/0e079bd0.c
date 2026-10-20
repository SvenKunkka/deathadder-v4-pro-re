/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e079bd0. Types and names are inferred; NOT original source. */

undefined * FUN_0e079bd0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0e08aff0(&DAT_2300177c,&DAT_2300041c);
  if ((((iVar1 == 0) && (iVar1 = FUN_0e08aff0(&DAT_2300177c,&DAT_230003fc), iVar1 == 0)) &&
      (iVar1 = FUN_0e08aff0(&DAT_2300177c,&DAT_230003c4), iVar1 == 0)) &&
     (iVar1 = FUN_0e08aff0(&DAT_2300177c,&DAT_230003b0), iVar1 == 0)) {
    iVar1 = FUN_0e08ad9c(&DAT_2300177c);
    if (iVar1 == 1) {
      iVar1 = FUN_0e08c398(&DAT_2300177c,1,&DAT_23000308);
      if (iVar1 != 0) {
        return (undefined *)0x0;
      }
      iVar1 = FUN_0e08c6f8(&DAT_2300177c,1,1);
      if (iVar1 != 0) {
        return (undefined *)0x0;
      }
      FUN_0e08adac(&DAT_2300177c,1,0,0,0);
    }
    iVar1 = FUN_0e08c398(&DAT_2300177c,0,&DAT_23000328);
    if ((((iVar1 == 0) && (iVar1 = FUN_0e08c6f8(&DAT_2300177c,0,1), iVar1 == 0)) &&
        ((FUN_0e08adac(&DAT_2300177c,0,0,0,0), param_1 == 0 ||
         (iVar1 = FUN_0e08cb6c(&DAT_2300177c,param_1), iVar1 == 0)))) &&
       (iVar1 = FUN_0e08ae84(&DAT_2300177c), iVar1 == 0)) {
      return &DAT_2300177c;
    }
  }
  return (undefined *)0x0;
}


