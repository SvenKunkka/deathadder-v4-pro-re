/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae99c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e0ae99c(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,char param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_r2;
  
  iVar3 = FUN_0e0ae8a8(*(undefined1 *)(param_1 + 8));
  if (iVar3 == 0xbad0000) {
    FUN_0e0ae84c(param_1);
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    *(undefined4 *)((uint)*(byte *)(param_1 + 8) * 4 + 0x5f99c100) = 0;
    iVar5 = (uint)*(byte *)(param_1 + 8) * 0x10;
    *(undefined4 *)(iVar5 + 0x5f99c520) = extraout_r2;
    *(uint *)(iVar5 + 0x5f99c524) = param_4 & 0xfffff;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_5 != '\0') {
      _DAT_5f99c334 = 1 << *(sbyte *)(param_1 + 8);
    }
  }
  return iVar3;
}


