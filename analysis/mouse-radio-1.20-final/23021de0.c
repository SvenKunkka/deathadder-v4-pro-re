/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23021de0. Types and names are inferred; NOT original source. */

void FUN_23021de0(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_230026c6;
  DAT_230026c4 = (undefined2)param_1;
  iVar1 = FUN_230222e0(param_1 ^ uVar2);
  iVar1 = FUN_230222e0(uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff);
  iVar1 = FUN_230222e0(uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff);
  uVar2 = uVar2 ^ uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff;
  DAT_230026c3 = (&DAT_23002712)[uVar2 % 0x25];
  if (DAT_230026c3 == -1) {
    DAT_230026c3 = (&DAT_230026ed)[(byte)(&DAT_230026c8)[uVar2 * DAT_23002737 >> 0x10]];
  }
  return;
}


