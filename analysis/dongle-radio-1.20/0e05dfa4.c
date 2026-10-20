/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05dfa4. Types and names are inferred; NOT original source. */

int FUN_0e05dfa4(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0e05df2c(param_1,param_2,*(undefined4 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x14),param_2,param_3);
  if (-1 < iVar1) {
    uVar2 = **(uint **)(param_1 + 0x3c);
    if (1 < uVar2) {
      param_3 = (param_3 - 1) + uVar2 & -uVar2;
    }
    iVar1 = 0;
    uVar2 = *(uint *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x10) = uVar2 + param_3;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uint)CARRY4(uVar2,param_3);
  }
  return iVar1;
}


