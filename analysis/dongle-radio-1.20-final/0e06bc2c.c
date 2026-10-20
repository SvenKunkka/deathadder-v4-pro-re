/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc2c. Types and names are inferred; NOT original source. */

int FUN_0e06bc2c(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if ((*param_1 < param_1[3]) && (uVar2 = param_2[1], uVar2 <= param_1[3] - *param_1)) {
    puVar4 = param_2 + 1;
    uVar3 = 0;
    if (*param_2 != 0) {
      iVar1 = FUN_0e06b358(puVar4,4,uVar2,*param_2,param_4);
      uVar2 = param_1[3];
      uVar3 = *param_1 + param_2[1] + iVar1;
      if (uVar2 < uVar3) goto LAB_0e06baf6;
    }
    iVar1 = FUN_0e06b358(puVar4,4,uVar2,uVar3,param_4);
    iVar1 = FUN_0e06b9d8(param_1,2,puVar4,iVar1 + -1);
    if (iVar1 != 0) {
      uVar2 = *param_2;
      if (*param_1 != uVar2) {
        FUN_0e06f376(*param_1,uVar2,param_2[1]);
        uVar2 = *param_1;
      }
      *param_1 = uVar2 + param_2[1];
      return iVar1;
    }
  }
  else {
LAB_0e06baf6:
    uVar2 = param_1[8];
    if ((uVar2 != 0) && ((*(char *)(uVar2 + 0x10) == '\0' || (*(int *)(uVar2 + 0xc) == 0)))) {
      *(undefined4 *)(uVar2 + 0xc) = 8;
    }
  }
  return 0;
}


