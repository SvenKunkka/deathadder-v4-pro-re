/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096bec. Types and names are inferred; NOT original source. */

void FUN_0e096bec(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_0e0966bc();
  if (iVar3 == 0) {
    if (*(code **)(param_1 + 0x24) != (code *)0x0) {
      (**(code **)(param_1 + 0x24))(param_1);
    }
    iVar3 = FUN_0e095e78(param_1 + 0x18);
    if (iVar3 != 0) {
      FUN_0e095cfc();
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
      FUN_0e095ff4(uVar4);
      return;
    }
  }
  return;
}


