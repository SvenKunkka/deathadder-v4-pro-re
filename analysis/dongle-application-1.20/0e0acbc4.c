/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0acbc4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0acbc4(int param_1,undefined4 param_2,code *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r3;
  
  _DAT_2f0119c8 = *(undefined4 *)(param_1 + 0x80);
  setProcStackPointerLimit(*(undefined4 *)(param_1 + 0x70));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(param_2);
  }
  _DAT_2f011ba0 = param_1;
  FUN_0e0b1d2a(0);
  FUN_0e0b00f0();
  iVar3 = FUN_0e0b2940();
  *(undefined4 *)(iVar3 + 8) = extraout_r3;
  (*param_3)(0,0,0);
  FUN_0e0aca08(*(undefined4 *)(iVar3 + 8));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e0ac974(extraout_r1);
  FUN_0e0b0c28("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e0b1d38();
  } while( true );
}


