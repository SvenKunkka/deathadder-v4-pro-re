/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089b90. Types and names are inferred; NOT original source. */

undefined4 FUN_0e089b90(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(DAT_0e089c0c + 0x28) & 0x10) == 0) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x11;
  }
  if ((*(uint *)(DAT_0e089c0c + 0x28) & 8) != 0) {
    uVar1 = 0x12;
  }
  if (*(int *)(DAT_0e089c0c + 0x28) << 0x1e < 0) {
    if ((*(int *)(DAT_0e089c0c + 0x28) << 0x18 < 0) && (param_1 != 0)) {
      *(uint *)(DAT_0e089c0c + 0x28) = *(uint *)(DAT_0e089c0c + 0x28) & 0xffffff7f;
    }
    uVar1 = 0x13;
  }
  if ((*(uint *)(DAT_0e089c0c + 0x28) & 1) != 0) {
    uVar1 = 0x14;
  }
  if ((*(uint *)(DAT_0e089c0c + 0x28) & 0x20) != 0) {
    uVar1 = 0x15;
  }
  if (*(int *)(DAT_0e089c0c + 0x28) << 0x1a < 0) {
    *(uint *)(DAT_0e089c0c + 0x24) = *(uint *)(DAT_0e089c0c + 0x24) & 0xffffdfff;
  }
  *(uint *)(DAT_0e089c0c + 0x28) = *(uint *)(DAT_0e089c0c + 0x28) | 0xff;
  *param_2 = 0;
  return uVar1;
}


