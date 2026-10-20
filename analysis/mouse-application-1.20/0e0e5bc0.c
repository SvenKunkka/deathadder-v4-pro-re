/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5bc0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0e5bc0(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = _DAT_2f0118dc;
  if (param_2 == 0) {
    param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      param_1 = getCurrentExceptionNumber();
      param_1 = param_1 & 0x1ff;
    }
    if ((param_1 == 0) && (_DAT_2f0118ec != _DAT_2f0118dc)) {
      *(undefined4 *)(_DAT_2f0118dc + 0x88) = 0xfffffff5;
      *(undefined4 *)(iVar2 + 0x84) = 0;
      _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0);
      }
      InstructionSynchronizationBarrier(0xf);
      return *(uint *)(_DAT_2f0118dc + 0x88);
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return param_1;
}


