/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091048. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091048(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_a4;
  undefined1 auStack_a0 [56];
  undefined1 local_68;
  undefined4 local_64 [23];
  
  FUN_0e097512(auStack_a0,0,0x3c);
  local_68 = 0x11;
  local_a4 = param_1;
  iVar1 = FUN_0e088d38(DAT_0e09107c,&local_a4,local_64,0);
  uVar2 = DAT_0e091080;
  if (iVar1 == 0) {
    uVar2 = local_64[0];
  }
  return uVar2;
}


