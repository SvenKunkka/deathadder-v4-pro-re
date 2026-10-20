/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b24ea. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0b24ea(int param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint extraout_r1;
  undefined4 uVar4;
  int iVar5;
  
  FUN_0e0b26cc(param_1 + 0x18);
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((*(byte *)(param_1 + 0xd) & 0x10) != 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  if ((*(byte *)(param_1 + 0xd) & 0x10) == 0) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 8;
  }
  bVar1 = *(byte *)(param_1 + 0xd);
  if ((uVar3 & bVar1) != 0) goto LAB_0e0afcb2;
  if ((char)bVar1 < '\0') {
    *(byte *)(param_1 + 0xd) = (byte)uVar3 | bVar1 & 0x7f;
    FUN_0e0b2458();
    uVar3 = extraout_r1;
  }
  else {
    *(byte *)(param_1 + 0xd) = (byte)uVar3 | bVar1;
  }
  if (uVar3 == 8) {
    if (*(int *)(param_1 + 8) != 0) {
      FUN_0e0b2468(param_1);
    }
    FUN_0e0b26cc(param_1 + 0x18);
    iVar5 = *(int *)(param_1 + 0x58);
    while ((param_1 + 0x58 != iVar5 && (iVar5 != 0))) {
      FUN_0e0b2468(iVar5);
      FUN_0e0b26cc(iVar5 + 0x18);
      *(undefined4 *)(iVar5 + 0x88) = 0;
      FUN_0e0afc14(iVar5);
      iVar5 = *(int *)(param_1 + 0x58);
    }
    if (param_1 != _DAT_2f011ba0) goto LAB_0e0afca0;
    uVar3 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar3 = getCurrentExceptionNumber();
      uVar3 = uVar3 & 0x1ff;
    }
    if (uVar3 == 0) goto LAB_0e0afca0;
    FUN_0e0afba8(1);
    _DAT_2f011844 = 0x101;
    _DAT_2f011ba0 = 0x2f011838;
    _DAT_2f0118a8 = 0;
    _DAT_2f0118ac = 0;
    _DAT_2f0118b4 = 0;
  }
  else {
LAB_0e0afca0:
    FUN_0e0afba8(1);
  }
  DataMemoryBarrier(0x1f);
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0x9f;
LAB_0e0afcb2:
  if (_DAT_2f011ba0 == param_1) {
    uVar3 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar3 = getCurrentExceptionNumber();
      uVar3 = uVar3 & 0x1ff;
    }
    if (uVar3 == 0) {
      FUN_0e0aca34(uVar4);
      return;
    }
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


