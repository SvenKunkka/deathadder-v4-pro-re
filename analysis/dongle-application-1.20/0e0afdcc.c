/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0afdcc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0afdcc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _DAT_2f011ba0;
  _DAT_2f011bc4 = _DAT_2f011ba0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0b247c(_DAT_2f011ba0,param_3);
  if (param_6 != -1 || param_5 != -1) {
    FUN_0e0b02bc(iVar3 + 0x18,&LAB_0e0b258e_1,param_5,param_6);
  }
  FUN_0e0aca34(param_2);
  return;
}


