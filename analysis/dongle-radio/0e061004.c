/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061004. Types and names are inferred; NOT original source. */

void FUN_0e061004(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char local_31;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint local_14;
  
  iVar3 = DAT_0e061174;
  puVar7 = (undefined4 *)0x0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar5 = puVar7;
  if (((param_3 & 0xff000000) == 0xff000000) && ((param_3 & 0xc) != 8)) {
    if ((int)(param_3 << 0x1c) < 0) {
      puVar7 = param_2;
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar7 = param_1;
      puVar5 = (undefined4 *)0x1;
    }
  }
  local_31 = '\0';
  switch(*(uint *)(DAT_0e061174 + 4) & 0x1ff) {
  case 3:
    if ((*(uint *)(DAT_0e061174 + 0x2c) & 2) != 0) goto switchD_0e061046_default;
    uVar6 = 0;
    if ((*(int *)(DAT_0e061174 + 0x2c) < 0) ||
       (uVar6 = 0, (*(uint *)(DAT_0e061174 + 0x2c) & 0x40000000) == 0)) goto LAB_0e061054;
    iVar4 = puVar7[6];
    *(uint *)(DAT_0e061174 + 0x14) = *(uint *)(DAT_0e061174 + 0x14) | 0x100;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    sVar1 = *(short *)(iVar4 + -2);
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffeff;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    if (sVar1 == -0x20fe) {
      uVar6 = *puVar7;
    }
    else if ((*(uint *)(iVar3 + 0x28) & 0xff) == 0) {
      if ((*(uint *)(iVar3 + 0x28) & 0xff00) == 0) {
        if (*(uint *)(iVar3 + 0x28) < 0x10000) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0e060eb0();
        }
      }
      else {
        uVar6 = FUN_0e060f14(1,&local_31);
      }
    }
    else {
      uVar6 = FUN_0e060f84(1,&local_31);
    }
    break;
  case 4:
    uVar6 = FUN_0e060f84(0,&local_31);
    break;
  case 5:
    uVar6 = FUN_0e060f14(0,&local_31);
    break;
  case 6:
    uVar6 = FUN_0e060eb0();
    goto LAB_0e061054;
  default:
switchD_0e061046_default:
    uVar6 = 0;
    goto LAB_0e061054;
  }
  if (local_31 != '\0') {
    return;
  }
LAB_0e061054:
  local_30 = *puVar7;
  uStack_2c = puVar7[1];
  uStack_28 = puVar7[2];
  uStack_24 = puVar7[3];
  local_20 = puVar7[4];
  uStack_1c = puVar7[5];
  uStack_18 = puVar7[6];
  local_14 = puVar7[7];
  if (puVar5 == (undefined4 *)0x0) {
    local_14 = local_14 & 0xfffffe00;
    FUN_0e060e10(uVar6,&local_30);
  }
  else {
    if ((local_14 & 0x1ff) == 0) {
      local_14 = local_14 | 0x1ff;
    }
    FUN_0e060e10(uVar6,&local_30);
  }
  return;
}


