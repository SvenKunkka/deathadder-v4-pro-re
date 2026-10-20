/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084bc0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e084bc0(byte *param_1,ushort *param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte local_31;
  byte *local_30;
  uint local_2c;
  undefined1 local_28;
  undefined2 *local_24;
  uint local_20;
  undefined1 local_1c;
  
  local_2c = (uint)*param_1;
  if (local_2c == 2) {
    uVar1 = FUN_0e084b5c(param_1[1],param_1 + 4,param_1[10]);
    return uVar1;
  }
  if (local_2c == 4) {
    DAT_23006bde = *(undefined2 *)(param_1 + 8);
LAB_0e084c4e:
    uVar1 = 1;
  }
  else {
    if (local_2c == 1) {
      local_20 = (uint)param_1[10];
      DAT_23006bf0 = param_1[1];
      if (local_20 < 2) {
        local_30 = &DAT_23006bf0;
      }
      else {
        local_30 = &local_31;
        local_31 = DAT_23006bf0;
      }
      local_24 = &DAT_23006c00;
      local_28 = 0;
      local_1c = 7;
      iVar2 = FUN_0e08fff4(&DAT_0e0979bc,&local_30,2,0x6a);
      if (iVar2 == 0) {
        DAT_23006be2 = '\0';
        if (param_2 != (ushort *)0x0) {
          if (param_1[10] == 1) {
            *param_2 = DAT_23006c00 & 0xff;
          }
          else if (param_1[10] == 2) {
            *param_2 = DAT_23006c00;
          }
        }
        goto LAB_0e084c4e;
      }
      DAT_23006be2 = DAT_23006be2 + '\x01';
    }
    uVar1 = 0;
  }
  return uVar1;
}


