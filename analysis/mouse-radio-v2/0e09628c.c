/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e09628c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e09628c(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_2 == -1 && param_1 == -1) {
    iVar4 = *(int *)(DAT_0e0962f4 + 8);
    FUN_0e0966bc(iVar4 + 0x18);
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    if ((*(byte *)(iVar4 + 0xd) & 0x10) == 0) {
      FUN_0e095b38(iVar4,uVar5);
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar5);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    return 0xffffffff;
  }
  iVar4 = FUN_0e0961d0();
  lVar3 = (longlong)iVar4 * 1000 + 0x7a11;
  uVar5 = FUN_0e0797c0((int)lVar3,(int)((ulonglong)lVar3 >> 0x20),0x7a12,0);
  return uVar5;
}


