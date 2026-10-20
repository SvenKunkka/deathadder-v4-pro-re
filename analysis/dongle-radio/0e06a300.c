/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a300. Types and names are inferred; NOT original source. */

int FUN_0e06a300(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = DAT_0e06a3c4;
  if (param_1 == param_2) {
    if ((param_3 != 0xff) &&
       (iVar3 = FUN_0e068b38(*(undefined4 *)(param_1 + 4),param_3), iVar3 == DAT_0e06a3c0)) {
      FUN_0e06ac0c(param_1);
      iVar3 = DAT_0e06a3c0;
    }
  }
  else {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_3 == 0xff) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar5);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      iVar3 = FUN_0e068b38(*(undefined4 *)(param_1 + 4),param_3);
      iVar4 = DAT_0e06a3c0;
      if ((iVar3 == DAT_0e06a3c0) &&
         (iVar3 = FUN_0e068b38(*(undefined4 *)(param_2 + 4),param_3), iVar3 == iVar4)) {
        iVar3 = FUN_0e06a170(param_1,param_2);
        if (iVar3 == 0) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar5);
          }
          InstructionSynchronizationBarrier(0xf);
        }
        else {
          iVar3 = FUN_0e06ac14();
          iVar3 = FUN_0e068b38(*(undefined4 *)(iVar3 + 4),param_3);
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar5);
          }
          InstructionSynchronizationBarrier(0xf);
          if (iVar3 != iVar4) {
            return iVar3;
          }
        }
        iVar4 = FUN_0e06ac0c(param_1);
        iVar3 = DAT_0e06a3c0;
        if (iVar4 == 3) {
          *(undefined4 *)(*(int *)(param_1 + 0x10) + (param_3 & 0x3f) * 4 + 0x80) = 0;
          *(undefined4 *)(*(int *)(param_2 + 0x10) + param_3 * 4 + 0x180) = 0;
          iVar3 = DAT_0e06a3c0;
        }
      }
      else {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar5);
        }
        InstructionSynchronizationBarrier(0xf);
      }
    }
  }
  return iVar3;
}


