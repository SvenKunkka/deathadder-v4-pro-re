/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b6a8. Types and names are inferred; NOT original source. */

int FUN_0e06b6a8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = param_1[8];
  if (iVar3 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    bVar1 = *(byte *)*param_1;
    if (0x3f < bVar1) {
      return 0;
    }
    iVar3 = FUN_0e06b470(param_1,param_2,4,0,param_4);
  }
  else {
    if (*(char *)(iVar3 + 0x10) == '\0') {
      pbVar2 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar2) {
LAB_0e06b672:
        *(undefined4 *)(iVar3 + 0xc) = 8;
        return 0;
      }
    }
    else {
      if (*(int *)(iVar3 + 0xc) != 0) {
        return 0;
      }
      pbVar2 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar2) goto LAB_0e06b672;
    }
    bVar1 = *pbVar2;
    if (0x3f < bVar1) {
      if ((*(char *)(iVar3 + 0x10) != '\0') && (*(int *)(iVar3 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar3 + 0xc) = 10;
      return 0;
    }
    iVar3 = FUN_0e06b470(param_1,param_2,4,0,param_4);
  }
  if (iVar3 != 0) {
    if (-1 < *(char *)(param_2 + 3)) {
      if (bVar1 >> 5 != 1) {
        return iVar3;
      }
      pbVar2 = (byte *)(param_2 + -1);
      do {
        pbVar2 = pbVar2 + 1;
        *pbVar2 = ~*pbVar2;
      } while (pbVar2 != (byte *)(param_2 + 3));
      return iVar3;
    }
    iVar3 = param_1[8];
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
    if ((iVar3 != 0) && ((*(char *)(iVar3 + 0x10) == '\0' || (*(int *)(iVar3 + 0xc) == 0)))) {
      *(undefined4 *)(iVar3 + 0xc) = 5;
    }
  }
  return 0;
}


