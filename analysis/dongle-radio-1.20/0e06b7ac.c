/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b7ac. Types and names are inferred; NOT original source. */

int FUN_0e06b7ac(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 2) {
      return 0;
    }
  }
  else {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      pbVar1 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar1) {
LAB_0e06b7f8:
        *(undefined4 *)(iVar2 + 0xc) = 8;
        return 0;
      }
    }
    else {
      if (*(int *)(iVar2 + 0xc) != 0) {
        return 0;
      }
      pbVar1 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar1) goto LAB_0e06b7f8;
    }
    if (*pbVar1 >> 5 != 2) {
      if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar2 + 0xc) = 10;
      return 0;
    }
  }
  iVar2 = FUN_0e06b470(param_1,param_2 + 1,4,0,param_4);
  if (iVar2 != 0) {
    iVar3 = *param_1;
    *param_2 = iVar3;
    if ((uint)param_2[1] <= (uint)(param_1[3] - iVar3)) {
      *param_1 = iVar3 + param_2[1];
      return iVar2;
    }
    iVar2 = param_1[8];
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
    if ((iVar2 != 0) && ((*(char *)(iVar2 + 0x10) == '\0' || (*(int *)(iVar2 + 0xc) == 0)))) {
      *(undefined4 *)(iVar2 + 0xc) = 8;
    }
  }
  return 0;
}


