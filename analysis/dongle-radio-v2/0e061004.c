/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061004. Types and names are inferred; NOT original source. */

void FUN_0e061004(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint local_14;
  
  puVar4 = (undefined4 *)0x0;
  uVar2 = *(uint *)(DAT_0e061174 + 4) & 0x1ff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar3 = puVar4;
  if (((param_3 & 0xff000000) == 0xff000000) && ((param_3 & 0xc) != 8)) {
    if ((int)(param_3 << 0x1c) < 0) {
      puVar4 = param_2;
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar4 = param_1;
      puVar3 = (undefined4 *)0x1;
    }
  }
  if (uVar2 - 3 < 4) {
                    /* WARNING: Could not recover jumptable at 0x0e061046. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0e061046::switchdataD_0e06104a + (uint)*(byte *)(uVar2 + 0xe061047) * 2))();
    return;
  }
  local_30 = *puVar4;
  uStack_2c = puVar4[1];
  uStack_28 = puVar4[2];
  uStack_24 = puVar4[3];
  local_20 = puVar4[4];
  uStack_1c = puVar4[5];
  uStack_18 = puVar4[6];
  local_14 = puVar4[7];
  if (puVar3 == (undefined4 *)0x0) {
    local_14 = local_14 & 0xfffffe00;
    FUN_0e060e10(0,&local_30);
  }
  else {
    if ((local_14 & 0x1ff) == 0) {
      local_14 = local_14 | 0x1ff;
    }
    FUN_0e060e10(0,&local_30);
  }
  return;
}


