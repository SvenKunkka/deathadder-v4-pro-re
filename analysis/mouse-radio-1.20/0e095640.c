/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095640. Types and names are inferred; NOT original source. */

uint FUN_0e095640(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = param_1[3];
  uVar7 = uVar3 & 0xfffffff7;
  param_1[3] = uVar7;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_0e096594(param_1 + 4);
    uVar7 = param_1[3];
    uVar3 = uVar7;
  }
  if (-1 < (int)(uVar3 << 0x1e)) {
    iVar4 = uVar7 << 0x1d;
    uVar7 = uVar7 & 0xfffffffb;
    iVar2 = param_1[2];
    param_1[3] = uVar7;
    if ((iVar4 < 0) && (puVar5 = *(undefined4 **)(iVar2 + 0x90), puVar5 != (undefined4 *)0x0)) {
      if (param_1 == puVar5) {
        uVar8 = *param_1;
        *(undefined4 *)(iVar2 + 0x90) = uVar8;
        if (param_1 == *(undefined4 **)(iVar2 + 0x94)) {
          *(undefined4 *)(iVar2 + 0x94) = uVar8;
        }
      }
      else {
        do {
          puVar6 = puVar5;
          puVar5 = (undefined4 *)*puVar6;
          if (puVar5 == (undefined4 *)0x0) goto LAB_0e095662;
        } while (param_1 != puVar5);
        *puVar6 = *param_1;
        if (param_1 == *(undefined4 **)(iVar2 + 0x94)) {
          *(undefined4 **)(iVar2 + 0x94) = puVar6;
        }
      }
      uVar7 = param_1[3];
      *param_1 = 0;
    }
  }
LAB_0e095662:
  uVar3 = 0;
  if ((uVar7 & 0x1f) != 0) {
    param_1[3] = uVar7 | 2;
    uVar3 = uVar7 & 0x1f | 2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


