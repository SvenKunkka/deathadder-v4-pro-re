/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c100f04. Types and names are inferred; NOT original source. */

undefined4 FUN_1c100f04(uint *param_1,uint *param_2,uint *param_3,int param_4,char param_5)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 uVar8;
  
  puVar7 = param_1 + 2;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_5 == '\0') {
    iVar2 = FUN_1c101ec8(puVar7);
  }
  else {
    param_2 = (uint *)param_1[1];
    iVar2 = FUN_1c101ec8(puVar7);
  }
  if (iVar2 != 0) {
    *(uint **)(iVar2 + 0x14) = param_3;
    *(undefined4 *)(iVar2 + 0x8c) = 0;
    FUN_1c101cfc();
    FUN_1c101fd0(puVar7,uVar8);
    return 0;
  }
  if (param_4 == 0) {
    *param_3 = 0;
    uVar6 = 0;
    uVar5 = 0;
    puVar3 = param_3;
    if (param_2 != (uint *)0x0) goto LAB_1c100f3a;
LAB_1c100f96:
    *puVar3 = *param_1 | uVar6;
    *param_1 = (uint)puVar3;
    if (param_1[1] != 0) goto LAB_1c100f52;
  }
  else {
    puVar3 = (uint *)FUN_1c102dcc(0,8);
    if (puVar3 == (uint *)0x0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar8);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0xfffffff4;
    }
    uVar6 = 1;
    puVar3[1] = (uint)param_3;
    *puVar3 = 1;
    uVar5 = uVar6;
    if (param_2 == (uint *)0x0) goto LAB_1c100f96;
LAB_1c100f3a:
    if (3 < *param_2) {
      *puVar3 = *param_2 & 0xfffffffc | uVar5;
      *param_2 = (uint)puVar3 | *param_2 & 3;
      goto LAB_1c100f52;
    }
    *puVar3 = uVar5;
    puVar4 = (uint *)param_1[1];
    if (puVar4 == (uint *)0x0) {
      *param_1 = (uint)puVar3;
      param_1[1] = (uint)puVar3;
      goto LAB_1c100f52;
    }
    *puVar4 = *puVar4 & 3 | (uint)puVar3;
  }
  param_1[1] = (uint)puVar3;
LAB_1c100f52:
  FUN_1c101fd0(puVar7,uVar8);
  return 0;
}


