/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5ff4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e5ff4(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  uVar7 = 0;
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    uVar7 = getBasePriority();
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if ((bVar8) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  _DAT_2f01190c = param_1;
  iVar2 = FUN_0e0e5eac();
  while (iVar4 = (int)_DAT_2f01190c >> 0x1f, iVar2 != 0) {
    uVar6 = *(uint *)(iVar2 + 0x10);
    iVar5 = *(int *)(iVar2 + 0x14);
    if ((int)((iVar4 - iVar5) - (uint)(_DAT_2f01190c < uVar6)) < 0 !=
        (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)(_DAT_2f01190c < uVar6)))) {
      *(uint *)(iVar2 + 0x10) = uVar6 - _DAT_2f01190c;
      *(uint *)(iVar2 + 0x14) = (iVar5 - iVar4) - (uint)(uVar6 < _DAT_2f01190c);
      break;
    }
    bVar8 = CARRY4(uVar6,_DAT_2f011650);
    _DAT_2f011650 = uVar6 + _DAT_2f011650;
    _DAT_2f011654 = _DAT_2f011654 + ((int)uVar6 >> 0x1f) + (uint)bVar8;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    iVar2 = FUN_0e0e5ed0();
    bVar8 = (bool)isCurrentModePrivileged();
    if (bVar8) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    (**(code **)(iVar2 + 8))();
    uVar7 = 0;
    bVar8 = (bool)isCurrentModePrivileged();
    if (bVar8) {
      uVar7 = getBasePriority();
    }
    bVar8 = (bool)isCurrentModePrivileged();
    if ((bVar8) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    _DAT_2f01190c = _DAT_2f01190c - uVar6;
    iVar2 = FUN_0e0e5eac();
  }
  bVar8 = CARRY4(_DAT_2f01190c,_DAT_2f011650);
  _DAT_2f011650 = _DAT_2f01190c + _DAT_2f011650;
  _DAT_2f011654 = _DAT_2f011654 + iVar4 + (uint)bVar8;
  _DAT_2f01190c = 0;
  uVar3 = FUN_0e0e734e();
  FUN_0e0e44bc(uVar3,0);
  iVar2 = _DAT_2f0118dc;
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar7 = 0;
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    uVar7 = getBasePriority();
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if ((bVar8) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar4 = _DAT_2f011900;
  if (_DAT_2f011900 != _DAT_2f0118dc) {
    _DAT_2f011900 = 0;
    if ((*(char *)(DAT_2f0118e4 + 0x2f011915) == '\0') ||
       (iVar4 = FUN_0e0e5d8c(_DAT_2f0118dc), iVar4 == 0)) goto LAB_0e0e5e38;
    iVar4 = iVar2;
    if ((*(byte *)(iVar2 + 0xd) & 0x1f) == 0) {
      FUN_0e0e5a6c(iVar2);
    }
  }
  FUN_0e0e5dc8(iVar4);
LAB_0e0e5e38:
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


