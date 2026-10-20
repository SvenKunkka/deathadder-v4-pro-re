/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fe6f8. Types and names are inferred; NOT original source. */

void FUN_1c0fe6f8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_1c0feb70(param_2);
  if (((*(int *)(DAT_1c0fe74c + param_1 * 0xc + 4) != iVar1) &&
      (*(int *)(DAT_1c0fe74c + param_1 * 0xc) != iVar1)) && (iVar1 = FUN_1c0fe0c4(), iVar1 != 0)) {
    FUN_1c0feb68();
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


