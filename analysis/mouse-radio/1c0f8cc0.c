/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8cc0. Types and names are inferred; NOT original source. */

void FUN_1c0f8cc0(int param_1,undefined1 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *local_14;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return;
  }
  iVar4 = FUN_1c100ad8(DAT_1c0f8d1c,&local_14,0,0);
  if (iVar4 == 0) {
    local_14[1] = param_1;
    *(undefined1 *)(local_14 + 2) = param_2;
    local_14[3] = param_3;
    puVar3 = DAT_1c0f8d20;
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
    puVar5 = (undefined4 *)DAT_1c0f8d20[1];
    *local_14 = 0;
    if (puVar5 == (undefined4 *)0x0) {
      *puVar3 = local_14;
    }
    else {
      *puVar5 = local_14;
    }
    puVar3[1] = local_14;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    FUN_1c101608(DAT_1c0f8d24,puVar5,0,0);
  }
  return;
}


