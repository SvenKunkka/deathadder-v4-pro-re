/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0885c8. Types and names are inferred; NOT original source. */

void FUN_0e0885c8(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 in_r3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar5 = (uint)DAT_2300765c;
  uVar3 = 1 << (uVar5 & 0x1f);
  uVar2 = *(uint *)(&DAT_23006d10 + (uint)(DAT_2300765c >> 5) * 4);
  *(uint *)(&DAT_23006d10 + (uint)(DAT_2300765c >> 5) * 4) = uVar2 & ~uVar3;
  if ((uVar3 & uVar2) == 0) {
    return;
  }
  FUN_0e08a980((&DAT_23006d04)[uVar5 * 0xc],(&DAT_23006d05)[uVar5 * 0xc],&DAT_23006d04 + uVar5 * 0xc
               ,uVar5 * 3,in_r3);
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  for (piVar4 = (int *)DAT_23001da8; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    if ((code *)piVar4[2] != (code *)0x0) {
      (*(code *)piVar4[2])((&DAT_23006d04)[(uint)DAT_2300765c * 0xc]);
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0975a8();
  *(undefined4 *)(&DAT_23006d04 + uVar5 * 0xc) = 0;
  *(undefined4 *)(&DAT_23006d08 + uVar5 * 0xc) = 0;
  *(undefined4 *)(&DAT_23006d0c + uVar5 * 0xc) = 0;
  return;
}


