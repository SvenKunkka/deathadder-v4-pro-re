/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e413c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e413c(undefined4 param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (param_2 == 1) {
    piVar6 = (int *)&DAT_2f011768;
  }
  else {
    if (param_2 != 0x10) {
      return;
    }
    piVar6 = (int *)&DAT_2f011760;
  }
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0e0e6d66(piVar6,param_1);
  if (iVar3 != 0) {
    iVar5 = 0;
    _DAT_2f01175c = *piVar6;
    iVar4 = 0;
    for (piVar6 = (int *)_DAT_2f01175c; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      iVar5 = iVar5 + 1;
      iVar4 = iVar3;
    }
    if (iVar4 != 0) {
      _DAT_2f01175c = 0;
    }
    if (iVar5 == 0) {
      _DAT_5201e490 = _DAT_5201e490 & ~param_2;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


