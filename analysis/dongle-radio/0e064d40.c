/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064d40. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e064d96) */

int FUN_0e064d40(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x10);
  if ((param_2 == 0) || (param_3 == 0)) {
    iVar1 = -0x16;
  }
  else {
    (**(code **)(iVar3 + 0x3c))();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
      iVar1 = -0x78;
    }
    else {
      *(int *)(iVar2 + 0x98) = param_2;
      *(int *)(iVar2 + 0x9c) = param_3;
      iVar1 = (**(code **)(iVar3 + 0x34))(param_1);
      if (iVar1 == 0) {
        *(uint *)(iVar2 + 0xa0) = *(uint *)(iVar2 + 0xa0) | 1;
      }
    }
    (**(code **)(iVar3 + 0x40))(param_1);
  }
  return iVar1;
}


