/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f9980. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f9980(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_24 [4];
  int local_20;
  int iStack_1c;
  
  iVar3 = *(int *)(param_1 + 0x10);
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 2;
  FUN_1c0f6868(*(undefined4 *)(iVar3 + 0xa8));
  iVar1 = FUN_1c0f9784(param_1,0x80,0);
  if (iVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    FUN_1c0f6868(param_2,iVar1);
    uVar2 = 0;
    *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 4;
  }
  local_20 = *(int *)(iVar3 + 0xa8);
  iVar1 = *(int *)(param_1 + 0x10);
  local_24[0] = 6;
  if (*(int *)(iVar1 + 0xa0) << 0x1f < 0) {
    *(undefined4 *)(local_20 + 0x1e) = uVar2;
    iStack_1c = param_1;
    uVar2 = (**(code **)(iVar1 + 0x98))(param_1,local_24);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


