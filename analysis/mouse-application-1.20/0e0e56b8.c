/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e56b8. Types and names are inferred; NOT original source. */

void FUN_0e0e56b8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

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
  FUN_0e0e5864(param_1,param_2,param_3,&LAB_0e0e54b4_1,param_1,0,0,param_4,0);
  if (param_5 != (int *)0x0) {
    if (*param_5 != 0) {
      FUN_0e0e7136(param_1);
    }
    if (*(char *)((int)param_5 + 5) != '\0') {
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
    }
  }
  thunk_FUN_0e0e5be4(param_1);
  return;
}


