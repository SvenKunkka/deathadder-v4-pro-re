/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c1009c4. Types and names are inferred; NOT original source. */

void FUN_1c1009c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_30;
  int iStack_2c;
  
  FUN_1c102958(&local_30,param_2,param_5,param_6);
  iVar4 = iStack_2c;
  iVar3 = local_30;
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
  while ((uVar6 = FUN_1c0f1e94(param_1,param_2,param_3), (int)uVar6 == 0 &&
         (param_5 != 0 || param_6 != 0))) {
    FUN_1c1029e8(&local_30,(int)((ulonglong)uVar6 >> 0x20),iVar3,iVar4);
    param_6 = iStack_2c;
    param_5 = local_30;
    FUN_1c101e20(param_1 + 0x14,uVar5,param_1 + 0xc);
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
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


