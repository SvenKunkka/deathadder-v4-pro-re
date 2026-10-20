/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b1cda. Types and names are inferred; NOT original source. */

int FUN_0e0b1cda(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint extraout_r3;
  uint *puVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  if ((*(int *)(param_1 + 0x14) == 0) ||
     (iVar3 = FUN_0e0b1c04(*(int *)(param_1 + 0x14),7,param_3,param_1,param_4), iVar3 == 0)) {
    return 0;
  }
  puVar4 = *(uint **)(extraout_r3 + 0x14);
  if (puVar4 == (uint *)0x0) {
    return -0x86;
  }
  iVar3 = FUN_0e0b1c04(puVar4,5);
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = FUN_0e0b1bc2(extraout_r3);
  if (iVar3 != 0) {
    return -0x10;
  }
  uVar6 = FUN_0e0b1c04(*(undefined4 *)(extraout_r3 + 0x14),8);
  if ((int)uVar6 == 0) {
    if (DAT_2f011bd9 != '\0') {
      thunk_FUN_0e0af748(puVar4 + 5,(int)((ulonglong)uVar6 >> 0x20),0xffffffff,0xffffffff,param_4);
    }
    if (puVar4[4] == 0) {
      puVar4[4] = extraout_r3;
      FUN_0e0b2404(puVar4 + 0xc,&DAT_0e0b1c71);
    }
    if ((char)puVar4[1] == '\0') {
      iVar3 = (*(code *)puVar4[2])(puVar4[4]);
      if (iVar3 < 0) goto LAB_0e0ac5be;
      *(undefined1 *)(puVar4 + 1) = 1;
    }
    else {
      iVar3 = 0;
    }
    puVar4[3] = 0;
    *puVar4 = *puVar4 | 0x20;
LAB_0e0ac5be:
    if (DAT_2f011bd9 == '\0') {
      return iVar3;
    }
    thunk_FUN_0e0af700(puVar4 + 5);
    return iVar3;
  }
  puVar4 = *(uint **)(extraout_r3 + 0x14);
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
  iVar3 = 0;
  if ((char)puVar4[1] == '\0') {
    iVar3 = (*(code *)puVar4[2])(extraout_r3);
    if (iVar3 < 0) goto LAB_0e0ac566;
    *(undefined1 *)(puVar4 + 1) = 1;
  }
  *puVar4 = *puVar4 | 0x20;
  puVar4[3] = 0;
LAB_0e0ac566:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3;
}


