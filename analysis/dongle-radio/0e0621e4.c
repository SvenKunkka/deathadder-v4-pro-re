/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0621e4. Types and names are inferred; NOT original source. */

void FUN_0e0621e4(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  puVar5 = DAT_0e062284;
  puVar8 = DAT_0e062288;
  if ((param_2 != 1) && (puVar8 = DAT_0e062280, param_2 != 0x10)) {
    return;
  }
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar4 = (undefined4 *)*puVar8;
  *DAT_0e062284 = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
LAB_0e062244:
    *(uint *)(DAT_0e06228c + 0x490) = *(uint *)(DAT_0e06228c + 0x490) & ~param_2 | param_2;
    puVar4 = (undefined4 *)*puVar8;
    if (puVar4 == (undefined4 *)0x0) goto LAB_0e062228;
  }
  else {
    iVar7 = 0;
    puVar3 = puVar4;
    do {
      puVar3 = (undefined4 *)*puVar3;
      iVar7 = iVar7 + 1;
    } while (puVar3 != (undefined4 *)0x0);
    *puVar5 = 0;
    if (iVar7 == 0) goto LAB_0e062244;
  }
  if (param_1 == puVar4) {
    uVar6 = *param_1;
    *puVar8 = uVar6;
    if (param_1 == (undefined4 *)puVar8[1]) {
      puVar8[1] = uVar6;
    }
  }
  else {
    do {
      puVar5 = puVar4;
      puVar4 = (undefined4 *)*puVar5;
      if (puVar4 == (undefined4 *)0x0) goto LAB_0e062228;
    } while (param_1 != puVar4);
    *puVar5 = *param_1;
    if (param_1 == (undefined4 *)puVar8[1]) {
      puVar8[1] = puVar5;
    }
  }
LAB_0e062228:
  *param_1 = 0;
  if ((undefined4 *)puVar8[1] == (undefined4 *)0x0) {
    *puVar8 = param_1;
    puVar8[1] = param_1;
  }
  else {
    *(undefined4 *)puVar8[1] = param_1;
    puVar8[1] = param_1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


