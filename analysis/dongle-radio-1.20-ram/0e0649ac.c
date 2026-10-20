/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0649ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0649ac(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((param_2 & 0x7f) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    (**(code **)(iVar2 + 0x3c))();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
      uVar1 = FUN_0e064968(param_1,param_2);
    }
    else {
      uVar1 = 0xffffffff;
    }
    (**(code **)(iVar2 + 0x40))(param_1);
  }
  return uVar1;
}


