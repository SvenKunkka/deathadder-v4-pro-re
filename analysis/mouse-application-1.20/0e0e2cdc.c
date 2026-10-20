/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e2cdc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e2cdc(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  
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
  for (piVar4 = (int *)_DAT_2f011720; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    puVar3 = piVar4 + 2;
    if (param_1 != 0) {
      puVar3 = piVar4 + 1;
    }
    if ((code *)*puVar3 != (code *)0x0) {
      (*(code *)*puVar3)(*(undefined1 *)((uint)DAT_2f0118e4 * 0xc + 0x2f011714));
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


