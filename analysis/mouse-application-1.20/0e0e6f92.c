/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6f92. Types and names are inferred; NOT original source. */

uint FUN_0e0e6f92(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & ~(1 << (param_2 & 0xff));
  return uVar1 >> (param_2 & 0xff) & 1;
}


