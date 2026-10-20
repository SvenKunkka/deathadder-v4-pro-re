/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b840. Types and names are inferred; NOT original source. */

int FUN_0e06b840(undefined4 *param_1,int param_2)

{
  int iVar1;
  int local_18;
  int iStack_14;
  
  iVar1 = param_1[8];
  if (iVar1 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 0) {
      return 0;
    }
  }
  else {
    if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
      return 0;
    }
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      *(undefined4 *)(iVar1 + 0xc) = 8;
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 0) {
      if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0xc) = 10;
      return 0;
    }
  }
  iVar1 = FUN_0e06b50c(param_1,&local_18,8,0);
  if (iVar1 != 0) {
    if (iStack_14 == 0 && local_18 == param_2) {
      return iVar1;
    }
    iVar1 = param_1[8];
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
    if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x10) == '\0' || (*(int *)(iVar1 + 0xc) == 0)))) {
      *(undefined4 *)(iVar1 + 0xc) = 0xb;
    }
  }
  return 0;
}


