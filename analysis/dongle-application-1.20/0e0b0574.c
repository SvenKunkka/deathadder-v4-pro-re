/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0574. Types and names are inferred; NOT original source. */

void FUN_0e0b0574(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  
  uVar2 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar2 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_4 != -1 || param_3 != -1) {
    if ((int)((param_4 + 1) - (uint)(param_3 != -1)) < 0 ==
        (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != -1)))) {
      if (param_4 < (int)(uint)(param_3 == 0)) {
        param_3 = 1;
        param_4 = 0;
      }
      bVar3 = param_3 != 0;
      param_3 = param_3 + -1;
      param_4 = param_4 + -1 + (uint)bVar3;
    }
    FUN_0e0b26cc(param_1);
    *(undefined4 *)(param_1 + 0x28) = param_5;
    *(undefined4 *)(param_1 + 0x2c) = param_6;
    *(undefined4 *)(param_1 + 0x30) = 0;
    FUN_0e0b02bc(param_1,&LAB_0e0b0494_1,param_3,param_4);
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


