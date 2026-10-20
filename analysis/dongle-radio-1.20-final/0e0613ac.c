/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0613ac. Types and names are inferred; NOT original source. */

void FUN_0e0613ac(int param_1,undefined4 param_2,code *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r3;
  
  DAT_23006930 = *(undefined4 *)(param_1 + 0x84);
  setProcStackPointerLimit(*(undefined4 *)(param_1 + 0x74));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(param_2);
  }
  DAT_23007170 = param_1;
  FUN_0e0613f4(0);
  FUN_0e06e3a4();
  iVar3 = FUN_0e06f4ac();
  *(undefined4 *)(iVar3 + 8) = extraout_r3;
  (*param_3)(0,0,0);
  FUN_0e061198(*(undefined4 *)(iVar3 + 8));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06110c(extraout_r1);
  FUN_0e05d634("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e061410();
  } while( true );
}


