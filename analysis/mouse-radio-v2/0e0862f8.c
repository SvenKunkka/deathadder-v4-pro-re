/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0862f8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0862f8(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((param_3 == (uint *)0x0) || (*param_1 <= param_2)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar3 = param_2 >> 5;
    *param_3 = *(uint *)(param_1[2] + uVar3 * 4) >> (param_2 & 0x1f) & 1;
    uVar2 = 0;
    *(uint *)(param_1[2] + uVar3 * 4) = *(uint *)(param_1[2] + uVar3 * 4) | 1 << (param_2 & 0x1f);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar2;
}


