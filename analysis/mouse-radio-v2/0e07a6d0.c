/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a6d0. Types and names are inferred; NOT original source. */

void FUN_0e07a6d0(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  
  iVar1 = DAT_0e07a790;
  *(undefined4 *)(DAT_0e07a790 + 0x704) = 1;
  *(undefined4 *)(iVar1 + 0xe44) = 0;
  *(undefined4 *)(iVar1 + 0xe48) = 0;
  *(undefined4 *)(iVar1 + 0xe3c) = 0;
  *(undefined4 *)(iVar1 + 0xe40) = 1;
  uVar2 = DAT_0e07a794;
  if (param_2 == 1) {
LAB_0e07a6fa:
    *(undefined4 *)(iVar1 + 0xe34) = 0x6a;
    *(undefined4 *)(iVar1 + 0xe2c) = uVar2;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(iVar1 + 0xe34) = 0xcc;
    *(undefined4 *)(iVar1 + 0xe2c) = 0xcccccccc;
  }
  else {
    if (param_2 != 0) goto LAB_0e07a6fa;
    *(undefined4 *)(iVar1 + 0xe34) = 0xab;
    *(undefined4 *)(iVar1 + 0xe2c) = 0xabababab;
  }
  iVar1 = DAT_0e07a790;
  if (param_3 == 0) {
    param_3 = 0xff;
  }
  param_3 = param_3 & 0xff;
  sVar3 = (short)param_3;
  if (param_1 < 7) {
    if (4 < param_1) {
      *(undefined4 *)(DAT_0e07a790 + 0xe44) = 0x103;
      uVar2 = DAT_0e07a7a4;
      sVar3 = sVar3 + 0x17;
      param_3 = param_3 | 0x2030000;
      *(undefined4 *)(iVar1 + 0xe48) = 0;
      goto LAB_0e07a726;
    }
    if (param_1 == 4) {
      sVar3 = sVar3 + 8;
      param_3 = param_3 | 0x3040000;
      uVar2 = DAT_0e07a798;
      goto LAB_0e07a726;
    }
  }
  else if (param_1 == 0xf) {
    sVar3 = 0x85;
    param_3 = 0x7f;
    uVar2 = DAT_0e07a7a0;
    goto LAB_0e07a726;
  }
  uVar2 = 8;
  sVar3 = sVar3 + 7;
  param_3 = param_3 | 0x3040000;
LAB_0e07a726:
  iVar1 = DAT_0e07a790;
  *DAT_0e07a79c = sVar3;
  *(undefined4 *)(iVar1 + 0xe20) = uVar2;
  *(uint *)(iVar1 + 0xe28) = param_3;
  return;
}


