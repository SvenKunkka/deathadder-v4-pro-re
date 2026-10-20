/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f4d38. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f4d38(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if ((param_2 == 0) || (param_3 == 0)) {
      uVar1 = 0xffffffea;
    }
    else if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 8) == 0)) {
      uVar1 = 0xffffffb9;
    }
    else {
      uVar1 = FUN_1c0f4b80();
    }
    return uVar1;
  }
  return 0xffffffea;
}


