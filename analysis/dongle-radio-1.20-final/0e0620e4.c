/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0620e4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0620e4(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  if (param_2 == 1) {
    puVar7 = &DAT_23006968;
  }
  else {
    if (param_2 != 0x10) {
      return;
    }
    puVar7 = &DAT_23006960;
  }
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar4 = (undefined4 *)*puVar7;
  DAT_2300695c = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
LAB_0e062144:
    _DAT_5301e490 = _DAT_5301e490 & ~param_2 | param_2;
    puVar4 = (undefined4 *)*puVar7;
    if (puVar4 == (undefined4 *)0x0) goto LAB_0e062128;
  }
  else {
    iVar6 = 0;
    puVar3 = puVar4;
    do {
      puVar3 = (undefined4 *)*puVar3;
      iVar6 = iVar6 + 1;
    } while (puVar3 != (undefined4 *)0x0);
    DAT_2300695c = (undefined4 *)0x0;
    if (iVar6 == 0) goto LAB_0e062144;
  }
  if (param_1 == puVar4) {
    uVar5 = *param_1;
    *puVar7 = uVar5;
    if (param_1 == (undefined4 *)puVar7[1]) {
      puVar7[1] = uVar5;
    }
  }
  else {
    do {
      puVar3 = puVar4;
      puVar4 = (undefined4 *)*puVar3;
      if (puVar4 == (undefined4 *)0x0) goto LAB_0e062128;
    } while (param_1 != puVar4);
    *puVar3 = *param_1;
    if (param_1 == (undefined4 *)puVar7[1]) {
      puVar7[1] = puVar3;
    }
  }
LAB_0e062128:
  *param_1 = 0;
  if ((undefined4 *)puVar7[1] == (undefined4 *)0x0) {
    *puVar7 = param_1;
    puVar7[1] = param_1;
  }
  else {
    *(undefined4 *)puVar7[1] = param_1;
    puVar7[1] = param_1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


