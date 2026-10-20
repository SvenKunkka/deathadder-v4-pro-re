/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020128. Types and names are inferred; NOT original source. */

undefined4 FUN_23020128(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_30 [32];
  
  bVar1 = *param_2;
  thunk_FUN_0e06f35c(auStack_30,param_1,bVar1);
  if (bVar1 >> 2 != 0) {
    FUN_2302003c(auStack_30,bVar1 >> 2,&DAT_23003020);
    bVar1 = *param_2;
  }
  thunk_FUN_0e06f35c(param_1,auStack_30,bVar1);
  return 1;
}


