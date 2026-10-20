/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e64d8. Types and names are inferred; NOT original source. */

void FUN_1c0e64d8(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_1c0e6568;
  uVar2 = *DAT_1c0e6568;
  *DAT_1c0e6568 = uVar2 & 0xfffeffff;
  if ((int)(uVar2 << 0xf) < 0) {
    FUN_1c0fe6f8(*DAT_1c0e656c,DAT_1c0e6570);
  }
  uVar2 = *puVar1;
  *puVar1 = uVar2 & 0xfffffffb;
  if ((int)(uVar2 << 0x1d) < 0) {
    FUN_1c0fe8d0(*DAT_1c0e656c,DAT_1c0e6580,DAT_1c0e6574);
  }
  uVar2 = *puVar1;
  *puVar1 = uVar2 & 0xffffffef;
  if ((int)(uVar2 << 0x1b) < 0) {
    FUN_1c0fe8d0(*DAT_1c0e656c,DAT_1c0e6580,DAT_1c0e657c);
  }
  uVar2 = *puVar1;
  *puVar1 = uVar2 & 0xfffffeff;
  if ((int)(uVar2 << 0x17) < 0) {
    FUN_1c0fe8d0(*DAT_1c0e656c,DAT_1c0e6578,DAT_1c0e6574);
    return;
  }
  return;
}


