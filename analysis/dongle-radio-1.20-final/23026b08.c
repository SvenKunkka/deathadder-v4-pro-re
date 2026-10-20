/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026b08. Types and names are inferred; NOT original source. */

void ram_candidate_23026b08(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  switch(*param_2) {
  case 0:
    iVar1 = thunk_FUN_0e06245c();
    if (iVar1 != 0) {
      thunk_FUN_0e0623ac(param_1);
    }
    DAT_23006904._0_1_ = 0;
    DAT_230071e6 = 0;
    DAT_23006838 = 0;
    DAT_2300683a = 0;
    DAT_23006834 = 0;
    DAT_23006836 = 0;
    DAT_230071e3 = 0;
    return;
  case 1:
    iVar1 = thunk_FUN_0e06245c();
    if (iVar1 != 0) {
      thunk_FUN_0e062414(param_1);
    }
    DAT_230071e6 = 1;
    return;
  case 2:
    DAT_23006908 = 0;
    DAT_2300690a = 0;
    DAT_23006900 = 0;
    DAT_230071e3 = 0;
    DAT_23006902 = 0;
    FUN_230206e4();
    DAT_230071e6 = 2;
    return;
  case 3:
    DAT_23006900 = 0;
    DAT_230071e3 = 0;
    DAT_23006908 = 0;
    DAT_23006902 = 0;
    DAT_2300690a = 0;
    FUN_2302070c();
    DAT_230071e6 = 3;
    break;
  case 4:
    DAT_230071e4 = 0;
    DAT_230071e3 = 0;
    DAT_23006900 = 0;
    DAT_23006908 = 0;
    DAT_23006902 = 0;
    DAT_2300690a = 0;
    FUN_230206c4();
    DAT_230071e6 = 4;
    break;
  case 5:
    DAT_230071e3 = 0;
    DAT_230071e4 = 1;
    DAT_23002c82 = 1;
    FUN_2302539c(0x29);
    thunk_FUN_0e06ddc4(&DAT_23001ea0);
    FUN_23025b40(0xff,0);
    return;
  default:
    goto switchD_23026b12_default;
  }
  DAT_23006838 = 0;
  DAT_23006904._0_1_ = 0;
  DAT_2300683a = 0;
  DAT_23006834 = 0;
  DAT_23006836 = 0;
switchD_23026b12_default:
  return;
}


