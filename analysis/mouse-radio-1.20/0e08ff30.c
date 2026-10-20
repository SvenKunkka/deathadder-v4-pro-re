/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ff30. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e08ff30(undefined4 param_1,uint param_2)

{
  uint local_18;
  uint local_14;
  
  if (7 < param_2) {
    param_2 = 8;
  }
  local_18 = _DAT_0fffe014 << 0x18 | ((_DAT_0fffe014 & 0xff00) >> 8) << 0x10 |
             (((_DAT_0fffe018 & 0xff) << 0x10 | _DAT_0fffe014 & 0xff0000) >> 0x10) << 8 |
             (_DAT_0fffe014 | _DAT_0fffe028 << 0x18) >> 0x18;
  local_14 = _DAT_0fffe010 << 0x18 | (_DAT_0fffe010 >> 8 & 0xff) << 0x10 |
             (_DAT_0fffe010 >> 0x10 & 0xff) << 8 | _DAT_0fffe010 >> 0x18;
  FUN_0e09739c(param_1,&local_18,param_2);
  return param_2;
}


