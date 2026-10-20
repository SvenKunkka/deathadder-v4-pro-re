/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a708. Types and names are inferred; NOT original source. */

void FUN_0e06a708(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e06ab80(param_2);
  if (((*(int *)(&DAT_23006e5c + param_1 * 0xc) != iVar1) &&
      (*(int *)(&DAT_23006e58 + param_1 * 0xc) != iVar1)) && (iVar1 = FUN_0e06a0d4(), iVar1 != 0)) {
    FUN_0e06ab78();
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


