/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d8f8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d8f8(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
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
  if ((param_3 == (uint *)0x0) || (*param_1 <= param_2)) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *param_3 = *(uint *)(param_1[2] + (param_2 >> 5) * 4) >> (param_2 & 0x1f) & 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


