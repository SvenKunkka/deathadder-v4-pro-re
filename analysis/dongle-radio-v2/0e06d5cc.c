/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d5cc. Types and names are inferred; NOT original source. */

void FUN_0e06d5cc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(int *)(param_1 + 0x98) = param_1 + 0x98;
  *(int *)(param_1 + 0x9c) = param_1 + 0x98;
  *(int *)(param_1 + 0xa0) = param_1 + 0xa0;
  *(int *)(param_1 + 0xa4) = param_1 + 0xa0;
  if (param_5 == (int *)0x0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0x101;
    if ((char)param_5[1] == '\0') {
      uVar1 = 1;
    }
  }
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  FUN_0e06d994(param_1,param_2,param_3,DAT_0e06d648,param_1,0,0,param_4,0);
  if (param_5 != (int *)0x0) {
    if (*param_5 != 0) {
      FUN_0e06d8f0(param_1);
    }
    if (*(char *)((int)param_5 + 5) != '\0') {
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
    }
  }
  thunk_FUN_0e06dde0(param_1);
  return;
}


