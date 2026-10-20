/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089f44. Types and names are inferred; NOT original source. */

void FUN_0e089f44(int param_1,undefined4 param_2,code *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r3;
  
  DAT_23006d30 = *(undefined4 *)(param_1 + 0x84);
  setProcStackPointerLimit(*(undefined4 *)(param_1 + 0x74));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(param_2);
  }
  DAT_23007654 = param_1;
  FUN_0e089f8c(0);
  FUN_0e0961d0();
  iVar3 = FUN_0e0974ec();
  *(undefined4 *)(iVar3 + 8) = extraout_r3;
  (*param_3)(0,0,0);
  FUN_0e089d18(*(undefined4 *)(iVar3 + 8));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e089c8c(extraout_r1);
  FUN_0e085e6c("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e089fa8();
  } while( true );
}


