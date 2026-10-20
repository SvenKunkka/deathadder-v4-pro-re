/* Automatically decompiled from Suit2FWData__application_application.bin at 0e0e5ae0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0e0e5ae0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _DAT_2f0118dc;
  _DAT_2f011900 = _DAT_2f0118dc;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0e7164(_DAT_2f0118dc,param_3,0x20,0x2f0118d4,param_4);
  if (param_6 != -1 || param_5 != -1) {
    FUN_0e0e5f08(iVar3 + 0x18,&LAB_0e0e7242_1,param_5,param_6);
  }
  iVar3 = _DAT_2f0118dc;
  *(undefined4 *)(_DAT_2f0118dc + 0x88) = 0xfffffff5;
  *(undefined4 *)(iVar3 + 0x84) = param_2;
  _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)(_DAT_2f0118dc + 0x88);
}


