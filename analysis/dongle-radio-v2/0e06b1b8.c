/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b1b8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e06b1b8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if (_NMI <= _Reset) {
      if ((MemManage != '\0') && (_HardFault != 0)) {
        return 0;
      }
      goto LAB_0e06b236;
    }
  }
  else {
    if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
      return 0;
    }
    if (*(uint *)(iVar2 + 8) <= *(uint *)(iVar2 + 4)) {
LAB_0e06b236:
      *(undefined4 *)(iVar2 + 0xc) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 4) = 0;
  *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
  puVar3 = (undefined4 *)(*(int *)param_1[8] + (((int *)param_1[8])[1] + -1) * 0x24);
  puVar4 = param_1;
  do {
    uVar6 = *puVar4;
    uVar5 = puVar4[1];
    uVar7 = puVar4[2];
    uVar1 = puVar4[3];
    puVar4 = puVar4 + 4;
    *puVar3 = uVar6;
    puVar3[1] = uVar5;
    puVar3[2] = uVar7;
    puVar3[3] = uVar1;
    puVar3 = puVar3 + 4;
  } while (puVar4 != param_1 + 8);
  *puVar3 = *puVar4;
  param_1[2] = param_2;
  return 1;
}


