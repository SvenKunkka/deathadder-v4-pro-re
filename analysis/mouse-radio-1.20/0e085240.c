/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e085240. Types and names are inferred; NOT original source. */

undefined4 FUN_0e085240(undefined1 param_1,uint param_2)

{
  int iVar1;
  undefined1 local_29;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined2 *local_1c;
  uint local_18;
  undefined1 local_14;
  
  if (param_2 < 2) {
    local_28 = &DAT_23006c40;
  }
  else {
    local_28 = &local_29;
    local_29 = param_1;
  }
  local_1c = &DAT_23006c98;
  local_24 = 1;
  local_20 = 0;
  local_14 = 7;
  DAT_23006c40 = param_1;
  local_18 = param_2;
  iVar1 = FUN_0e08fff4(&DAT_0e0979a8,&local_28,2,100);
  if (iVar1 == 0) {
    DAT_23006c25 = 0;
    DAT_23006c24 = 0;
    return 1;
  }
  DAT_23006c24 = DAT_23006c24 + '\x01';
  return 0;
}


