/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061d3c. Types and names are inferred; NOT original source. */

uint FUN_0e061d3c(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23006958 = DAT_23006958 & 0xfffffeef;
  iVar2 = FUN_0e06ad08(*(undefined1 *)(param_1 + 0x20),*(short *)(param_1 + 0x1a) != 0);
  if (iVar2 == 0) {
    uVar5 = FUN_0e06e9a0();
    lVar6 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    uVar3 = (uint)lVar6;
    while( true ) {
      uVar5 = FUN_0e06e9a0(uVar3);
      lVar7 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
      if ((int)(uint)((uint)(lVar7 - lVar6) < 1000) <= (int)((ulonglong)(lVar7 - lVar6) >> 0x20)) {
        return 0xffffff8c;
      }
      uVar3 = (DAT_23006958 & 0x1ff) >> 8;
      if ((int)(DAT_23006958 << 0x17) < 0) break;
      if ((int)(DAT_23006958 << 0x1b) < 0) {
        return uVar3;
      }
    }
    return 0xfffffffb;
  }
  return 0xfffffffb;
}


