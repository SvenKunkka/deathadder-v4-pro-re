/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0afeac. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0afeac(undefined4 param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1ff;
    }
    if (uVar2 == 0) {
      if (_DAT_2f011bb0 != _DAT_2f011ba0) {
        FUN_0e0aca34();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


