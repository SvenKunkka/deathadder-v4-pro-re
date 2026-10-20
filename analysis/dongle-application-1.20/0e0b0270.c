/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0270. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0b0270(uint param_1,int param_2,undefined4 param_3)

{
  uint local_10;
  int local_c;
  undefined4 uStack_8;
  
  if (_DAT_2f011bd0 == 0) {
    local_10 = param_1;
    local_c = param_2;
    uStack_8 = param_3;
    FUN_0e0ae8d4(&local_10);
    return local_10 - _DAT_2f011680 >> 5 |
           ((local_c - _DAT_2f011684) - (uint)(local_10 < _DAT_2f011680)) * 0x8000000;
  }
  return 0;
}


