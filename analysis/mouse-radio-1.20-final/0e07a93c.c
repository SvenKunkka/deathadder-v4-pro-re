/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07a93c. Types and names are inferred; NOT original source. */

void FUN_0e07a93c(undefined1 *param_1)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  dword dVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  dword dVar9;
  uint uVar10;
  int iVar11;
  
  switch(*param_1) {
  case 0:
    FUN_0e07a77c(param_1[1],(int)(char)param_1[4],param_1[5]);
    return;
  case 1:
    iVar7 = *(int *)(param_1 + 8);
    uVar8 = (uint)(byte)param_1[1];
    iVar11 = (int)(char)param_1[4];
    dVar9 = (dword)(byte)param_1[6];
    RADIO_S_SHORTS = 0;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    RADIO_S_TASKS_DISABLE = 1;
    do {
      dVar4 = RADIO_S_EVENTS_DISABLED;
    } while (dVar4 == 0);
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    FUN_0e07a688(uVar8,param_1[5],*(undefined4 *)(param_1 + 0xc),dVar4);
    if (uVar8 < 7) {
      if (4 < uVar8) {
        dVar4 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar4 | 0x100001;
        RADIO_S_MODE = uVar8;
        FUN_0e07a4c0(iVar11);
        goto LAB_0e07ab10;
      }
    }
    else if (uVar8 == 0xf) {
      dVar4 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar4 | 0x100001;
      RADIO_S_MODE = 0xf;
      FUN_0e07a4c0(iVar11);
      if (dVar9 - 0xb < 0x10) {
        dVar9 = dVar9 * 5 - 0x32;
      }
      else {
        dVar9 = 5;
      }
      goto LAB_0e07ab10;
    }
    dVar4 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar4 | 0x21;
    RADIO_S_MODE = uVar8;
    FUN_0e07a4c0(iVar11);
LAB_0e07ab10:
    RADIO_S_FREQUENCY = dVar9;
    DAT_230038ac = 0;
    RADIO_S_EVENTS_END = 0;
    dVar4 = RADIO_S_EVENTS_END;
    if (iVar7 != 0) {
      RADIO_S_INTENSET00 = 0x40;
    }
    RADIO_S_TASKS_TXEN = 1;
    return;
  case 2:
    FUN_0e07a810(param_1[1],param_1[0xc],param_1[4]);
    return;
  case 3:
    uVar5 = *(undefined4 *)(param_1 + 8);
    DAT_23007713 = param_1[5];
    break;
  case 4:
    uVar5 = *(undefined4 *)(param_1 + 8);
    DAT_23007713 = param_1[4];
    break;
  case 5:
    uVar8 = *(uint *)(param_1 + 8);
    iVar7 = *(int *)(param_1 + 0xc);
    uVar10 = (uint)(byte)param_1[1];
    cVar2 = param_1[4];
    dVar9 = (dword)(byte)param_1[6];
    RADIO_S_SHORTS = 0;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    RADIO_S_TASKS_DISABLE = 1;
    do {
      dVar4 = RADIO_S_EVENTS_DISABLED;
    } while (dVar4 == 0);
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    FUN_0e07a688(uVar10,param_1[5],*(undefined4 *)(param_1 + 0x10),dVar4);
    RADIO_S_MODE = uVar10;
    dVar4 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar4 | 0x80001;
    FUN_0e07a4c0((int)cVar2);
    if (uVar10 == 0xf) {
      if (dVar9 - 0xb < 0x10) {
        dVar9 = dVar9 * 5 - 0x32;
      }
      else {
        dVar9 = 5;
      }
    }
    RADIO_S_FREQUENCY = dVar9;
    uVar6 = (uint)DAT_2300768c;
    bVar1 = (&DAT_0e098b5c)[uVar10];
    DAT_230038ac = 0;
    thunk_FUN_23029c64(&DAT_0e098b6c);
    FUN_0e07a708(0);
    dVar4 = TIMER021_S_SHORTS;
    TIMER021_S_SHORTS = 0;
    TIMER021_S_INTENCLR = 0xffffffff;
    uVar5 = thunk_FUN_23029e1c(&DAT_0e098b6c,(uVar6 * bVar1 * (100 - uVar8)) / uVar8 + uVar6 * bVar1
                              );
    thunk_FUN_23029ca4(&DAT_0e098b6c,1,uVar5,2,0);
    if (iVar7 != 0) {
      RADIO_S_INTENSET00 = 0x40;
    }
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = getBasePriority();
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if ((bVar3) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    EGU020_S_TASKS_TRIGGER_0 = 1;
    iVar7 = FUN_0e092994(DAT_23007711);
    if (iVar7 != 0) {
      FUN_0e092a14(1 << DAT_23007711);
    }
    FUN_0e07a3b8();
    FUN_0e092628(DAT_23007711,&TIMER021_S_EVENTS_COMPARE_1,&RADIO_S_TASKS_TXEN);
    DAT_230038a0 = DAT_230038a0 | 0x100;
    FUN_0e0929f0(1 << (uint)DAT_23007711);
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
  default:
    return;
  }
  thunk_FUN_23029c64(&DAT_0e098b6c);
  dVar4 = TIMER021_S_SHORTS;
  TIMER021_S_SHORTS = 0;
  TIMER021_S_INTENCLR = 0xffffffff;
  uVar5 = thunk_FUN_23029d58(&DAT_0e098b6c,uVar5);
  thunk_FUN_23029ca4(&DAT_0e098b6c,0,uVar5,0x10001,1);
  ram_candidate_23029c84(&DAT_0e098b6c);
  return;
}


