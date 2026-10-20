/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e089b20. Types and names are inferred; NOT original source. */

undefined4 FUN_0e089b20(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(DAT_0e089b8c + 0x28) & 0x1000) == 0) {
    uVar1 = 0x16;
  }
  else {
    uVar1 = 0x17;
  }
  if ((*(uint *)(DAT_0e089b8c + 0x28) & 0x800) != 0) {
    uVar1 = 0x18;
  }
  if (*(int *)(DAT_0e089b8c + 0x28) << 0x16 < 0) {
    if ((*(int *)(DAT_0e089b8c + 0x28) << 0x10 < 0) && (param_1 != 0)) {
      *(uint *)(DAT_0e089b8c + 0x28) = *(uint *)(DAT_0e089b8c + 0x28) & 0xffff7fff;
    }
    uVar1 = 0x19;
  }
  if ((*(uint *)(DAT_0e089b8c + 0x28) & 0x400) != 0) {
    uVar1 = 0x1a;
  }
  if (*(int *)(DAT_0e089b8c + 0x28) << 0x17 < 0) {
    uVar1 = 0x1b;
  }
  else if ((*(uint *)(DAT_0e089b8c + 0x28) & 0x2000) != 0) {
    uVar1 = 0x1c;
  }
  *(uint *)(DAT_0e089b8c + 0x28) = *(uint *)(DAT_0e089b8c + 0x28) | 0xff00;
  *param_2 = 0;
  return uVar1;
}


