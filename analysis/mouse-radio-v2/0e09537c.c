/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09537c. Types and names are inferred; NOT original source. */

void FUN_0e09537c(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_c;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar2 = *(uint *)(param_1 + -4);
  *(uint *)(param_1 + -4) = uVar2 & 0xfffffff7;
  if ((int)(uVar2 << 0x1c) < 0) {
    local_c = *(undefined4 *)(param_1 + 0x18);
    FUN_0e0952b4(param_1 + -0x10,&local_c);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


