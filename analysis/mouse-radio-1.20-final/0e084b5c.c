/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084b5c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e084b5c(undefined1 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 *local_1c;
  int iStack_18;
  undefined1 local_14;
  
  DAT_23006bf0 = param_1;
  if (param_3 != 0) {
    FUN_0e09739c(&DAT_23006bf1);
  }
  iStack_18 = param_3 + 1;
  local_1c = &DAT_23006bf0;
  local_14 = 2;
  iVar1 = FUN_0e08fff4(&DAT_0e0979bc,&local_1c,1,0x6a);
  if (iVar1 == 0) {
    DAT_23006be2 = 0;
    return 1;
  }
  DAT_23006be2 = DAT_23006be2 + '\x01';
  return 0;
}


