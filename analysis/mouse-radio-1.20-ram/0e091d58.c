/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091d58. Types and names are inferred; NOT original source. */

undefined4 FUN_0e091d58(int *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)(param_1 + 1);
  uVar5 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar5 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = (&DAT_23007329)[(uint)bVar1 * 0x10];
  if (7 < bVar2) {
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xbad0002;
  }
  *param_2 = bVar2;
  (&DAT_23007329)[(uint)bVar1 * 0x10] = bVar2 + 1;
  *(uint *)(*param_1 + 0x508) = 1 << *param_2 | *(uint *)(*param_1 + 0x508);
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0xbad0000;
}


