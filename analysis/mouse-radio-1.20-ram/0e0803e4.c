/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0803e4. Types and names are inferred; NOT original source. */

void FUN_0e0803e4(undefined1 param_1,undefined1 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_2300771c;
  DAT_2300771c = (byte)(uVar1 + 1);
  if (7 < (uVar1 + 1 & 0xff)) {
    DAT_2300771c = 0;
  }
  DAT_230076d2 = DAT_230076d2 | 0x80;
  DAT_2300771d = param_2;
  DAT_2300771e = param_1;
  *(undefined1 *)((int)&DAT_23004a98 + uVar1) = param_1;
  *(undefined1 *)((int)&DAT_23004a90 + uVar1) = param_2;
  return;
}


