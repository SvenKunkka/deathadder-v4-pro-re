/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1c18. Types and names are inferred; NOT original source. */

int FUN_0e0b1c18(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int extraout_r3;
  undefined4 uVar6;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0e0b1c04(*(int *)(param_1 + 0x14),8,param_3,param_4,param_4);
    if (iVar4 == 0) {
      iVar4 = FUN_0e0ac474(*(undefined4 *)(param_1 + 0x14),0,0,0);
      if ((iVar4 == 0) &&
         (iVar5 = FUN_0e0b1c04(*(undefined4 *)(param_1 + 0x14),2), iVar4 = extraout_r3, iVar5 != 0))
      {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0b1c6a);
        (*pcVar1)();
      }
    }
    else {
      uVar6 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar6 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      iVar4 = FUN_0e0b1bd0(param_1);
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
    }
  }
  return iVar4;
}


