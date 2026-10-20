/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d95e0. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0d95e0(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_30 [32];
  
  bVar1 = *param_2;
  thunk_EXT_FUN_0e0974c4(auStack_30,param_1,bVar1);
  if (bVar1 >> 2 != 0) {
    FUN_1c0d94ec(auStack_30,bVar1 >> 2,DAT_1c0d9614);
    bVar1 = *param_2;
  }
  thunk_EXT_FUN_0e0974c4(param_1,auStack_30,bVar1);
  return 1;
}


