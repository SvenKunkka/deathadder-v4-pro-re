/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d630. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d630(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *local_c;
  
  local_c = &DAT_23002b18;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((*(uint *)(param_1 + 0xc) & 0x1e) == 0) {
    if (param_4 == 0 && param_3 == 0) {
      uVar3 = FUN_0e06d2dc(param_1,&local_c);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return uVar3;
    }
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
    *(undefined **)(param_1 + 0x28) = &DAT_23002b18;
    FUN_0e06e648(param_1 + 0x10,0xe06d3a5);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


