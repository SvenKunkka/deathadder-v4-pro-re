/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302676c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_2302676c(void)

{
  undefined4 uVar1;
  undefined1 *unaff_r4;
  
  uVar1 = DAT_23002da0;
  if ((byte)unaff_r4[1] >> 5 == 7) {
    *(undefined4 *)(unaff_r4 + 8) = DAT_23002d94;
    DAT_23002d30 = uVar1;
    _DAT_23002d28 = DAT_23002d98;
    DAT_23002d2c = DAT_23002d9c;
    DAT_23002d34 = DAT_23002da4;
    DAT_23002d38 = (undefined2)DAT_23002da8;
    *unaff_r4 = 2;
    uVar1 = ram_candidate_230266b0();
    return uVar1;
  }
  return 1;
}


