/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c102d6c. Types and names are inferred; NOT original source. */

uint FUN_1c102d6c(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iStack_28;
  uint uStack_24;
  
  uVar3 = DAT_1c102c84;
  iStack_28 = 0;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar4 = *(uint *)(param_1 + 8);
  uVar6 = uVar4 & param_2 ^ uVar4;
  *(uint *)(param_1 + 8) = uVar6;
  uStack_24 = uVar6;
  FUN_1c1023d8(param_1,uVar3,&iStack_28);
  iVar2 = iStack_28;
  while (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x8c) = 0;
    *(uint *)(iVar2 + 100) = uVar6;
    iVar5 = *(int *)(iVar2 + 0x60);
    FUN_1c101db0(iVar2,0);
    iVar2 = iVar5;
  }
  FUN_1c101fd0(param_1 + 0xc,uVar7);
  return uVar4 & param_2;
}


