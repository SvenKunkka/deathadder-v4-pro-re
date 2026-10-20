/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06edd4. Types and names are inferred; NOT original source. */

uint FUN_0e06edd4(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iStack_28;
  uint uStack_24;
  
  iStack_28 = 0;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_1 + 8);
  uVar5 = uVar3 & param_2 ^ uVar3;
  *(uint *)(param_1 + 8) = uVar5;
  uStack_24 = uVar5;
  FUN_0e06e484(param_1,0xe06ed7d,&iStack_28);
  iVar2 = iStack_28;
  while (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x8c) = 0;
    *(uint *)(iVar2 + 100) = uVar5;
    iVar4 = *(int *)(iVar2 + 0x60);
    FUN_0e06de58(iVar2,0);
    iVar2 = iVar4;
  }
  FUN_0e06e078(param_1 + 0xc,uVar6);
  return uVar3 & param_2;
}


