/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061e3c. Types and names are inferred; NOT original source. */

uint FUN_0e061e3c(int param_1)

{
  short sVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  
  puVar3 = DAT_0e061edc;
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  sVar1 = *(short *)(param_1 + 0x1a);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  *DAT_0e061edc = *DAT_0e061edc & 0xfffffeff;
  *puVar3 = *puVar3 & 0xffffffef;
  iVar4 = FUN_0e06ada4(*(undefined1 *)(param_1 + 0x20),sVar1 != 0);
  if (iVar4 == 0) {
    uVar7 = FUN_0e06ea3c();
    lVar8 = FUN_0e05bbd8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
    uVar5 = (uint)lVar8;
    while( true ) {
      uVar7 = FUN_0e06ea3c(uVar5);
      lVar9 = FUN_0e05bbd8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      if ((int)(uint)((uint)(lVar9 - lVar8) < 1000) <= (int)((ulonglong)(lVar9 - lVar8) >> 0x20)) {
        return 0xffffff8c;
      }
      uVar5 = (*puVar3 & 0x1ff) >> 8;
      if ((int)(*puVar3 << 0x17) < 0) break;
      if ((int)(*puVar3 << 0x1b) < 0) {
        return uVar5;
      }
    }
    return 0xfffffffb;
  }
  return 0xfffffffb;
}


