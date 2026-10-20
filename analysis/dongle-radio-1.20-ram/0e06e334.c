/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e334. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e334(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_23007170;
  if (param_2 == -1 && param_1 == -1) {
    FUN_0e06e768(DAT_23007170 + 0x18);
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
    if ((*(byte *)(iVar2 + 0xd) & 0x10) == 0) {
      FUN_0e06db60(iVar2,uVar4);
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    return 0xffffffff;
  }
  uVar3 = FUN_0e06e278();
  uVar4 = FUN_0e05ba10(uVar3 + 999,((int)uVar3 >> 0x1f) + (uint)(0xfffffc18 < uVar3),1000,0);
  return uVar4;
}


