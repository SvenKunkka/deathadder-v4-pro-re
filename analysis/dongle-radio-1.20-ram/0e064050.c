/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064050. Types and names are inferred; NOT original source. */

void FUN_0e064050(int param_1,undefined1 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *local_14;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar5 = FUN_0e06cae4(&DAT_23001b48,&local_14,0,0);
    if (iVar5 == 0) {
      local_14[1] = param_1;
      *(undefined1 *)(local_14 + 2) = param_2;
      local_14[3] = param_3;
      puVar3 = DAT_23006984;
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
      *local_14 = 0;
      puVar4 = local_14;
      if (DAT_23006984 != (undefined4 *)0x0) {
        *DAT_23006984 = local_14;
        puVar4 = DAT_23006980;
      }
      DAT_23006980 = puVar4;
      DAT_23006984 = local_14;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e06d630(&DAT_23000238,puVar3,0,0);
    }
    return;
  }
  return;
}


