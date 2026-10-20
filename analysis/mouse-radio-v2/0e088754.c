/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e088754. Types and names are inferred; NOT original source. */

void FUN_0e088754(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 in_r3;
  uint *puVar7;
  int *piVar8;
  uint uVar9;
  undefined4 uVar10;
  
  iVar6 = DAT_0e0887ec;
  uVar9 = (uint)*(byte *)(DAT_0e0887ec + 0x10);
  uVar4 = 1 << (uVar9 & 0x1f);
  puVar7 = (uint *)(DAT_0e0887f0 + (uint)(*(byte *)(DAT_0e0887ec + 0x10) >> 5) * 4);
  uVar3 = *puVar7;
  *puVar7 = uVar3 & ~uVar4;
  iVar2 = DAT_0e0887f4;
  if ((uVar4 & uVar3) == 0) {
    return;
  }
  iVar5 = DAT_0e0887f4 + uVar9 * 0xc;
  FUN_0e08ab0c(*(undefined1 *)(DAT_0e0887f4 + uVar9 * 0xc),*(undefined1 *)(iVar5 + 1),iVar5,
               uVar9 * 3,in_r3);
  uVar10 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar10 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  for (piVar8 = (int *)*DAT_0e0887f8; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
    if ((code *)piVar8[2] != (code *)0x0) {
      (*(code *)piVar8[2])(*(undefined1 *)(iVar2 + (uint)*(byte *)(iVar6 + 0x10) * 0xc));
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar10);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0976c8();
  iVar6 = iVar2 + uVar9 * 0xc;
  *(undefined4 *)(iVar2 + uVar9 * 0xc) = 0;
  *(undefined4 *)(iVar6 + 4) = 0;
  *(undefined4 *)(iVar6 + 8) = 0;
  return;
}


