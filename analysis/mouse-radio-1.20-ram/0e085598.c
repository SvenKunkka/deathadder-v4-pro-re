/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085598. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e085598(char param_1)

{
  int iVar1;
  undefined1 *local_1c;
  undefined4 local_18;
  undefined1 local_14;
  
  local_18 = 2;
  DAT_23006c41 = param_1 << 6;
  local_1c = &DAT_23006c40;
  DAT_23006c40 = 10;
  local_14 = 2;
  iVar1 = FUN_0e08fff4(&DAT_0e0979a8,&local_1c,1,100);
  if (iVar1 == 0) {
    _DAT_23006c24 = 0;
    DAT_230077c1 = param_1;
    return;
  }
  _DAT_23006c24 = CONCAT11(DAT_23006c25,DAT_23006c24 + '\x01');
  DAT_230077c1 = 0;
  return;
}


