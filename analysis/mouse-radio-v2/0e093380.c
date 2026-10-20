/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093380. Types and names are inferred; NOT original source. */

int FUN_0e093380(int param_1,uint param_2,int *param_3,uint *param_4,int *param_5,code *param_6,
                uint param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  param_5[2] = param_8;
  *(undefined1 *)(param_5 + 4) = 0;
  *(undefined1 *)(param_5 + 5) = 0;
  param_5[6] = 0;
  *param_5 = param_1;
  param_5[3] = param_1 + param_2;
  if (param_7 < 2) {
    param_5[8] = 0;
    piVar3 = param_3;
  }
  else {
    param_5[8] = (int)(param_5 + param_7 * 9 + -9);
    param_5[param_7 * 9 + -9] = 0;
    *(uint *)(param_5[8] + 8) = param_7 - 2;
    *(undefined4 *)(param_5[8] + 4) = 0;
    *(undefined4 *)(param_5[8] + 0xc) = 0;
    *(undefined1 *)(param_5[8] + 0x10) = 0;
    *(undefined1 *)(param_5[8] + 0x11) = 1;
    *(undefined1 *)(param_5[8] + 0x12) = 0;
    piVar3 = (int *)0x1;
    if (param_7 != 2) {
      *(int **)param_5[8] = param_5 + 9;
      piVar3 = param_5 + 9;
    }
  }
  iVar1 = (*param_6)(param_5,param_3,piVar3,param_6,param_4);
  if (iVar1 == 0) {
    iVar1 = param_5[8];
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0xc);
      *(undefined4 *)(iVar1 + 0xc) = 0;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    return 0x1f;
  }
  if (param_4 != (uint *)0x0) {
    uVar4 = *param_5 - param_1;
    if (param_2 <= (uint)(*param_5 - param_1)) {
      uVar4 = param_2;
    }
    *param_4 = uVar4;
  }
  return 0;
}


