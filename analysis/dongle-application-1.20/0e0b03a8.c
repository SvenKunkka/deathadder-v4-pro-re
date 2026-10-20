/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b03a8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0b03a8(uint param_1)

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
  _DAT_2f011bd0 = param_1;
  iVar2 = FUN_0e0b0260();
  while (iVar4 = (int)_DAT_2f011bd0 >> 0x1f, iVar2 != 0) {
    uVar6 = *(uint *)(iVar2 + 0x10);
    iVar5 = *(int *)(iVar2 + 0x14);
    if ((int)((iVar4 - iVar5) - (uint)(_DAT_2f011bd0 < uVar6)) < 0 !=
        (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)(_DAT_2f011bd0 < uVar6)))) {
      *(uint *)(iVar2 + 0x10) = uVar6 - _DAT_2f011bd0;
      *(uint *)(iVar2 + 0x14) = (iVar5 - iVar4) - (uint)(uVar6 < _DAT_2f011bd0);
      break;
    }
    bVar8 = CARRY4(uVar6,_DAT_2f0118e0);
    _DAT_2f0118e0 = uVar6 + _DAT_2f0118e0;
    _DAT_2f0118e4 = _DAT_2f0118e4 + ((int)uVar6 >> 0x1f) + (uint)bVar8;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    iVar2 = FUN_0e0b0284();
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
    _DAT_2f011bd0 = _DAT_2f011bd0 - uVar6;
    iVar2 = FUN_0e0b0260();
  }
  bVar8 = CARRY4(_DAT_2f011bd0,_DAT_2f0118e0);
  _DAT_2f0118e0 = _DAT_2f011bd0 + _DAT_2f0118e0;
  _DAT_2f0118e4 = _DAT_2f0118e4 + iVar4 + (uint)bVar8;
  _DAT_2f011bd0 = 0;
  uVar3 = FUN_0e0b269a();
  FUN_0e0adf4c(uVar3,0);
  iVar2 = _DAT_2f011ba0;
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
  iVar4 = _DAT_2f011bc4;
  if (_DAT_2f011bc4 != _DAT_2f011ba0) {
    _DAT_2f011bc4 = 0;
    if ((*(char *)(DAT_2f011ba8 + 0x2f011bda) == '\0') ||
       (iVar4 = FUN_0e0b0140(_DAT_2f011ba0), iVar4 == 0)) goto LAB_0e0b01ec;
    iVar4 = iVar2;
    if ((*(byte *)(iVar2 + 0xd) & 0x1f) == 0) {
      FUN_0e0afd58(iVar2);
    }
  }
  FUN_0e0b017c(iVar4);
LAB_0e0b01ec:
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


