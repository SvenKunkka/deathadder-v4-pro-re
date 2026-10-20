/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6d26. Types and names are inferred; NOT original source. */

void FUN_0e0e6d26(undefined4 param_1,uint *param_2)

{
  uint local_20 [2];
  byte local_18;
  uint local_14;
  
  local_20[0] = *param_2;
  local_18 = (byte)(short)param_2[2] & 0x1f | (byte)(*(short *)((int)param_2 + 10) << 5);
  local_14 = (param_2[1] - 1) + (local_20[0] & 0xffffffe0) & 0xffffffe0;
  FUN_0e0e36a8(param_1,local_20);
  return;
}


