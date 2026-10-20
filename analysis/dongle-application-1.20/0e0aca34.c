/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0aca34. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0aca34(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = _DAT_2f011ba0;
  *(undefined4 *)(_DAT_2f011ba0 + 0x88) = 0xfffffff5;
  *(undefined4 *)(iVar2 + 0x84) = param_1;
  _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)(_DAT_2f011ba0 + 0x88);
}


