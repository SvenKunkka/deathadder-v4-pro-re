/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e096164. Types and names are inferred; NOT original source. */

undefined4 FUN_0e096164(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = DAT_23007654;
  if (param_2 == -1 && param_1 == -1) {
    FUN_0e096594(DAT_23007654 + 0x18);
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
      FUN_0e095a10(iVar4,uVar5);
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
  iVar4 = FUN_0e0960a8();
  lVar3 = (longlong)iVar4 * 1000 + 0x7a11;
  uVar5 = FUN_0e0795d8((int)lVar3,(int)((ulonglong)lVar3 >> 0x20),0x7a12,0);
  return uVar5;
}


