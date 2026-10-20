/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f9534. Types and names are inferred; NOT original source. */

undefined4
FUN_1c0f9534(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((param_2 & 0x7f) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    (**(code **)(iVar2 + 0x3c))();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
      uVar1 = FUN_1c0f94a8(param_1,param_2,param_3,param_4,param_5);
    }
    else {
      uVar1 = 0xffffffff;
    }
    (**(code **)(iVar2 + 0x40))(param_1);
  }
  return uVar1;
}


