/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0925d0. Types and names are inferred; NOT original source. */

void FUN_0e0925d0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e092a48(param_2);
  if (((*(int *)(&DAT_2300733c + param_1 * 0xc) != iVar1) &&
      (*(int *)(&DAT_23007338 + param_1 * 0xc) != iVar1)) && (iVar1 = FUN_0e091f9c(), iVar1 != 0)) {
    FUN_0e092a40();
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


