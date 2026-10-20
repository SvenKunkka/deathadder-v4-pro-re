/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e34d8. Types and names are inferred; NOT original source. */

void FUN_0e0e34d8(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + (uVar1 >> 5) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


