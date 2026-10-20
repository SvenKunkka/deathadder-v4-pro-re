/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e078db4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0e080328(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (uint)DAT_23004477;
  DAT_23007727 = DAT_23007727 | 1;
  uVar3 = *(undefined4 *)((int)&DAT_23004a60 + (uint)DAT_23004a60._2_1_ * 6 + 3);
  DAT_23004a8c = uVar3;
  _DAT_23006bc4 = uVar3;
  (&DAT_230044d4)[uVar2 * 0xf4] = DAT_23004a60._2_1_;
  *(undefined4 *)(&DAT_230044ca + uVar2 * 0xf4) = uVar3;
  FUN_0e07d4ac(8);
  cVar1 = DAT_23007723;
  uVar2 = (uint)DAT_2300771c;
  DAT_2300771d = 0;
  DAT_2300771c = (byte)(uVar2 + 1);
  if (7 < (uVar2 + 1 & 0xff)) {
    DAT_2300771c = 0;
  }
  DAT_230076d2 = DAT_230076d2 | 0x80;
  DAT_2300771e = 2;
  (&DAT_23004a98)[uVar2] = 2;
  (&DAT_23004a90)[uVar2] = 0;
  if ((cVar1 == '\x01') && (DAT_2300777f != '\0')) {
    (*(code *)0x23021279)();
    return;
  }
  return;
}


