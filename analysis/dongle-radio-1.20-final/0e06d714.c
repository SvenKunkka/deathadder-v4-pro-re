/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d714. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d714(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *local_1c [2];
  
  local_1c[0] = &DAT_23002b18;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar3 & 0xfffffff7;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_0e06e768(param_1 + 0x10);
  }
  if (param_4 == 0 && param_3 == 0) {
    uVar2 = FUN_0e06d2dc(param_1,local_1c);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar2;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
  *(undefined **)(param_1 + 0x28) = local_1c[0];
  FUN_0e06e648(param_1 + 0x10,0xe06d3a5,param_3,param_4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}


