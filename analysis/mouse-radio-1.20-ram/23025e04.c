/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23025e04. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23025e04(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4,
                 short param_5)

{
  uint uVar1;
  uint uVar2;
  
  FUN_230259ec(param_1,param_2,param_3,param_4);
  uVar1 = (uint)(ushort)(DAT_23006b8a + 1);
  uVar2 = uVar1;
  if (30000 < uVar1) {
    uVar2 = 0;
  }
  param_5 = param_5 + _DAT_23006b88;
  _DAT_23006b88 = uVar2;
  if (uVar1 < 0x7531) {
    _DAT_23006b88 = CONCAT22((short)uVar2,param_5);
  }
  return;
}


