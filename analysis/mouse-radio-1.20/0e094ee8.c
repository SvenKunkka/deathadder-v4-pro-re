/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e094ee8. Types and names are inferred; NOT original source. */

uint * FUN_0e094ee8(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar4 = (uint *)*param_1;
  if (puVar4 == (uint *)0x0) {
    if (param_3 != 0 || param_4 != 0) {
      iVar2 = FUN_0e095cf8(param_1 + 2,uVar5,param_1 + 2,param_4,param_3,param_4);
      if (iVar2 != 0) {
        return (uint *)0x0;
      }
      return *(uint **)(DAT_23007654 + 0x14);
    }
  }
  else {
    uVar3 = *puVar4;
    if (puVar4 == (uint *)param_1[1]) {
      param_1[1] = uVar3 & 0xfffffffc;
    }
    *param_1 = uVar3 & 0xfffffffc;
    if ((*puVar4 & 3) != 0) {
      puVar6 = (uint *)puVar4[1];
      FUN_0e096c54(puVar4);
      puVar4 = puVar6;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return puVar4;
}


