/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089e48. Types and names are inferred; NOT original source. */

void FUN_0e089e48(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(((uVar1 >> 5) + 0x20) * 4 + -0x1fff1f00) = 1 << (uVar1 & 0x1f);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


