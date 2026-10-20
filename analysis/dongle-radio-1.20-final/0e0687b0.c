/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0687b0. Types and names are inferred; NOT original source. */

int FUN_0e0687b0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  
  if ((*(char *)(*(int *)(param_1 + 4) + 0x48) != '\0') &&
     (iVar2 = FUN_0e06edf4(*param_2), iVar2 != 0)) {
    return iVar2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  software_interrupt(2);
  *param_2 = 0;
  return 0;
}


