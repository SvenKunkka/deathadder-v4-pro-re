/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091db8. Types and names are inferred; NOT original source. */

void FUN_0e091db8(int *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  undefined4 uVar6;
  
  bVar1 = *(byte *)(param_1 + 1);
  uVar6 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar6 = getBasePriority();
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if ((bVar4) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = (&DAT_23007329)[(uint)bVar1 * 0x10];
  if (bVar2 != 0) {
    uVar5 = 0;
    do {
      uVar3 = uVar5 & 0xff;
      uVar5 = uVar5 + 1;
      *(uint *)(*param_1 + 0x508) = *(uint *)(*param_1 + 0x508) & ~(1 << uVar3);
    } while (bVar2 != uVar5);
  }
  (&DAT_23007329)[(uint)bVar1 * 0x10] = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


