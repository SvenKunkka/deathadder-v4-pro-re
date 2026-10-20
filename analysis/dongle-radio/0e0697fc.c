/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0697fc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0697fc(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,char param_5)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 1 << *(sbyte *)(param_1 + 8);
  if ((uVar3 & 0xe080) == 0) {
    return DAT_0e0698a0;
  }
  if ((~*(uint *)(DAT_0e06988c + 4) & 0xe080 & uVar3) == 0) {
    return DAT_0e06989c;
  }
  FUN_0e069664();
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
  *(undefined4 *)(DAT_0e069890 + (uint)*(byte *)(param_1 + 8) * 4) = 0;
  iVar4 = (uint)*(byte *)(param_1 + 8) * 0x10;
  *(undefined4 *)(iVar4 + 0x5f99c520) = param_3;
  *(uint *)(iVar4 + 0x5f99c524) = param_4 & 0xfffff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_5 != '\0') {
    *(int *)(DAT_0e069894 + 0x354) = 1 << *(sbyte *)(param_1 + 8);
  }
  return DAT_0e069898;
}


