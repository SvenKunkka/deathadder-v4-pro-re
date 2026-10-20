/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e3d0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e3d0(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_2 == -1 && param_1 == -1) {
    iVar4 = *(int *)(DAT_0e06e43c + 8);
    FUN_0e06e804(iVar4 + 0x18);
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if ((*(byte *)(iVar4 + 0xd) & 0x10) == 0) {
      FUN_0e06dbfc(iVar4,uVar3);
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    return 0xffffffff;
  }
  uVar2 = FUN_0e06e314();
  uVar3 = FUN_0e05bbd8(uVar2 + 999,((int)uVar2 >> 0x1f) + (uint)(0xfffffc18 < uVar2),1000,0);
  return uVar3;
}


