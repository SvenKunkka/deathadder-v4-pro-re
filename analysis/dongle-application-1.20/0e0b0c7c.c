/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0c7c. Types and names are inferred; NOT original source. */

void FUN_0e0b0c7c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_30 [28];
  
  if (param_5 == (uint *)0x0) {
    param_5 = (uint *)FUN_0e0b0c42(auStack_30);
  }
  uVar1 = *param_5;
  iVar3 = *(int *)(param_1 + 8);
  uVar2 = *(uint *)(iVar3 + uVar1 * 4);
  uVar4 = param_5[4];
  if (uVar1 == param_5[1]) {
    if (param_4 == 0) {
      uVar2 = uVar2 & ~uVar4;
    }
    else {
      uVar2 = uVar2 | uVar4;
    }
    *(uint *)(iVar3 + uVar1 * 4) = uVar2;
  }
  else if (param_4 == 0) {
    *(uint *)(iVar3 + uVar1 * 4) = uVar2 & ~uVar4;
    *(uint *)(*(int *)(param_1 + 8) + param_5[1] * 4) =
         *(uint *)(*(int *)(param_1 + 8) + param_5[1] * 4) & ~param_5[5];
    uVar1 = *param_5;
    while (uVar1 = uVar1 + 1, uVar1 < param_5[1]) {
      *(undefined4 *)(*(int *)(param_1 + 8) + uVar1 * 4) = 0;
    }
  }
  else {
    *(uint *)(iVar3 + uVar1 * 4) = uVar2 | uVar4;
    *(uint *)(*(int *)(param_1 + 8) + param_5[1] * 4) =
         *(uint *)(*(int *)(param_1 + 8) + param_5[1] * 4) | param_5[5];
    uVar1 = *param_5;
    while (uVar1 = uVar1 + 1, uVar1 < param_5[1]) {
      *(undefined4 *)(*(int *)(param_1 + 8) + uVar1 * 4) = 0xffffffff;
    }
  }
  return;
}


