/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e095cf8. Types and names are inferred; NOT original source. */

void FUN_0e095cf8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = DAT_23007654;
  DAT_23007670 = DAT_23007654;
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
  FUN_0e095924(DAT_23007654,param_3,param_3,uVar4);
  if (param_6 != -1 || param_5 != -1) {
    FUN_0e096474(iVar3 + 0x18,&LAB_0e0959a4_1,param_5,param_6);
  }
  FUN_0e089d4c(param_2);
  return;
}


