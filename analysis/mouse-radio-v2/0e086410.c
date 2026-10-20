/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e086410. Types and names are inferred; NOT original source. */

undefined4 FUN_0e086410(uint *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 auStack_38 [28];
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((((param_2 == 0) || (uVar4 = *param_1, uVar4 < param_2)) || (uVar4 <= param_3)) ||
     (uVar4 <= (param_2 - 1) + param_3)) {
    uVar3 = 0xffffffea;
  }
  else {
    iVar2 = FUN_0e086168(param_1,param_3,param_2,1,auStack_38,0);
    if (iVar2 == 0) {
      uVar3 = 0xfffffff2;
    }
    else {
      FUN_0e086080(param_1,param_3,param_2,0,auStack_38);
      uVar3 = 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


