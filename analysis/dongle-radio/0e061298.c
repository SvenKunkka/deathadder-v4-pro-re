/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061298. Types and names are inferred; NOT original source. */

int FUN_0e061298(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = DAT_0e0612c8;
  if (*(int *)(DAT_0e0612c4 + 8) == param_1) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getCurrentExceptionNumber();
      uVar4 = uVar4 & 0x1ff;
    }
    if (uVar4 != 0) {
      *(uint *)(DAT_0e0612c8 + 4) = *(uint *)(DAT_0e0612c8 + 4) | 0x10000000;
      *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xffff7fff;
    }
  }
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (-1 < (int)((uint)*(byte *)(param_1 + 0xc) << 0x1f)) {
    if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1c) < 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return param_1;
    }
    iVar2 = FUN_0e06dbfc(param_1,uVar3,1);
    return iVar2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  software_interrupt(2);
  return 4;
}


