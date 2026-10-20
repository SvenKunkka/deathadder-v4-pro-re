/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5ebc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0e5ebc(uint param_1,int param_2,undefined4 param_3)

{
  uint local_10;
  int local_c;
  undefined4 uStack_8;
  
  if (_DAT_2f01190c == 0) {
    local_10 = param_1;
    local_c = param_2;
    uStack_8 = param_3;
    FUN_0e0e45f4(&local_10);
    return local_10 - _DAT_2f0113f0 >> 5 |
           ((local_c - _DAT_2f0113f4) - (uint)(local_10 < _DAT_2f0113f0)) * 0x8000000;
  }
  return 0;
}


