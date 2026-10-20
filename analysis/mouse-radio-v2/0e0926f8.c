/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0926f8. Types and names are inferred; NOT original source. */

void FUN_0e0926f8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e092b70(param_2);
  if (((*(int *)(DAT_0e09274c + param_1 * 0xc + 4) != iVar1) &&
      (*(int *)(DAT_0e09274c + param_1 * 0xc) != iVar1)) && (iVar1 = FUN_0e0920c4(), iVar1 != 0)) {
    FUN_0e092b68();
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


