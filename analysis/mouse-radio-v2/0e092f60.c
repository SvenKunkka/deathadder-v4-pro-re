/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092f60. Types and names are inferred; NOT original source. */

int FUN_0e092f60(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e095808();
  if ((iVar1 == 0) && (*DAT_0e092fd8 == 1)) {
    iVar1 = FUN_0e087790(DAT_0e092fd8 + -2,param_1,param_2);
    return (uint)(iVar1 == 0) << 1;
  }
  if (param_2 < 0x21) {
    local_3a = (undefined2)param_2;
    local_3c = 0x5c;
    FUN_0e0974c4(auStack_38,param_1,param_2);
    iVar1 = FUN_0e094bfc(DAT_0e092fd4,&local_3c,param_3,param_4);
    if (iVar1 == 0) {
      if (*DAT_0e092fd8 != 1) {
        return 0;
      }
      uVar2 = FUN_0e095414(DAT_0e092fdc);
      return (uVar2 >> 0x1f) << 1;
    }
  }
  return 2;
}


