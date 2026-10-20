/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09554c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e09554c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_1c [2];
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_2 + 0xc);
  *(uint *)(param_2 + 0xc) = uVar3 & 0xfffffff7;
  local_1c[0] = param_1;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_0e096594(param_2 + 0x10);
  }
  if (param_4 == 0 && param_3 == 0) {
    uVar2 = FUN_0e09518c(param_2,local_1c);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar2;
  }
  *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
  *(undefined4 *)(param_2 + 0x28) = local_1c[0];
  FUN_0e096474(param_2 + 0x10,0xe095255,param_3,param_4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}


