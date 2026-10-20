/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0937f0. Types and names are inferred; NOT original source. */

undefined4
FUN_0e0937f0(uint param_1,uint param_2,uint *param_3,code *param_4,undefined4 *param_5,int param_6,
            int param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = param_5[8];
  if (((iVar1 == 0) || (*(char *)(iVar1 + 0x10) == '\0')) || (*(int *)(iVar1 + 0xc) == 0)) {
    if (param_2 != 0) {
      uVar4 = 0;
      do {
        uVar3 = *param_5;
        uVar2 = param_5[2];
        iVar1 = (*param_4)(param_5,param_6);
        param_6 = param_6 + param_7;
        if (iVar1 == 0) {
          *param_3 = uVar4;
          *param_5 = uVar3;
          param_5[2] = uVar2;
          if (param_1 <= uVar4) goto LAB_0e093846;
          iVar1 = param_5[8];
          if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x10) == '\0' || (*(int *)(iVar1 + 0xc) == 0)))) {
            *(undefined4 *)(iVar1 + 0xc) = 0xd;
          }
          goto LAB_0e093854;
        }
        uVar4 = uVar4 + 1;
      } while (param_2 != uVar4);
    }
    *param_3 = param_2;
LAB_0e093846:
    uVar2 = 1;
  }
  else {
LAB_0e093854:
    uVar2 = 0;
  }
  return uVar2;
}


