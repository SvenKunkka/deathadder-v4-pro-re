/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06df64. Types and names are inferred; NOT original source. */

void FUN_0e06df64(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = DAT_0e06dfb0;
  *DAT_0e06dfb4 = *(undefined4 *)(DAT_0e06dfb0 + 8);
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar4 = *(int *)(iVar4 + 8);
  FUN_0e06db10(iVar4,param_3,param_3,uVar3);
  if (param_6 != -1 || param_5 != -1) {
    FUN_0e06e6e4(iVar4 + 0x18,DAT_0e06dfb8,param_5,param_6);
  }
  FUN_0e0612cc(param_2);
  return;
}


