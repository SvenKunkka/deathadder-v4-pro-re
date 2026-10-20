/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e090bec. Types and names are inferred; NOT original source. */

int FUN_0e090bec(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  cVar1 = *(char *)(iVar3 + 0x48);
  if (cVar1 == '\x01') {
    iVar2 = FUN_0e096c4c(iVar3 + 0x28,1,0,*(undefined4 *)(iVar3 + 0x3c),
                         *(undefined4 *)(iVar3 + 0x38),*(undefined4 *)(iVar3 + 0x3c));
    if (iVar2 == 0) {
      return -0x20;
    }
    *(undefined1 *)(iVar3 + 0x48) = 2;
  }
  else {
    if (cVar1 == '\x03') {
      return -0x20;
    }
    if (cVar1 == '\0') {
      return -0xe;
    }
  }
  iVar3 = FUN_0e087604(iVar3 + 0x20,param_2,param_3);
  FUN_0e096c54(param_2);
  if (iVar3 != -0x16) {
    if (iVar3 < -0x15) {
      if (iVar3 == -0x78) {
        return -0x72;
      }
      if (iVar3 == -0x4d) {
        return -0x4d;
      }
    }
    else if (iVar3 == -5) {
      return -5;
    }
    if (iVar3 < 0) {
      iVar3 = -5;
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}


