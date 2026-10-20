/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d758. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08d758(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x10);
  (**(code **)(iVar3 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar1 = (**(code **)(iVar3 + 0x30))(param_1);
    puVar2 = (uint *)(iVar4 + 0xa0);
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  else {
    uVar1 = 0xffffff88;
  }
  (**(code **)(iVar3 + 0x40))(param_1);
  return uVar1;
}


