/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021534. Types and names are inferred; NOT original source. */

void FUN_23021534(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_230030e6;
  DAT_230030e4 = (undefined2)param_1;
  iVar1 = FUN_23021b8c(param_1 ^ uVar2);
  iVar1 = FUN_23021b8c(uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff);
  iVar1 = FUN_23021b8c(uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff);
  uVar2 = uVar2 ^ uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff;
  DAT_230030e3 = (&DAT_23003132)[uVar2 % 0x25];
  if (DAT_230030e3 == -1) {
    DAT_230030e3 = (&DAT_2300310d)[(byte)(&DAT_230030e8)[uVar2 * DAT_23003157 >> 0x10]];
  }
  return;
}


