/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e3184. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e3184(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char local_39;
  undefined4 local_38 [7];
  uint local_1c;
  
  puVar6 = (undefined4 *)0x0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar5 = puVar6;
  if ((((param_3 & 0xff000000) == 0xff000000) && ((param_3 & 0xc) != 8)) &&
     (puVar5 = param_2, -1 < (int)(param_3 << 0x1c))) {
    puVar6 = (undefined4 *)0x1;
    puVar5 = param_1;
  }
  local_39 = '\0';
  switch(_DAT_e000ed04 & 0x1ff) {
  case 3:
    if (((-1 < _DAT_e000ed2c << 0x1e) && (-1 < _DAT_e000ed2c)) && (_DAT_e000ed2c << 1 < 0)) {
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      _DAT_e000ed14 = _DAT_e000ed14 & 0xfffffeff;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      if (*(short *)(puVar5[6] + -2) == -0x20fe) {
        uVar4 = *puVar5;
        break;
      }
      if ((_DAT_e000ed28 & 0xff) != 0) {
        uVar4 = 1;
        goto LAB_0e0e325c;
      }
      if ((_DAT_e000ed28 & 0xff00) != 0) {
        uVar4 = 1;
        goto LAB_0e0e3276;
      }
      if (0xffff < _DAT_e000ed28) goto switchD_0e0e31c2_caseD_6;
    }
  default:
    uVar4 = 0;
    break;
  case 4:
    uVar4 = 0;
LAB_0e0e325c:
    uVar4 = FUN_0e0e310c(uVar4,&local_39);
    break;
  case 5:
    uVar4 = 0;
LAB_0e0e3276:
    uVar4 = FUN_0e0e30a0(uVar4,&local_39);
    break;
  case 6:
switchD_0e0e31c2_caseD_6:
    uVar4 = FUN_0e0e3044();
  }
  if (local_39 == '\0') {
    puVar7 = local_38;
    puVar8 = puVar5 + 8;
    do {
      uVar2 = *puVar5;
      uVar3 = puVar5[1];
      puVar5 = puVar5 + 2;
      *puVar7 = uVar2;
      puVar7[1] = uVar3;
      puVar7 = puVar7 + 2;
    } while (puVar5 != puVar8);
    if (puVar6 == (undefined4 *)0x0) {
      local_1c = local_1c & 0xfffffe00;
    }
    else if ((local_1c & 0x1ff) == 0) {
      local_1c = ~(~(local_1c >> 9) << 9);
    }
    FUN_0e0e6cba(uVar4,local_38);
  }
  return;
}


