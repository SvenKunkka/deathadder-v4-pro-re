/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e6930. Types and names are inferred; NOT original source. */

void FUN_1c0e6930(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  iVar1 = DAT_1c0e69d0;
  *(undefined4 *)(DAT_1c0e69d0 + 0x400) = 0;
  *(undefined4 *)(iVar1 + 0x490) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x220) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  do {
  } while (*(int *)(iVar1 + 0x220) == 0);
  *(undefined4 *)(iVar1 + 0x220) = 0;
  *(int *)(iVar1 + 0x500) = param_1;
  uVar2 = DAT_1c0e69d4;
  *(uint *)(iVar1 + 0x400) = *(uint *)(iVar1 + 0x400) | 0x21;
  *(undefined4 *)(iVar1 + 0xed0) = uVar2;
  FUN_1c0e66d0(param_1,param_3,0,iVar1,param_4);
  pcVar5 = DAT_1c0e69e0;
  puVar4 = DAT_1c0e69dc;
  puVar3 = DAT_1c0e69d8;
  iVar1 = DAT_1c0e69d0;
  if (param_1 == 0xf) {
    if (param_2 - 0xbU < 0x10) {
      param_2 = param_2 * 5 + -0x32;
    }
    else {
      param_2 = 5;
    }
  }
  *(int *)(DAT_1c0e69d0 + 0x708) = param_2;
  *puVar3 = 0;
  *puVar4 = 0;
  *(undefined4 *)(iVar1 + 0x488) = 0x800;
  if ((*pcVar5 != '\0') && (FUN_1c0e6828(1), *pcVar5 != '\0')) {
    *DAT_1c0e69e4 = 1;
    return;
  }
  *(undefined4 *)(DAT_1c0e69d0 + 4) = 1;
  return;
}


