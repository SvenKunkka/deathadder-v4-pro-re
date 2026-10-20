/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021654. Types and names are inferred; NOT original source. */

uint FUN_23021654(undefined4 param_1,int param_2)

{
  if ((DAT_2300323e == 0) || (DAT_2300323e == 1)) {
    return (uint)*(byte *)((int)&DAT_2300534b + param_2 * 4 + (uint)(byte)(&DAT_23005349)[param_2]);
  }
  if ((DAT_2300323e != 2) && (DAT_2300323e != 3)) {
    return 0x962;
  }
  FUN_23021534();
  DAT_23003228 = (ushort)DAT_230030e3;
  return (uint)(byte)(&DAT_0e06fb84)[DAT_230030e3];
}


