/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fa350. Types and names are inferred; NOT original source. */

void FUN_1c0fa350(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  iVar1 = FUN_1c0f9358(param_1,*(undefined1 *)(param_2 + 0x18));
  if (iVar1 == 0) {
    return;
  }
  if (*(char *)(param_2 + 0x18) < '\0') {
    iVar1 = FUN_1c0fa18c(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),param_2,iVar1)
    ;
    uVar3 = *(undefined1 *)(param_2 + 0x18);
    if (iVar1 != 0) {
      uVar2 = FUN_1c0f92f4(param_1,uVar3);
      FUN_1c0f93b8(param_1,uVar2,0xffffff91,param_4);
      return;
    }
  }
  else {
    FUN_1c0fa09c();
    uVar3 = *(undefined1 *)(param_2 + 0x18);
  }
  FUN_1c0f92a8(param_1,uVar3,1,param_4);
  return;
}


