
void FUN_0e05c0e8(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 in_r3;
  
  bVar1 = DAT_230071cb;
  uVar2 = DAT_230071cd;
  if (DAT_230071de != '\0') {
    FUN_0e05d028();
    bVar1 = DAT_230071cb;
    uVar2 = DAT_230071cd;
  }
  DAT_230065f2._2_1_ = uVar2;
  DAT_23006600 = bVar1;
  DAT_230071de = 0;
  if (DAT_230071cf == '\x01') {
    DAT_23006601 = 4;
    DAT_23006618 = 2;
  }
  else if (DAT_230071cf == '\x02') {
    DAT_23006601 = 9;
    DAT_23006618 = 4;
  }
  else if (DAT_230071cf == '\0') {
    DAT_23006601 = 3;
    DAT_23006618 = 1;
  }
  if (DAT_230071ce < 0x11) {
    DAT_23006602 = (&DAT_0e06fbe8)[DAT_230071ce];
  }
  else {
    DAT_23006602 = 4;
  }
  DAT_23006610 = (uint)DAT_230071cc;
  uVar3 = (uint)DAT_230071ca;
  if (uVar3 < 2) {
    DAT_230071ca = 1;
    DAT_2300660c = 0x32;
  }
  else if (uVar3 < 99) {
    DAT_2300660c = 100 / (uVar3 + 1);
  }
  else {
    DAT_230071ca = 99;
    DAT_2300660c = 1;
  }
  DAT_230065f2._3_1_ = 0;
  DAT_230065ee._0_2_ = 0;
  DAT_230065f6._0_2_ = 0;
  DAT_230065fa._2_2_ = 0;
  DAT_230065fe = 0;
  DAT_230065e8 = 2;
  DAT_230065f6._2_2_ = 0xc0d5;
  DAT_230065fa._0_2_ = 0xe05;
  DAT_230065ea = (uint)DAT_23006600 << 0x10;
  DAT_23006614 = (uint)DAT_230071ac;
  DAT_230065ee._2_2_ = (ushort)DAT_230071cc;
  DAT_230065f2._0_2_ = 0;
  DAT_230065e9 = DAT_23006601;
  DAT_23006603 = DAT_230065f2._2_1_;
  DAT_230071cb = DAT_23006600;
  DAT_230071cd = DAT_230065f2._2_1_;
  FUN_0e05cd78(&DAT_230065e8,DAT_23006610,DAT_23006614,in_r3);
  return;
}


