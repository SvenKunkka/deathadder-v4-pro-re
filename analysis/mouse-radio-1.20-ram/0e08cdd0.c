/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08cdd0. Types and names are inferred; NOT original source. */

int FUN_0e08cdd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(iVar3 + 4);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (*(int *)(iVar3 + 0x10) << 0x1f < 0) {
    iVar2 = **(int **)(*(int *)(iVar5 + 0x10) + 4);
    uVar1 = *(undefined1 *)(iVar2 + 0x14);
    iVar2 = FUN_0e08a648(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),param_3,param_2,iVar2,0,0);
    if (iVar2 == 0) {
      return -0xc;
    }
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined1 *)(iVar2 + 0x18) = uVar1;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined2 *)(iVar2 + 0x20) = 0;
    uVar6 = FUN_0e08ca2c(iVar5,iVar2);
    if ((int)uVar6 != 0) {
      FUN_0e08a670(iVar2);
      return (int)uVar6;
    }
    iVar5 = 0;
    if (*(int *)(iVar4 + 0x18) == 0) {
      FUN_0e094fc8(iVar3 + 0x14,(int)((ulonglong)uVar6 >> 0x20),0xffffffff,0xffffffff);
      return 0;
    }
  }
  else {
    iVar5 = -0xd;
  }
  return iVar5;
}


