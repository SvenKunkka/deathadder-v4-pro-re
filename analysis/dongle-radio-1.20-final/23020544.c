/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020544. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23020544(void)

{
  ushort uVar1;
  
  thunk_FUN_0e05c200();
LAB_23020568:
  do {
    thunk_FUN_0e06e334(100000,0);
    FUN_23026ea4();
    FUN_23025994();
    if ((DAT_230071b8 == '\0') || (DAT_230071b7 == '\0')) goto LAB_23020560;
    FUN_23025a44();
    DAT_230071b7 = '\0';
    FUN_23025cb0();
  } while (DAT_23002c84 == 0);
  goto LAB_23020598;
LAB_23020560:
  FUN_23025cb0();
  if (DAT_23002c84 != 0) {
LAB_23020598:
    uVar1 = DAT_23002c86 + 1;
    _DAT_23002c84 = CONCAT22(uVar1,DAT_23002c84);
    if (4 < uVar1) {
      _DAT_23002c84 = 0;
      DAT_230071bd = 0;
      FUN_2302060c(1);
    }
  }
  goto LAB_23020568;
}


