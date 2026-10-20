/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b05e8. Types and names are inferred; NOT original source. */

uint FUN_0e0b05e8(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_28;
  uint local_24;
  uint uStack_20;
  
  local_28 = 0;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar4 = *(uint *)(param_1 + 8);
  uVar5 = uVar4 ^ param_3 & (param_2 ^ uVar4);
  *(uint *)(param_1 + 8) = uVar5;
  local_24 = uVar5;
  uStack_20 = param_3;
  FUN_0e0b2656(param_1,0xe0b27bb,&local_28);
  iVar2 = local_28;
  while (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x88) = 0;
    *(uint *)(iVar2 + 100) = uVar5;
    iVar3 = *(int *)(iVar2 + 0x60);
    FUN_0e0b2540(iVar2,0);
    iVar2 = iVar3;
  }
  FUN_0e0afeac(param_1 + 0xc,uVar6);
  return uVar4 & param_3;
}


