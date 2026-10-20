/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e072b9c. Types and names are inferred; NOT original source. */

uint FUN_0e072b9c(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar2 + 4);
  if (*(char *)(iVar2 + 0x18) == '\x01') {
    uVar1 = thunk_FUN_0e08ac48();
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    *(uint *)(*(int *)(iVar2 + 4) + 0x48) = param_2;
  }
  *(uint *)(iVar3 + 4) = param_3 & param_2;
  *(uint *)(iVar3 + 8) = param_2 & ~(param_3 & param_2);
  if (*(char *)(*(int *)(param_1 + 4) + 0x18) != '\x01') {
    return 0;
  }
  *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x44) = param_2;
  uVar1 = thunk_FUN_0e08acf8();
  return uVar1 & (int)uVar1 >> 0x1f;
}


