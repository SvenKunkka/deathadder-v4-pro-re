/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f3bd8. Types and names are inferred; NOT original source. */

uint FUN_1c0f3bd8(int *param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  iVar1 = *param_1;
  uVar2 = (uint)(param_2 - *(int *)(iVar1 + 0x10)) / *(uint *)(iVar1 + 0x14);
  if ((uVar2 < *(uint *)(iVar1 + 0x18)) &&
     (param_2 == uVar2 * *(uint *)(iVar1 + 0x14) + *(int *)(iVar1 + 0x10) + 4)) {
    if (-1 < (int)uVar2) {
      local_1a = (undefined1)uVar2;
      local_1c = param_3;
      local_1b = param_4;
      FUN_1c100d84(param_1 + 0x1e,param_2,0xffffffff,0xffffffff);
      uVar2 = FUN_1c0f440c(iVar1,param_1 + 2,&local_1c,3);
      FUN_1c100e80(param_1 + 0x1e);
    }
    return uVar2;
  }
  return 0xffffffea;
}


