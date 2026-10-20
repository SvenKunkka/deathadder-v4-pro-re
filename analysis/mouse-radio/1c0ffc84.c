/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ffc84. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0ffc84(int param_1,code *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_3 + 0x20);
  if (((iVar2 != 0) && (*(char *)(iVar2 + 0x10) != '\0')) && (*(int *)(iVar2 + 0xc) != 0)) {
    return 0;
  }
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      iVar1 = (*param_2)(param_3,param_4);
      iVar2 = iVar2 + 1;
      param_4 = param_4 + param_5;
      if (iVar1 == 0) {
        return 0;
      }
    } while (param_1 != iVar2);
  }
  return 1;
}


