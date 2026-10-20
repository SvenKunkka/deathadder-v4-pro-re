/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fde80. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0fde80(int *param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar5 = DAT_1c0fded4 + (uint)*(byte *)(param_1 + 1) * 0x10;
  bVar1 = *(byte *)(iVar5 + 1);
  if (7 < bVar1) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return DAT_1c0fdedc;
  }
  *param_2 = bVar1;
  *(byte *)(iVar5 + 1) = bVar1 + 1;
  uVar4 = DAT_1c0fded8;
  *(uint *)(*param_1 + 0x508) = 1 << *param_2 | *(uint *)(*param_1 + 0x508);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar4;
}


