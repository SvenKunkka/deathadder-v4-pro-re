/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f9b7c. Types and names are inferred; NOT original source. */

void FUN_1c0f9b7c(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  if ((int)((uint)*(byte *)(param_2 + 0x19) << 0x1f) < 0) {
    if (*(char *)(param_2 + 0x18) == '\0') {
      sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 6);
      if (*(int *)(iVar4 + 0xa8) != 0) {
        FUN_1c0f67fc();
      }
      *(int *)(iVar4 + 0xa8) = param_2;
      if (*(int *)(iVar4 + 0xa4) != 0) {
        *(undefined4 *)(iVar4 + 0xa4) = 0;
      }
      if (sVar1 == 0) {
        *(undefined4 *)(iVar4 + 0xa4) = 3;
        return;
      }
      *(uint *)(iVar4 + 0xa4) = (**(byte **)(param_2 + 0xc) >> 7) + 1;
      return;
    }
  }
  else if (*(char *)(param_2 + 0x18) == '\0') {
    if (*(int *)(iVar4 + 0xa4) == 1) {
      *(undefined4 *)(iVar4 + 0xa4) = 5;
      return;
    }
    if (*(int *)(iVar4 + 0xa4) != 4) {
      *(undefined4 *)(iVar4 + 0xa4) = 6;
      return;
    }
    if (*(short *)(param_2 + 0x10) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 6;
    }
    goto LAB_1c0f9ba4;
  }
  iVar2 = *(int *)(iVar4 + 0xa4);
  if (iVar2 == 5) {
    *(undefined4 *)(iVar4 + 0xa4) = 0;
    return;
  }
  if (iVar2 == 2) {
    uVar3 = (*(uint *)(iVar4 + 0x80) ^ 4) & 4;
  }
  else if (iVar2 == 3) {
    uVar3 = 0;
  }
  else {
    uVar3 = 6;
  }
LAB_1c0f9ba4:
  *(uint *)(iVar4 + 0xa4) = uVar3;
  return;
}


