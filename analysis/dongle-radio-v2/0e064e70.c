/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064e70. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064e70(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_24 [4];
  int local_20;
  int iStack_1c;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar3 + 0xa4) == 2) {
    iVar4 = *(int *)(iVar3 + 0xa8);
    iVar1 = FUN_0e064c00(param_1,0x80,*(undefined2 *)(*(int *)(iVar4 + 0xc) + 6));
    if (iVar1 == 0) {
      uVar2 = 0xfffffff4;
    }
    else {
      FUN_0e061c2c(iVar4,iVar1);
      uVar2 = 0;
      *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 2;
    }
    local_20 = *(int *)(iVar3 + 0xa8);
    iVar3 = *(int *)(param_1 + 0x10);
    local_24[0] = 6;
    if (*(int *)(iVar3 + 0xa0) << 0x1f < 0) {
      *(undefined4 *)(local_20 + 0x1e) = uVar2;
      iStack_1c = param_1;
      uVar2 = (**(code **)(iVar3 + 0x98))(param_1,local_24);
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffff7a;
  }
  return uVar2;
}


