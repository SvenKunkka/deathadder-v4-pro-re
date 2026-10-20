/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ebe0. Types and names are inferred; NOT original source. */

void FUN_0e06ebe0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar2 = getBasePriority();
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if ((bVar4) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_4 != -1 || param_3 != -1) {
    iVar3 = param_4;
    if ((int)((param_4 + 1) - (uint)(param_3 != -1)) < 0 ==
        (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != -1)))) {
      if (param_4 < (int)(uint)(param_3 == 0)) {
        param_3 = 1;
        iVar3 = 0;
      }
      bVar4 = param_3 != 0;
      param_3 = param_3 + -1;
      iVar3 = iVar3 + -1 + (uint)bVar4;
    }
    FUN_0e06e768(param_1);
    *(undefined4 *)(param_1 + 0x28) = param_5;
    *(undefined4 *)(param_1 + 0x2c) = param_6;
    *(undefined4 *)(param_1 + 0x30) = 0;
    FUN_0e06e648(param_1,&LAB_0e06eb00_1,param_3,iVar3,param_4);
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


