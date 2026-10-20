/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1076. Types and names are inferred; NOT original source. */

uint FUN_0e0b1076(undefined4 *param_1,undefined4 *param_2)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = FUN_0e0b0fea();
  if (-1 < (int)uVar3) {
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
    uVar1 = *(ushort *)(param_1 + 6);
    uVar3 = uVar1 & 7;
    if (*(short *)((int)param_1 + 0x1a) == -1) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar3 = 0xfffffff5;
    }
    else if (uVar3 == 2) {
      *(short *)((int)param_1 + 0x1a) = *(short *)((int)param_1 + 0x1a) + 1;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e0b100a(param_1,param_2,2,0);
    }
    else {
      switch(uVar3) {
      case 0:
      case 4:
      case 6:
        *param_2 = 0;
        if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
          *param_1 = param_2;
          param_1[1] = param_2;
        }
        else {
          *(undefined4 *)param_1[1] = param_2;
          param_1[1] = param_2;
        }
        if ((uVar1 & 7) == 0) {
          FUN_0e0abb44(param_1,2,uVar4);
        }
        else {
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(uVar4);
          }
          InstructionSynchronizationBarrier(0xf);
        }
        break;
      default:
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        uVar3 = 0xfffffffb;
        break;
      case 5:
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        uVar3 = 0xffffff7a;
      }
    }
  }
  return uVar3;
}


