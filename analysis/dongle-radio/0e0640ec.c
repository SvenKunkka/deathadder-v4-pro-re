/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0640ec. Types and names are inferred; NOT original source. */

void FUN_0e0640ec(int param_1,undefined1 param_2,undefined4 param_3)

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
  iVar4 = FUN_0e06cb80(DAT_0e064148,&local_14,0,0);
  if (iVar4 == 0) {
    local_14[1] = param_1;
    *(undefined1 *)(local_14 + 2) = param_2;
    local_14[3] = param_3;
    puVar3 = DAT_0e06414c;
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    puVar5 = (undefined4 *)DAT_0e06414c[1];
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
    FUN_0e06d6cc(DAT_0e064150,puVar5,0,0);
  }
  return;
}


