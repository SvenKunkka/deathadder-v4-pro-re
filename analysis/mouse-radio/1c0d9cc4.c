/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0d9cc4. Types and names are inferred; NOT original source. */

void FUN_1c0d9cc4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_1c0d9d3c;
  param_1 = param_1 * 0xee0;
  *(undefined4 *)(DAT_1c0d9d3c + param_1 + 0x164) = 0;
  *(undefined2 *)(param_1 + 0x164 + iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + param_1 + 0x15e) = 0;
  *(undefined2 *)(param_1 + 0x15e + iVar1 + 4) = 0;
  iVar2 = param_1 + 0x168 + iVar1;
  *(undefined4 *)(iVar2 + 6) = DAT_1c0d9d40;
  iVar3 = iVar1 + param_1;
  *(undefined4 *)(iVar2 + 2) = DAT_1c0d9d44;
  *(undefined4 *)(iVar2 + 10) = 0x10101010;
  *(int *)(iVar3 + 0x178) = param_1 + 400 + iVar1;
  *(int *)(iVar3 + 0x17c) = param_1 + 0x390 + iVar1;
  *(int *)(iVar3 + 0x180) = param_1 + 0x3e0 + iVar1;
  *(int *)(iVar3 + 0x184) = param_1 + 0x4e0 + iVar1;
  *(int *)(iVar3 + 0x188) = param_1 + 0x6e0 + iVar1;
  *(int *)(iVar3 + 0x18c) = param_1 + 0x8e0 + iVar1;
  return;
}


