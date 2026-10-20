/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0612cc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0612cc(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_0e061300;
  iVar2 = DAT_0e0612fc;
  iVar4 = *(int *)(DAT_0e0612fc + 8);
  *(undefined4 *)(iVar4 + 0x88) = param_1;
  *(undefined4 *)(iVar4 + 0x8c) = 0xfffffff5;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)(*(int *)(iVar2 + 8) + 0x8c);
}


