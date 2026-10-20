/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062414. Types and names are inferred; NOT original source. */

undefined4 FUN_0e062414(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1e) < 0) {
    FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
    FUN_0e063788(param_1,0);
    uVar1 = FUN_0e064c60(*(undefined4 *)(param_1 + 0x18));
    *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) & 0xfd;
    FUN_0e06cea8(param_1 + 4);
  }
  else {
    uVar1 = 0xffffff88;
  }
  return uVar1;
}


