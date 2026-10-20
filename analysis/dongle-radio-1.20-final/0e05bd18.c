/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05bd18. Types and names are inferred; NOT original source. */

undefined * FUN_0e05bd18(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_2300037c);
  if ((((iVar1 == 0) && (iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_2300035c), iVar1 == 0)) &&
      (iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_23000324), iVar1 == 0)) &&
     (iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_23000310), iVar1 == 0)) {
    iVar1 = FUN_0e062250(&DAT_23001d0c);
    if (iVar1 == 1) {
      iVar1 = FUN_0e06384c(&DAT_23001d0c,1,&DAT_23000268);
      if (iVar1 != 0) {
        return (undefined *)0x0;
      }
      iVar1 = FUN_0e063bac(&DAT_23001d0c,1,1);
      if (iVar1 != 0) {
        return (undefined *)0x0;
      }
      FUN_0e062260(&DAT_23001d0c,1,0,0,0);
    }
    iVar1 = FUN_0e06384c(&DAT_23001d0c,0,&DAT_23000288);
    if ((((iVar1 == 0) && (iVar1 = FUN_0e063bac(&DAT_23001d0c,0,1), iVar1 == 0)) &&
        ((FUN_0e062260(&DAT_23001d0c,0,0,0,0), param_1 == 0 ||
         (iVar1 = FUN_0e064024(&DAT_23001d0c,param_1), iVar1 == 0)))) &&
       (iVar1 = FUN_0e062338(&DAT_23001d0c), iVar1 == 0)) {
      return &DAT_23001d0c;
    }
  }
  return (undefined *)0x0;
}


