/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c101e20. Types and names are inferred; NOT original source. */

void FUN_1c101e20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = DAT_1c101e6c;
  *DAT_1c101e70 = *(undefined4 *)(DAT_1c101e6c + 8);
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
  iVar4 = *(int *)(iVar4 + 8);
  FUN_1c101a4c(iVar4,param_3,param_3,uVar3);
  if (param_6 != -1 || param_5 != -1) {
    FUN_1c10259c(iVar4 + 0x18,DAT_1c101e74,param_5,param_6);
  }
  FUN_1c0f5ed8(param_2);
  return;
}


