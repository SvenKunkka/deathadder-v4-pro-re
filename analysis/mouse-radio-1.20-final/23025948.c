/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025948. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_23025948(int param_1)

{
  ushort uVar1;
  undefined1 local_30;
  undefined1 local_2f;
  
  uVar1 = *(ushort *)(param_1 + 1);
  FUN_23021c58(0,uVar1 << 8 | uVar1 >> 8);
  if (uVar1 != 0) {
    local_2f = 0;
    if (_DAT_23006b88 >> 0x10 != 0) {
      local_2f = (undefined1)((_DAT_23006b88 & 0xffff) / (_DAT_23006b88 >> 0x10));
    }
    _DAT_23006b88 = 0;
    local_30 = 0xac;
    FUN_23025ab0(0,3,&local_30,2,0xff);
    DAT_23006b68 = 0;
  }
  return 1;
}


