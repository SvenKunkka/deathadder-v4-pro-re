/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e6f74. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0e6f74(undefined4 *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  
  if (*(char *)((int)param_1 + 0xe) == param_2) {
    return 0;
  }
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (((*(byte *)((int)param_1 + 0xd) & 0x1f) == 0) && (param_1[6] == 0)) {
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x7f;
    uVar9 = FUN_0e0e7140();
    iVar5 = (int)((ulonglong)uVar9 >> 0x20);
    iVar3 = (int)uVar9;
    *(byte *)(iVar3 + 0xd) = *(byte *)(iVar3 + 0xd) | 0x80;
    *(char *)(iVar3 + 0xe) = (char)((ulonglong)uVar9 >> 0x20);
    puVar7 = (undefined4 *)0x0;
    if (_DAT_2f0118f0 != (undefined4 *)&DAT_2f0118f0) {
      puVar7 = _DAT_2f0118f0;
    }
    for (; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
      if ((iVar5 != *(char *)((int)puVar7 + 0xe)) && (iVar5 < *(char *)((int)puVar7 + 0xe))) {
        puVar6 = (undefined4 *)puVar7[1];
        *param_1 = puVar7;
        param_1[1] = puVar6;
        *puVar6 = param_1;
        puVar7[1] = param_1;
        goto LAB_0e0e5baa;
      }
      if (_DAT_2f0118f4 == puVar7) break;
    }
    *param_1 = &DAT_2f0118f0;
    param_1[1] = _DAT_2f0118f4;
    *_DAT_2f0118f4 = param_1;
    _DAT_2f0118f4 = param_1;
LAB_0e0e5baa:
    FUN_0e0e58bc(1);
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
    *(char *)((int)param_1 + 0xe) = (char)param_2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar4;
}


