/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b229e. Types and names are inferred; NOT original source. */

uint FUN_0e0b229e(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & ~(1 << (param_2 & 0xff));
  return uVar1 >> (param_2 & 0xff) & 1;
}


