/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096b78. Types and names are inferred; NOT original source. */

void FUN_0e096b78(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  uVar3 = 0;
  bVar5 = (bool)isCurrentModePrivileged();
  if (bVar5) {
    uVar3 = getBasePriority();
  }
  bVar5 = (bool)isCurrentModePrivileged();
  if ((bVar5) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_4 != -1 || param_3 != -1) {
    iVar4 = param_4;
    if ((int)((param_4 + 1) - (uint)(param_3 != -1)) < 0 ==
        (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != -1)))) {
      if (param_4 < (int)(uint)(param_3 == 0)) {
        param_3 = 1;
        iVar4 = 0;
      }
      bVar5 = param_3 != 0;
      param_3 = param_3 + -1;
      iVar4 = iVar4 + -1 + (uint)bVar5;
    }
    FUN_0e0966bc(param_1);
    *(undefined4 *)(param_1 + 0x28) = param_5;
    *(undefined4 *)(param_1 + 0x2c) = param_6;
    uVar2 = DAT_0e096be8;
    *(undefined4 *)(param_1 + 0x30) = 0;
    FUN_0e09659c(param_1,uVar2,param_3,iVar4,param_4);
  }
  bVar5 = (bool)isCurrentModePrivileged();
  if (bVar5) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


