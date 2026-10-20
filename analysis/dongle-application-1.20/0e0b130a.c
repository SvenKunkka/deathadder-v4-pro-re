/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b130a. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0b130a(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = *(int *)(param_1 + 4);
  uVar4 = FUN_0e0b12e0(iVar6 + 0x10,param_3,0);
  puVar5 = *(uint **)(iVar6 + 0x2c);
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (uVar4 < *puVar5) {
    uVar2 = puVar5[2];
    *(uint *)(uVar2 + (uVar4 >> 5) * 4) = *(uint *)(uVar2 + (uVar4 >> 5) * 4) | 1 << (uVar4 & 0x1f);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffea;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


