/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086784. Types and names are inferred; NOT original source. */

uint FUN_0e086784(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  uVar3 = FUN_0e0868ac(param_2 + 1);
  if (uVar3 == 0) {
    if (3 < (uint)param_2[2]) {
      return 0xffffffea;
    }
  }
  else if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar1 = *(ushort *)(param_1 + 6);
  uVar3 = uVar1 & 7;
  if (*(ushort *)((int)param_1 + 0x1a) == 0xffff) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
  if (uVar3 == 2) {
    iVar6 = *(ushort *)((int)param_1 + 0x1a) + 1;
    *(short *)((int)param_1 + 0x1a) = (short)iVar6;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    pcVar4 = (code *)FUN_0e0868d4(param_2 + 1,0,uVar5,iVar6,param_4);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(param_1,param_2,2,0);
    }
    return 2;
  }
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
    break;
  default:
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffffb;
  case 5:
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xffffff7a;
  }
  if ((uVar1 & 7) == 0) {
    FUN_0e08647c(param_1,2);
    return uVar3;
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


