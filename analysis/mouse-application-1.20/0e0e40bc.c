/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e40bc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0e40bc(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  if (param_2 == 1) {
    piVar5 = (int *)&DAT_2f011768;
  }
  else {
    if (param_2 != 0x10) {
      return;
    }
    piVar5 = (int *)&DAT_2f011760;
  }
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = false;
  iVar2 = 0;
  _DAT_2f01175c = *piVar5;
  for (piVar4 = (int *)_DAT_2f01175c; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    bVar1 = true;
    iVar2 = iVar2 + 1;
  }
  if (bVar1) {
    _DAT_2f01175c = 0;
  }
  uVar3 = 0;
  if (iVar2 == 0) {
    iVar2 = 0x5201e000;
    uVar3 = _DAT_5201e490 & ~param_2 | param_2;
    _DAT_5201e490 = uVar3;
  }
  FUN_0e0e6d66(piVar5,param_1,iVar2,uVar3,param_4);
  *param_1 = 0;
  if ((undefined4 *)piVar5[1] == (undefined4 *)0x0) {
    *piVar5 = (int)param_1;
    piVar5[1] = (int)param_1;
  }
  else {
    *(undefined4 *)piVar5[1] = param_1;
    piVar5[1] = (int)param_1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


