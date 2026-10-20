/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e079cac. Types and names are inferred; NOT original source. */

void FUN_0e079cac(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 in_r3;
  
  bVar1 = DAT_230076fd;
  uVar2 = DAT_230076ff;
  if (DAT_23007710 != '\0') {
    FUN_0e07abec();
    bVar1 = DAT_230076fd;
    uVar2 = DAT_230076ff;
  }
  DAT_23003872._2_1_ = uVar2;
  DAT_23003880 = bVar1;
  DAT_23007710 = 0;
  if (DAT_23007701 == '\x01') {
    DAT_23003881 = 4;
    DAT_23003898 = 2;
  }
  else if (DAT_23007701 == '\x02') {
    DAT_23003881 = 9;
    DAT_23003898 = 4;
  }
  else if (DAT_23007701 == '\0') {
    DAT_23003881 = 3;
    DAT_23003898 = 1;
  }
  if (DAT_23007700 < 0x11) {
    DAT_23003882 = (&DAT_0e098a40)[DAT_23007700];
  }
  else {
    DAT_23003882 = 4;
  }
  DAT_23003890 = (uint)DAT_230076fe;
  uVar3 = (uint)DAT_230076fc;
  if (uVar3 < 2) {
    DAT_230076fc = 1;
    DAT_2300388c = 0x32;
  }
  else if (uVar3 < 99) {
    DAT_2300388c = 100 / (uVar3 + 1);
  }
  else {
    DAT_230076fc = 99;
    DAT_2300388c = 1;
  }
  DAT_23003872._3_1_ = 0;
  DAT_2300386e._0_2_ = 0;
  DAT_23003876._0_2_ = 0;
  DAT_2300387a._2_2_ = 0;
  DAT_2300387e = 0;
  DAT_23003868 = 2;
  DAT_23003876._2_2_ = 0x9c99;
  DAT_2300387a._0_2_ = 0xe07;
  DAT_2300386a = (uint)DAT_23003880 << 0x10;
  DAT_23003894 = (uint)DAT_2300768a;
  DAT_2300386e._2_2_ = (ushort)DAT_230076fe;
  DAT_23003872._0_2_ = 0;
  DAT_23003869 = DAT_23003881;
  DAT_23003883 = DAT_23003872._2_1_;
  DAT_230076fd = DAT_23003880;
  DAT_230076ff = DAT_23003872._2_1_;
  FUN_0e07a93c(&DAT_23003868,DAT_23003890,DAT_23003894,in_r3);
  return;
}


