/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09387c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e09387c(int *param_1,char param_2,byte *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = (byte *)*param_1;
  pbVar4 = (byte *)param_1[3];
  iVar2 = param_1[8];
  if (pbVar3 + param_4 + 1 <= pbVar4) {
    bVar1 = *param_3;
    if (param_4 != 0) {
      if (param_4 - 2U < 7) {
        bVar1 = "ipc_to_sysctrl"[param_4 + 0xe] + 0x18;
      }
      else {
        bVar1 = 0x18;
      }
    }
    if (iVar2 == 0) {
      if (pbVar4 <= pbVar3) {
        return 0;
      }
    }
    else {
      if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
        return 0;
      }
      if (pbVar4 <= pbVar3) goto LAB_0e093914;
    }
    *pbVar3 = bVar1 & 0x1f | param_2 << 5;
    iVar2 = *param_1;
    if (param_4 == 0) {
      *param_1 = iVar2 + 1;
    }
    else {
      param_4 = param_4 + -1;
      *param_1 = iVar2 + 2;
      pbVar3 = param_3 + param_4;
      *(byte *)(iVar2 + 1) = param_3[param_4];
      if (param_4 != 0) {
        do {
          pbVar4 = (byte *)*param_1;
          *param_1 = (int)(pbVar4 + 1);
          pbVar3 = pbVar3 + -1;
          *pbVar4 = *pbVar3;
        } while (pbVar3 != param_3);
      }
    }
    param_1[2] = param_1[2] + 1;
    return 1;
  }
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
    return 0;
  }
LAB_0e093914:
  *(undefined4 *)(iVar2 + 0xc) = 8;
  return 0;
}


