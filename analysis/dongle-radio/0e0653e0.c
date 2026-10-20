/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0653e0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0653e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  thunk_FUN_0e06d0a4(param_2,param_3,param_3,*(int *)(param_1 + 0x10),param_4);
  if (-1 < (int)((uint)*(byte *)(param_2 + 0x14) << 0x1e)) {
    if (*(char *)(param_2 + 0x18) < '\0') {
      bVar1 = *(byte *)(param_2 + 0x18) & 0x7f;
    }
    else {
      bVar1 = *(byte *)(param_2 + 0x18) + 0x10;
    }
    FUN_0e06ee5c(iVar2 + 0x9c,1 << bVar1);
    FUN_0e06ee5c(iVar2 + 0x90,2);
  }
  return 0;
}


