/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064eb0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064eb0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 4;
  local_14[0] = 6;
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar2 + 0xa0) << 0x1f < 0) {
    *(undefined1 *)(param_2 + 0x1e) = 0;
    *(undefined1 *)(param_2 + 0x1f) = 0;
    *(undefined1 *)(param_2 + 0x20) = 0;
    *(undefined1 *)(param_2 + 0x21) = 0;
    local_10 = param_2;
    local_c = param_1;
    uVar1 = (**(code **)(iVar2 + 0x98))(param_1,local_14);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


