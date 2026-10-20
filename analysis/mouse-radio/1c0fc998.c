/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fc998. Types and names are inferred; NOT original source. */

uint FUN_1c0fc998(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte local_11 [5];
  
  iVar4 = *(int *)(param_1 + 0x10);
  uVar1 = *(undefined4 *)(param_1 + 4);
  if (*(char *)(iVar4 + 0x25) != '\0') {
    return 0xfffffff0;
  }
  if ((char)param_2[3] != '\x02') {
    return 0xffffff7a;
  }
  if (*param_2 == 0) {
    iVar3 = param_2[1];
    if (*(char *)(iVar4 + 0x24) == '\0') {
      if (DAT_1c0fca10 < iVar3 - 1U) goto LAB_1c0fc9f4;
      *(int *)(iVar4 + 0x20) = iVar3;
    }
    else if (*(int *)(iVar4 + 0x20) != iVar3) goto LAB_1c0fc9f4;
    iVar3 = FUN_1c0fde80(uVar1,local_11);
    if (iVar3 == DAT_1c0fca0c) {
      uVar2 = 0xfffffff4;
    }
    else {
      uVar2 = (uint)local_11[0];
      if (param_2[2] != 0) {
        *(int *)(iVar4 + uVar2 * 4) = param_2[2];
      }
      *(char *)(iVar4 + 0x24) = *(char *)(iVar4 + 0x24) + '\x01';
    }
  }
  else {
LAB_1c0fc9f4:
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


