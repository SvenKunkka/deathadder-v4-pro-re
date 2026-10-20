/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0622bc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0622bc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80);
  FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff);
  if (iVar2 << 0x1e < 0) {
    if (((int)((uint)*(byte *)(param_1 + 0x60) << 0x1c) < 0) &&
       ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1d) < 0)) {
      iVar2 = *(int *)(param_1 + 0x18);
      iVar3 = *(int *)(iVar2 + 8);
      if (*(int *)(*(int *)(iVar2 + 0x10) + 0xa0) << 0x1e < 0) {
        (**(code **)(iVar3 + 0x3c))(iVar2);
        uVar1 = (**(code **)(iVar3 + 0x20))(iVar2);
        (**(code **)(iVar3 + 0x40))(iVar2);
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else {
      uVar1 = 0xfffffff3;
    }
  }
  else {
    uVar1 = 0xffffff7a;
  }
  FUN_0e06cea8(param_1 + 4);
  return uVar1;
}


