/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23020e44. Types and names are inferred; NOT original source. */

undefined4 FUN_23020e44(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_30 [32];
  
  bVar1 = *param_2;
  thunk_FUN_0e09739c(auStack_30,param_1,bVar1);
  if (bVar1 >> 2 != 0) {
    FUN_23020d50(auStack_30,bVar1 >> 2,&DAT_23002600);
    bVar1 = *param_2;
  }
  thunk_FUN_0e09739c(param_1,auStack_30,bVar1);
  return 1;
}


