/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a7a4. Types and names are inferred; NOT original source. */

void FUN_0e06a7a4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e06ac1c(param_2);
  if (((*(int *)(DAT_0e06a7f8 + param_1 * 0xc + 4) != iVar1) &&
      (*(int *)(DAT_0e06a7f8 + param_1 * 0xc) != iVar1)) && (iVar1 = FUN_0e06a170(), iVar1 != 0)) {
    FUN_0e06ac14();
  }
  if (param_2 + 0xacfd4000U < 0x1065) {
    iVar1 = 0x100;
  }
  else {
    iVar1 = 0x80;
  }
  *(undefined4 *)(iVar1 + param_2) = 0;
  return;
}


