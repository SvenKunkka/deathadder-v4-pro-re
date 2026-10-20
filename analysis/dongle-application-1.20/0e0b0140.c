/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b0140. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0b0140(int param_1)

{
  if (*(ushort *)(param_1 + 0xe) < 0x80) {
    if (_DAT_2f011bcc == 0) {
      return 0;
    }
    if ((_DAT_2f011bc8 <= *(char *)(param_1 + 0xe)) && ((*(byte *)(param_1 + 0xd) & 0x1f) == 0)) {
      if (param_1 == 0x2f011718) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


