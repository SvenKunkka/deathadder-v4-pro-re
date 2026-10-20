/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b978. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06b978(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 5) != '\0') {
    iVar1 = param_1[8];
    if (iVar1 == 0) {
      pcVar3 = (char *)*param_1;
      if ((char *)param_1[3] <= pcVar3) {
        return 0;
      }
      if (*pcVar3 != -1) {
        return 0;
      }
    }
    else {
      if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      pcVar3 = (char *)*param_1;
      if ((char *)param_1[3] <= pcVar3) {
        *(undefined4 *)(iVar1 + 0xc) = 8;
        return 0;
      }
      if (*pcVar3 != -1) {
        if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
          return 0;
        }
        *(undefined4 *)(iVar1 + 0xc) = 10;
        return 0;
      }
    }
    uVar2 = 0xffffffff;
    *param_1 = pcVar3 + 1;
    *(undefined1 *)(param_1 + 5) = 0;
  }
  uVar2 = FUN_0e06b240(param_1,7,uVar2);
  return uVar2;
}


