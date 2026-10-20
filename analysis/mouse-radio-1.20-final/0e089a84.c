/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089a84. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e089a84(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char local_31;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint local_14;
  
  puVar4 = (undefined4 *)0x0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar2 = puVar4;
  if (((param_3 & 0xff000000) == 0xff000000) && ((param_3 & 0xc) != 8)) {
    if ((int)(param_3 << 0x1c) < 0) {
      puVar4 = param_2;
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar4 = param_1;
      puVar2 = (undefined4 *)0x1;
    }
  }
  local_31 = '\0';
  switch(_DAT_e000ed04 & 0x1ff) {
  case 3:
    if ((_DAT_e000ed2c & 2) != 0) goto switchD_0e089ac6_default;
    uVar3 = 0;
    if (((int)_DAT_e000ed2c < 0) || (uVar3 = 0, (_DAT_e000ed2c & 0x40000000) == 0))
    goto LAB_0e089ad4;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    _DAT_e000ed14 = _DAT_e000ed14 & 0xfffffeff;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    if (*(short *)(puVar4[6] + -2) == -0x20fe) {
      uVar3 = *puVar4;
    }
    else if ((_DAT_e000ed28 & 0xff) == 0) {
      if ((_DAT_e000ed28 & 0xff00) == 0) {
        if (_DAT_e000ed28 < 0x10000) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_0e089930();
        }
      }
      else {
        uVar3 = FUN_0e089994(1,&local_31);
      }
    }
    else {
      uVar3 = FUN_0e089a04(1,&local_31);
    }
    break;
  case 4:
    uVar3 = FUN_0e089a04(0,&local_31);
    break;
  case 5:
    uVar3 = FUN_0e089994(0,&local_31);
    break;
  case 6:
    uVar3 = FUN_0e089930();
    goto LAB_0e089ad4;
  default:
switchD_0e089ac6_default:
    uVar3 = 0;
    goto LAB_0e089ad4;
  }
  if (local_31 != '\0') {
    return;
  }
LAB_0e089ad4:
  local_30 = *puVar4;
  uStack_2c = puVar4[1];
  uStack_28 = puVar4[2];
  uStack_24 = puVar4[3];
  local_20 = puVar4[4];
  uStack_1c = puVar4[5];
  uStack_18 = puVar4[6];
  local_14 = puVar4[7];
  if (puVar2 == (undefined4 *)0x0) {
    local_14 = local_14 & 0xfffffe00;
    FUN_0e089890(uVar3,&local_30);
  }
  else {
    if ((local_14 & 0x1ff) == 0) {
      local_14 = local_14 | 0x1ff;
    }
    FUN_0e089890(uVar3,&local_30);
  }
  return;
}


