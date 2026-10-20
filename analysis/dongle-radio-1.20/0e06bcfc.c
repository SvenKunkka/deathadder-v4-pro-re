/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bcfc. Types and names are inferred; NOT original source. */

undefined4
FUN_0e06bcfc(uint param_1,uint param_2,uint *param_3,undefined4 param_4,int param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_3;
  if ((param_1 <= uVar3) && (uVar3 <= param_2)) {
    uVar1 = FUN_0e06bcb8(uVar3,param_4,param_5,param_6);
    return uVar1;
  }
  iVar2 = *(int *)(param_5 + 0x20);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      *(undefined4 *)(iVar2 + 0xc) = 0xd;
    }
    else if (*(int *)(iVar2 + 0xc) == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 0xd;
    }
  }
  return 0;
}


