/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0696e0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0696e0(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  do {
    uVar3 = DAT_0e069724[1];
  } while (0x3fffffff < uVar3);
  *param_1 = *DAT_0e069724;
  param_1[1] = uVar3 & 0xfffff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  return DAT_0e069728;
}


