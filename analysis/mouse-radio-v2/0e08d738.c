/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08d738. Types and names are inferred; NOT original source. */

undefined4 FUN_0e08d738(int param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
    uVar3 = param_2 & 0xf;
    if ((int)(param_2 << 0x18) < 0) {
      uVar3 = uVar3 + 0x10;
    }
    piVar2 = *(int **)(*(int *)(param_1 + 0x10) + uVar3 * 4);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0xffffffed;
    }
    else {
      uVar1 = 0;
      if (*piVar2 != 0) {
        uVar1 = (**(code **)(iVar4 + 8))(param_1);
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return uVar1;
}


