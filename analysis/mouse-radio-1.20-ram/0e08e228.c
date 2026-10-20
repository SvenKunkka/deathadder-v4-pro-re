/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08e228. Types and names are inferred; NOT original source. */

void FUN_0e08e228(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  iVar1 = FUN_0e08d230(param_1,*(undefined1 *)(param_2 + 0x18));
  if (iVar1 == 0) {
    return;
  }
  if (*(char *)(param_2 + 0x18) < '\0') {
    iVar1 = FUN_0e08e064(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),param_2,iVar1)
    ;
    uVar3 = *(undefined1 *)(param_2 + 0x18);
    if (iVar1 != 0) {
      uVar2 = FUN_0e08d1cc(param_1,uVar3);
      FUN_0e08d290(param_1,uVar2,0xffffff91,param_4);
      return;
    }
  }
  else {
    FUN_0e08df74();
    uVar3 = *(undefined1 *)(param_2 + 0x18);
  }
  FUN_0e08d180(param_1,uVar3,1,param_4);
  return;
}


