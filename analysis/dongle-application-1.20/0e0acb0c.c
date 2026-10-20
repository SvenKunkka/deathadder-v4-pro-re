/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0acb0c. Types and names are inferred; NOT original source. */

void FUN_0e0acb0c(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + (uVar1 >> 5) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


