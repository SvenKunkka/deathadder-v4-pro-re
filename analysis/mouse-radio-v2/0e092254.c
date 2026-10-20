/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e092254. Types and names are inferred; NOT original source. */

int FUN_0e092254(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = DAT_0e092318;
  if (param_1 == param_2) {
    if ((param_3 != 0xff) &&
       (iVar3 = FUN_0e0977e0(*(undefined4 *)(param_1 + 4),param_3), iVar3 == DAT_0e092314)) {
      FUN_0e092b60(param_1);
      iVar3 = DAT_0e092314;
    }
  }
  else {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
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
      iVar3 = FUN_0e0977e0(*(undefined4 *)(param_1 + 4),param_3);
      iVar4 = DAT_0e092314;
      if ((iVar3 == DAT_0e092314) &&
         (iVar3 = FUN_0e0977e0(*(undefined4 *)(param_2 + 4),param_3), iVar3 == iVar4)) {
        iVar3 = FUN_0e0920c4(param_1,param_2);
        if (iVar3 == 0) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar5);
          }
          InstructionSynchronizationBarrier(0xf);
        }
        else {
          iVar3 = FUN_0e092b68();
          iVar3 = FUN_0e0977e0(*(undefined4 *)(iVar3 + 4),param_3);
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar5);
          }
          InstructionSynchronizationBarrier(0xf);
          if (iVar3 != iVar4) {
            return iVar3;
          }
        }
        iVar4 = FUN_0e092b60(param_1);
        iVar3 = DAT_0e092314;
        if (iVar4 == 3) {
          *(undefined4 *)(*(int *)(param_1 + 0x10) + (param_3 & 0x3f) * 4 + 0x80) = 0;
          *(undefined4 *)(*(int *)(param_2 + 0x10) + param_3 * 4 + 0x180) = 0;
          iVar3 = DAT_0e092314;
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


