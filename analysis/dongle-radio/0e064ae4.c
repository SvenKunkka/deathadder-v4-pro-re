/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064ae4. Types and names are inferred; NOT original source. */

int FUN_0e064ae4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar2 = param_2 & 0xf;
    if ((int)(param_2 << 0x18) < 0) {
      uVar2 = uVar2 + 0x10;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x10) + uVar2 * 4);
    if ((iVar3 == 0) || (-1 < (int)((uint)*(byte *)(iVar3 + 0x14) << 0x1f))) {
      iVar1 = -0x13;
    }
    else if ((*(byte *)(iVar3 + 0x19) & 3) == 1) {
      iVar1 = -0x86;
    }
    else {
      iVar1 = (**(code **)(iVar4 + 0x10))
                        (param_1,iVar3,*(int *)(param_1 + 0x10),*(code **)(iVar4 + 0x10),param_4);
      if (iVar1 == 0) {
        *(byte *)(iVar3 + 0x14) = *(byte *)(iVar3 + 0x14) & 0xfd;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return iVar1;
}


