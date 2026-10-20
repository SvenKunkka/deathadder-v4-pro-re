/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0debec. Types and names are inferred; NOT original source. */

uint FUN_1c0debec(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  puVar3 = *(uint **)(iVar4 + 4);
  uVar2 = *puVar3;
  if (*(char *)(iVar4 + 0x18) == '\x01') {
    uVar1 = thunk_EXT_FUN_0e08add4();
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    *(uint *)(*(int *)(iVar4 + 4) + 0x48) = param_2;
  }
  puVar3[1] = param_2 & ~uVar2;
  puVar3[2] = uVar2 & param_2;
  if (*(char *)(*(int *)(param_1 + 4) + 0x18) != '\x01') {
    return 0;
  }
  *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x44) = param_2;
  uVar2 = thunk_EXT_FUN_0e08ae84();
  return uVar2 & (int)uVar2 >> 0x1f;
}


