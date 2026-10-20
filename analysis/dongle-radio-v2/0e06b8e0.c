/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b8e0. Types and names are inferred; NOT original source. */

int FUN_0e06b8e0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  char local_15;
  undefined4 local_14 [2];
  
  local_15 = '\0';
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 4) {
      return 0;
    }
  }
  else {
    if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
      return 0;
    }
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      *(undefined4 *)(iVar2 + 0xc) = 8;
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 4) {
      if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar2 + 0xc) = 10;
      return 0;
    }
  }
  iVar2 = FUN_0e06b50c(param_1,local_14,4,&local_15);
  cVar1 = local_15;
  if (iVar2 != 0) {
    if (local_15 == '\0') {
      iVar2 = FUN_0e06b1b8(param_1,local_14[0]);
    }
    else {
      iVar2 = FUN_0e06b1b8(param_1,0xfffffff0);
    }
    if (iVar2 != 0) {
      *(char *)(param_1 + 5) = cVar1;
      return iVar2;
    }
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
  }
  return 0;
}


