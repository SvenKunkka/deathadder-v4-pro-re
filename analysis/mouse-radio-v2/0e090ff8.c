/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090ff8. Types and names are inferred; NOT original source. */

int FUN_0e090ff8(undefined1 *param_1)

{
  int iVar1;
  undefined4 local_b0;
  undefined1 auStack_ac [60];
  undefined1 local_70;
  int local_6c;
  undefined1 local_68;
  
  if (param_1 == (undefined1 *)0x0) {
    local_6c = -0x16;
  }
  else {
    FUN_0e097512(auStack_ac,0,0x40);
    local_70 = 0x10;
    iVar1 = FUN_0e088d38(DAT_0e091044,auStack_ac,&local_6c,&local_b0);
    if (iVar1 == 0) {
      if (local_6c == 0) {
        *param_1 = local_68;
      }
      thunk_FUN_0e089978(local_b0);
    }
    else {
      thunk_FUN_0e089978(local_b0);
      local_6c = -0x7db;
    }
  }
  return local_6c;
}


