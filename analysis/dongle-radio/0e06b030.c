/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b030. Types and names are inferred; NOT original source. */

int FUN_0e06b030(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e06d8cc();
  if ((iVar1 == 0) && (*DAT_0e06b0a8 == 1)) {
    iVar1 = FUN_0e05eecc(DAT_0e06b0a8 + -2,param_1,param_2);
    return (uint)(iVar1 == 0) << 1;
  }
  if (param_2 < 0x21) {
    local_3a = (undefined2)param_2;
    local_3c = 0x5c;
    FUN_0e06f3f8(auStack_38,param_1,param_2);
    iVar1 = FUN_0e06cc78(DAT_0e06b0a4,&local_3c,param_3,param_4);
    if (iVar1 == 0) {
      if (*DAT_0e06b0a8 != 1) {
        return 0;
      }
      uVar2 = FUN_0e06d4d8(DAT_0e06b0ac);
      return (uVar2 >> 0x1f) << 1;
    }
  }
  return 2;
}


