/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1e9e. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0b1e9e(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  puVar1 = *(undefined4 **)(iVar4 + 4);
  if (puVar1 == (undefined4 *)0x0) {
LAB_0e0b1ee6:
    if (param_3 == 0) {
      return 0xffffffea;
    }
  }
  else {
    if (puVar1 == param_2) {
      uVar2 = *param_2;
      *(undefined4 *)(iVar4 + 4) = uVar2;
      if (param_2 == *(undefined4 **)(iVar4 + 8)) {
        *(undefined4 *)(iVar4 + 8) = uVar2;
      }
    }
    else {
      do {
        puVar3 = puVar1;
        puVar1 = (undefined4 *)*puVar3;
        if (puVar1 == (undefined4 *)0x0) goto LAB_0e0b1ee6;
      } while (param_2 != puVar1);
      *puVar3 = *param_2;
      if (param_2 == *(undefined4 **)(iVar4 + 8)) {
        *(undefined4 **)(iVar4 + 8) = puVar3;
      }
    }
    *param_2 = 0;
    if (param_3 == 0) {
      return 0;
    }
  }
  *param_2 = *(undefined4 *)(iVar4 + 4);
  *(undefined4 **)(iVar4 + 4) = param_2;
  if (*(int *)(iVar4 + 8) == 0) {
    *(undefined4 **)(iVar4 + 8) = param_2;
  }
  return 0;
}


