/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5420. Types and names are inferred; NOT original source. */

void FUN_0e0e5420(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0e0e724a();
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 0xc) != iVar3) {
      iVar3 = iVar3 + 1;
    }
    *(int *)(param_1 + 8) = iVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  *(undefined4 *)(iVar3 + 0x88) = 0;
  FUN_0e0e71b4();
  FUN_0e0e5bc0(0x2f011915,uVar4);
  return;
}


