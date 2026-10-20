/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0ff67c. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0ff67c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if (((byte *)*param_1 < (byte *)param_1[3]) && (*(byte *)*param_1 >> 5 == 0)) {
      uVar1 = FUN_1c0ff43c(param_1,param_2,4,0);
      return uVar1;
    }
    return 0;
  }
  if ((*(char *)(iVar2 + 0x10) == '\0') || (*(int *)(iVar2 + 0xc) == 0)) {
    if ((byte *)*param_1 < (byte *)param_1[3]) {
      if (*(byte *)*param_1 >> 5 == 0) {
        uVar1 = FUN_1c0ff43c(param_1,param_2,4,0);
        return uVar1;
      }
      if ((*(char *)(iVar2 + 0x10) == '\0') || (*(int *)(iVar2 + 0xc) == 0)) {
        *(undefined4 *)(iVar2 + 0xc) = 10;
        return 0;
      }
    }
    else {
      *(undefined4 *)(iVar2 + 0xc) = 8;
    }
  }
  return 0;
}


