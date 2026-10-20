/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086b88. Types and names are inferred; NOT original source. */

int FUN_0e086b88(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  
  uVar2 = *(uint *)(param_1 + 0x40) + *param_2;
  uVar3 = param_2[1] + (uint)CARRY4(*(uint *)(param_1 + 0x40),*param_2);
  *param_2 = uVar2;
  param_2[1] = uVar3;
  if (uVar2 == *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x40) * -2) {
    if (uVar3 == 0) {
      uVar3 = *(uint *)(param_1 + 0x1c);
    }
    *param_2 = uVar2;
    param_2[1] = uVar3 - 1;
    iVar1 = FUN_0e086b0c(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 0) {
      uVar3 = *(uint *)(param_1 + 0xc);
      *param_2 = *(uint *)(param_1 + 8);
      param_2[1] = uVar3;
    }
    else {
      *param_2 = local_18;
    }
  }
  return 0;
}


