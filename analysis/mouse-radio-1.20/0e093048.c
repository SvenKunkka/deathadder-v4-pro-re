/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e093048. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e093048(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  piVar9 = (int *)param_1[8];
  if (piVar9 == (int *)0x0) {
    uVar8 = *param_1;
    uVar7 = param_1[2];
    local_30 = param_1[5];
    uStack_2c = param_1[6];
    uStack_28 = param_1[7];
    iVar5 = _Reset;
    if (_Reset != 0) goto LAB_0e093092;
    if ((MemManage != '\0') && (_HardFault != 0)) {
      return 0;
    }
  }
  else {
    if (((char)piVar9[4] != '\0') && (piVar9[3] != 0)) {
      return 0;
    }
    local_30 = param_1[5];
    uStack_2c = param_1[6];
    uStack_28 = param_1[7];
    uVar8 = *param_1;
    uVar7 = param_1[2];
    iVar5 = piVar9[1];
    if (piVar9[1] != 0) {
LAB_0e093092:
      if ((param_2 & 1) != 0) {
        puVar4 = (undefined4 *)(*piVar9 + (iVar5 + -1) * 0x24);
        if (((param_2 & 4) == 0) && (*(char *)(puVar4 + 4) != '\0')) {
          if (((char)piVar9[4] != '\0') && (piVar9[3] != 0)) {
            return 0;
          }
          piVar9[3] = 0xf;
          return 0;
        }
        puVar11 = puVar4 + 8;
        puVar3 = param_1;
        do {
          uVar10 = *puVar4;
          uVar6 = puVar4[1];
          uVar1 = puVar4[2];
          uVar2 = puVar4[3];
          puVar4 = puVar4 + 4;
          *puVar3 = uVar10;
          puVar3[1] = uVar6;
          puVar3[2] = uVar1;
          puVar3[3] = uVar2;
          puVar3 = puVar3 + 4;
        } while (puVar4 != puVar11);
        *puVar3 = *puVar4;
      }
      if ((param_2 & 2) != 0) {
        *(int *)(param_1[8] + 4) = *(int *)(param_1[8] + 4) + -1;
      }
      if (param_3 < uVar7) {
        iVar5 = param_1[8];
        if (iVar5 == 0) {
          return 0;
        }
        if ((*(char *)(iVar5 + 0x10) != '\0') && (*(int *)(iVar5 + 0xc) != 0)) {
          return 0;
        }
        *(undefined4 *)(iVar5 + 0xc) = 4;
        return 0;
      }
      if ((param_2 & 4) != 0) {
        *param_1 = uVar8;
      }
      if ((param_2 & 8) != 0) {
        param_1[5] = local_30;
        param_1[6] = uStack_2c;
        param_1[7] = uStack_28;
      }
      return 1;
    }
  }
  piVar9[3] = 2;
  return 0;
}


