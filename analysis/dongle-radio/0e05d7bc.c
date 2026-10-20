/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d7bc. Types and names are inferred; NOT original source. */

void FUN_0e05d7bc(int param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  puVar3 = &local_28;
  if (param_5 == (uint *)0x0) {
    local_24 = param_3 + -1 + param_2;
    local_28 = param_2 >> 5;
    local_1c = local_24 & 0x1f;
    local_1c = 1 << local_1c;
    local_24 = local_24 >> 5;
    local_20 = param_2 & 0x1f;
    local_18 = -(1 << (param_2 & 0x1f));
    local_14 = local_1c - 1 | local_1c;
    uVar2 = local_28;
    if (local_28 == local_24) {
      local_18 = local_18 & local_14;
      goto LAB_0e05d84e;
    }
  }
  else {
    local_28 = param_5[1];
    local_18 = param_5[4];
    puVar3 = param_5;
    uVar2 = *param_5;
    if (*param_5 == local_28) {
LAB_0e05d84e:
      iVar1 = *(int *)(param_1 + 8);
      uVar2 = *(uint *)(iVar1 + local_28 * 4);
      if (param_4 == 0) {
        *(uint *)(iVar1 + local_28 * 4) = uVar2 & ~local_18;
        return;
      }
      *(uint *)(iVar1 + local_28 * 4) = local_18 | uVar2;
      return;
    }
  }
  iVar1 = *(int *)(param_1 + 8);
  uVar4 = *(uint *)(iVar1 + uVar2 * 4);
  if (param_4 == 0) {
    *(uint *)(iVar1 + uVar2 * 4) = uVar4 & ~local_18;
    *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) =
         *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) & ~puVar3[5];
    uVar2 = *puVar3 + 1;
    if (uVar2 < puVar3[1]) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 8) + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1;
      } while (uVar2 < puVar3[1]);
      return;
    }
  }
  else {
    *(uint *)(iVar1 + uVar2 * 4) = local_18 | uVar4;
    *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) =
         *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) | puVar3[5];
    uVar2 = *puVar3 + 1;
    if (uVar2 < puVar3[1]) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 8) + uVar2 * 4) = 0xffffffff;
        uVar2 = uVar2 + 1;
      } while (uVar2 < puVar3[1]);
    }
  }
  return;
}


