/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f28f0. Types and names are inferred; NOT original source. */

int FUN_1c0f28f0(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined1 auStack_38 [32];
  
  if (param_6 == 0) {
    return 0;
  }
  param_3 = param_4 * param_1[6] + *param_1 + param_3;
  uVar2 = -*(int *)param_1[0xf] & param_6;
  if (uVar2 != 0) {
    iVar1 = (**(code **)(*(int *)(param_1[0xe] + 8) + 4))(param_1[0xe],param_3,param_5,uVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_6 = param_6 - uVar2;
    if (param_6 == 0) {
      return 0;
    }
    param_3 = param_3 + uVar2;
    param_5 = param_5 + uVar2;
  }
  FUN_1c1034c4(auStack_38,param_5,param_6);
  piVar3 = (int *)param_1[0xf];
  FUN_1c103512(auStack_38 + param_6,*(undefined1 *)((int)piVar3 + 5),*piVar3 - param_6);
  iVar1 = (**(code **)(*(int *)(param_1[0xe] + 8) + 4))(param_1[0xe],param_3,auStack_38,*piVar3);
  return iVar1;
}


