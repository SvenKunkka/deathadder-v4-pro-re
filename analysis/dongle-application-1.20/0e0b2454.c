/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b2454. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0afed0(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
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
  if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1d) < 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfb;
    FUN_0e0afc14();
    FUN_0e0afeac(0x2f011bda,uVar3);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


