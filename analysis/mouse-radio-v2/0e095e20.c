/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095e20. Types and names are inferred; NOT original source. */

void FUN_0e095e20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = DAT_0e095e6c;
  *DAT_0e095e70 = *(undefined4 *)(DAT_0e095e6c + 8);
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
  FUN_0e095a4c(iVar4,param_3,param_3,uVar3);
  if (param_6 != -1 || param_5 != -1) {
    FUN_0e09659c(iVar4 + 0x18,DAT_0e095e74,param_5,param_6);
  }
  FUN_0e089ed8(param_2);
  return;
}


