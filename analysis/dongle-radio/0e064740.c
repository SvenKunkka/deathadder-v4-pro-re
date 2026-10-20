/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064740. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064740(int param_1,int param_2)

{
  uint uVar1;
  
  if (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f) {
    uVar1 = *(byte *)(param_2 + 0x18) & 0xf;
    if ((int)((uint)*(byte *)(param_2 + 0x18) << 0x18) < 0) {
      uVar1 = uVar1 + 0x10;
    }
    *(int *)(*(int *)(param_1 + 0x10) + uVar1 * 4) = param_2;
    FUN_0e06d094();
    return 0;
  }
  return 0xfffffff3;
}


