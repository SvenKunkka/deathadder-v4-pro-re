/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e087db0. Types and names are inferred; NOT original source. */

int FUN_0e087db0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = FUN_0e087b24(uVar2,param_3,param_4);
  if (-1 < iVar1) {
    iVar1 = FUN_0e087d20(uVar2,0,*(undefined1 *)(param_2 + 0xc),iVar1,param_4);
    return iVar1;
  }
  FUN_0e087b24(uVar2,param_3,0xffffffff);
  return iVar1;
}


