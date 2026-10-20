/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d4e0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08d4e0(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar3 = param_2 & 0xf;
    if ((int)(param_2 << 0x18) < 0) {
      uVar3 = uVar3 + 0x10;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + uVar3 * 4);
    if ((iVar2 == 0) || (-1 < (int)((uint)*(byte *)(iVar2 + 0x14) << 0x1f))) {
      uVar1 = 0xffffffed;
    }
    else if ((*(byte *)(iVar2 + 0x19) & 3) == 1) {
      uVar1 = 0xffffff7a;
    }
    else {
      uVar1 = (**(code **)(iVar4 + 0xc))(param_1);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return uVar1;
}


