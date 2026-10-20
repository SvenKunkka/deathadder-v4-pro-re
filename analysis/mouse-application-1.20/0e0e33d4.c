/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e33d4. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e0e599a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0e33d4(int param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int extraout_r1;
  undefined4 uVar5;
  uint uVar6;
  
  if (_DAT_2f0118dc == param_1) {
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = getCurrentExceptionNumber();
      uVar6 = uVar6 & 0x1ff;
    }
    if (uVar6 != 0) {
      _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
      _DAT_e000ed24 = _DAT_e000ed24 & 0xffff7fff;
    }
  }
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((uint)*(byte *)(param_1 + 0xc) << 0x1f) < 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0);
    }
    InstructionSynchronizationBarrier(0xf);
    software_interrupt(2);
    return 4;
  }
  if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1c) < 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return param_1;
  }
  iVar4 = 8;
  bVar1 = *(byte *)(param_1 + 0xd);
  iVar3 = param_1;
  if ((bVar1 & 8) != 0) goto LAB_0e0e59c6;
  if ((char)bVar1 < '\0') {
    *(byte *)(param_1 + 0xd) = bVar1 & 0x7f | 8;
    FUN_0e0e7140();
    iVar4 = extraout_r1;
  }
  else {
    *(byte *)(param_1 + 0xd) = bVar1 | 8;
  }
  if (iVar4 == 8) {
    if (*(int *)(param_1 + 8) != 0) {
      FUN_0e0e7150(param_1);
    }
    FUN_0e0e7380(param_1 + 0x18);
    iVar3 = *(int *)(param_1 + 0x58);
    while ((param_1 + 0x58 != iVar3 && (iVar3 != 0))) {
      FUN_0e0e7150(iVar3);
      FUN_0e0e7380(iVar3 + 0x18);
      *(undefined4 *)(iVar3 + 0x88) = 0;
      FUN_0e0e5928(iVar3);
      iVar3 = *(int *)(param_1 + 0x58);
    }
    if (param_1 != _DAT_2f0118dc) goto LAB_0e0e59b4;
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = getCurrentExceptionNumber();
      uVar6 = uVar6 & 0x1ff;
    }
    if (uVar6 == 0) goto LAB_0e0e59b4;
    iVar3 = FUN_0e0e58bc(1);
    _DAT_2f0115b4 = 0x101;
    _DAT_2f0118dc = 0x2f0115a8;
    _DAT_2f011618 = 0;
    _DAT_2f01161c = 0;
    _DAT_2f011624 = 0;
  }
  else {
LAB_0e0e59b4:
    iVar3 = FUN_0e0e58bc(1);
  }
  DataMemoryBarrier(0x1f);
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0x9f;
LAB_0e0e59c6:
  iVar4 = _DAT_2f0118dc;
  if (_DAT_2f0118dc == param_1) {
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = getCurrentExceptionNumber();
      uVar6 = uVar6 & 0x1ff;
    }
    if (uVar6 == 0) {
      *(undefined4 *)(_DAT_2f0118dc + 0x88) = 0xfffffff5;
      *(undefined4 *)(iVar4 + 0x84) = uVar5;
      _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(0);
      }
      InstructionSynchronizationBarrier(0xf);
      return *(int *)(_DAT_2f0118dc + 0x88);
    }
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3;
}


