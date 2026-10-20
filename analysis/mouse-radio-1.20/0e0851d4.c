/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0851d4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0851d4(undefined1 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 *local_1c;
  int iStack_18;
  undefined1 local_14;
  
  DAT_23006c40 = param_1;
  if (param_3 != 0) {
    FUN_0e09739c(&DAT_23006c41);
  }
  iStack_18 = param_3 + 1;
  local_1c = &DAT_23006c40;
  local_14 = 2;
  iVar1 = FUN_0e08fff4(&DAT_0e0979a8,&local_1c,1,100);
  if (iVar1 == 0) {
    DAT_23006c25 = 0;
    DAT_23006c24 = 0;
    return 1;
  }
  DAT_23006c24 = DAT_23006c24 + '\x01';
  return 0;
}


