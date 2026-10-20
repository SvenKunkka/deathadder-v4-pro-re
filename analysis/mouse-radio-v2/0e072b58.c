/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072b58. Types and names are inferred; NOT original source. */

uint FUN_0e072b58(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 4);
  if (*(char *)(iVar3 + 0x18) == '\x01') {
    uVar2 = thunk_FUN_0e08add4();
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(undefined4 *)(*(int *)(iVar3 + 4) + 0x48) = param_2;
    *(undefined4 *)(iVar4 + 4) = param_2;
    iVar3 = *(int *)(param_1 + 4);
    cVar1 = *(char *)(iVar3 + 0x18);
  }
  else {
    *(undefined4 *)(iVar4 + 4) = param_2;
    iVar3 = *(int *)(param_1 + 4);
    cVar1 = *(char *)(iVar3 + 0x18);
  }
  if (cVar1 != '\x01') {
    return 0;
  }
  *(undefined4 *)(*(int *)(iVar3 + 4) + 0x44) = param_2;
  uVar2 = thunk_FUN_0e08ae84();
  return uVar2 & (int)uVar2 >> 0x1f;
}


