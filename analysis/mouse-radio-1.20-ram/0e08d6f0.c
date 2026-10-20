/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d6f0. Types and names are inferred; NOT original source. */

int FUN_0e08d6f0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x10);
  (**(code **)(iVar5 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0x10) + 0xa0);
    uVar2 = (uVar3 & 3) >> 1;
    if ((int)(uVar3 << 0x1e) < 0) {
      iVar1 = -0x78;
    }
    else {
      *(uint *)(iVar4 + 0xa4) = uVar2;
      *(uint *)(iVar4 + 0xa8) = uVar2;
      iVar1 = (**(code **)(iVar5 + 0x2c))(param_1);
      if (iVar1 == 0) {
        *(uint *)(iVar4 + 0xa0) = *(uint *)(iVar4 + 0xa0) | 2;
        (**(code **)(iVar5 + 0x40))(param_1);
        return 0;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  (**(code **)(iVar5 + 0x40))(param_1);
  return iVar1;
}


