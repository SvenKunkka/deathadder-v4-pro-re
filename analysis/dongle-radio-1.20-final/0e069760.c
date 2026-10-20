/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069760. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e069760(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,char param_5)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 1 << *(sbyte *)(param_1 + 8);
  if ((uVar3 & 0xe080) == 0) {
    return 0xbad0008;
  }
  if ((~DAT_23000ab4 & 0xe080 & uVar3) == 0) {
    return 0xbad0004;
  }
  FUN_0e0695c8();
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)((uint)*(byte *)(param_1 + 8) * 4 + 0x5f99c100) = 0;
  iVar4 = (uint)*(byte *)(param_1 + 8) * 0x10;
  *(undefined4 *)(iVar4 + 0x5f99c520) = param_3;
  *(uint *)(iVar4 + 0x5f99c524) = param_4 & 0xfffff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_5 != '\0') {
    _DAT_5f99c354 = 1 << *(sbyte *)(param_1 + 8);
  }
  return 0xbad0000;
}


