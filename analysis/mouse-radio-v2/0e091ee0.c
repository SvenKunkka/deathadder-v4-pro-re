/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091ee0. Types and names are inferred; NOT original source. */

void FUN_0e091ee0(int *param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  iVar4 = DAT_0e091f2c;
  bVar1 = *(byte *)(param_1 + 1);
  uVar7 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar7 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar6 = (uint)*(byte *)(DAT_0e091f2c + (uint)bVar1 * 0x10 + 1);
  if (uVar6 != 0) {
    uVar5 = 0;
    do {
      uVar2 = uVar5 & 0xff;
      uVar5 = uVar5 + 1;
      *(uint *)(*param_1 + 0x508) = *(uint *)(*param_1 + 0x508) & ~(1 << uVar2);
    } while (uVar6 != uVar5);
  }
  *(undefined1 *)(iVar4 + (uint)bVar1 * 0x10 + 1) = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


