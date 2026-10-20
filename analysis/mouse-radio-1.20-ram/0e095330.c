/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095330. Types and names are inferred; NOT original source. */

uint FUN_0e095330(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar5 = param_1[3];
  if ((int)(uVar5 << 0x1e) < 0) {
    uVar2 = 0;
    if ((uVar5 & 0x1f) != 0) {
      param_1[3] = uVar5 | 2;
      uVar2 = uVar5 & 0x1f | 2;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar2;
  }
  uVar2 = uVar5 & 0xfffffffb;
  iVar7 = param_1[2];
  param_1[3] = uVar2;
  if (((int)(uVar5 << 0x1d) < 0) &&
     (puVar3 = *(undefined4 **)(iVar7 + 0x90), puVar3 != (undefined4 *)0x0)) {
    if (param_1 == puVar3) {
      uVar6 = *param_1;
      *(undefined4 *)(iVar7 + 0x90) = uVar6;
      if (param_1 == *(undefined4 **)(iVar7 + 0x94)) {
        *(undefined4 *)(iVar7 + 0x94) = uVar6;
      }
    }
    else {
      do {
        puVar4 = puVar3;
        puVar3 = (undefined4 *)*puVar4;
        if (puVar3 == (undefined4 *)0x0) goto LAB_0e095370;
      } while (param_1 != puVar3);
      *puVar4 = *param_1;
      if (param_1 == *(undefined4 **)(iVar7 + 0x94)) {
        *(undefined4 **)(iVar7 + 0x94) = puVar4;
      }
    }
    uVar2 = param_1[3];
    *param_1 = 0;
  }
LAB_0e095370:
  uVar5 = 0;
  if ((uVar2 & 0x1f) != 0) {
    param_1[3] = uVar2 | 2;
    uVar5 = uVar2 & 0x1f | 2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar5;
}


