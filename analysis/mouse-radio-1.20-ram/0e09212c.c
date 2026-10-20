/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09212c. Types and names are inferred; NOT original source. */

int FUN_0e09212c(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == param_2) {
    if (param_3 == 0xff) {
      return 0xbad0004;
    }
    iVar3 = FUN_0e0975d8(*(undefined4 *)(param_1 + 4),param_3);
    if (iVar3 != 0xbad0000) {
      return iVar3;
    }
    FUN_0e092a38(param_1);
  }
  else {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_3 == 0xff) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0xbad0004;
    }
    iVar3 = FUN_0e0975d8(*(undefined4 *)(param_1 + 4),param_3);
    if ((iVar3 != 0xbad0000) ||
       (iVar3 = FUN_0e0975d8(*(undefined4 *)(param_2 + 4),param_3), iVar3 != 0xbad0000)) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return iVar3;
    }
    iVar3 = FUN_0e091f9c(param_1,param_2);
    if (iVar3 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      iVar3 = FUN_0e092a40();
      iVar3 = FUN_0e0975d8(*(undefined4 *)(iVar3 + 4),param_3);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      if (iVar3 != 0xbad0000) {
        return iVar3;
      }
    }
    iVar3 = FUN_0e092a38(param_1);
    if (iVar3 == 3) {
      *(undefined4 *)(*(int *)(param_1 + 0x10) + (param_3 & 0x3f) * 4 + 0x80) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x10) + param_3 * 4 + 0x180) = 0;
    }
  }
  return 0xbad0000;
}


