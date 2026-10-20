/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cd54. Types and names are inferred; NOT original source. */

void FUN_0e06cd54(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0e06df70();
  while (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x8c) = 0xffffffdd;
    FUN_0e06dd24();
    iVar3 = FUN_0e06df70(param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  FUN_0e06e078(param_1 + 8,uVar4,*(undefined4 *)(param_1 + 0x1c),param_4);
  return;
}


