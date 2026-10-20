/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d5ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08d5ac(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *(int *)(param_1 + 8);
  (**(code **)(iVar5 + 0x3c))();
  if ((*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) &&
     (uVar3 = (uint)*(byte *)(param_2 + 0x18), uVar3 != 0)) {
    bVar6 = -1 < (int)(uVar3 << 0x18);
    uVar4 = uVar3;
    if (bVar6) {
      uVar4 = uVar3 & 0xf;
    }
    if (!bVar6) {
      uVar4 = (uVar3 & 0xf) + 0x10;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4);
    if ((iVar2 == 0) || (-1 < (int)((uint)*(byte *)(iVar2 + 0x14) << 0x1f))) {
      uVar1 = 0xffffffed;
    }
    else {
      *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xfe;
      uVar1 = (**(code **)(iVar5 + 4))(param_1,iVar2,param_2);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  (**(code **)(iVar5 + 0x40))(param_1);
  return uVar1;
}


