/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08cb98. Types and names are inferred; NOT original source. */

void FUN_0e08cb98(int param_1,undefined1 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *local_14;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar5 = FUN_0e0949b0(&DAT_230015e8,&local_14,0,0);
    if (iVar5 == 0) {
      local_14[1] = param_1;
      *(undefined1 *)(local_14 + 2) = param_2;
      local_14[3] = param_3;
      puVar3 = DAT_23006d84;
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
      *local_14 = 0;
      puVar4 = local_14;
      if (DAT_23006d84 != (undefined4 *)0x0) {
        *DAT_23006d84 = local_14;
        puVar4 = DAT_23006d80;
      }
      DAT_23006d80 = puVar4;
      DAT_23006d84 = local_14;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e0954e0(&DAT_23000230,puVar3,0,0);
    }
    return;
  }
  return;
}


