/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0963d8. Types and names are inferred; NOT original source. */

int FUN_0e0963d8(int *param_1,code *param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
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
  piVar4 = (int *)*param_1;
  if (param_1 != piVar4) {
    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      iVar3 = (*param_2)(piVar4,param_3);
      if (iVar3 != 0) goto LAB_0e09640e;
      if (piVar4 == (int *)param_1[1]) break;
    }
  }
  iVar3 = 0;
LAB_0e09640e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3;
}


