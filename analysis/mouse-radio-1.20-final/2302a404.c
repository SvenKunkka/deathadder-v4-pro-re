/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302a404. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302a404(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  undefined4 in_r3;
  
  bVar5 = DAT_23001504._3_1_ | DAT_23001504._2_1_ << 1;
  if (DAT_23007794 == bVar5) goto LAB_2302a468;
  DAT_23007793 = bVar5 | DAT_23007793 << 2;
  bVar3 = DAT_23007793 & 0x3f;
  DAT_23007794 = bVar5;
  if (bVar3 == 0x34) {
LAB_2302a43c:
    if (DAT_23007724 == '\x03') {
      DAT_2300778a = DAT_2300778a + 1;
    }
    else {
      FUN_23027170(1,6,bVar3,DAT_23007724,in_r3);
      _DAT_23006774 = 0x102;
    }
  }
  else if (bVar3 < 0x35) {
    if (bVar3 == 7) {
LAB_2302a488:
      if (DAT_23007724 == '\x03') {
        DAT_2300778a = DAT_2300778a - 1;
      }
      else {
        FUN_23027170(1,7,bVar3,DAT_23007724,in_r3);
        _DAT_23006776 = 0x102;
      }
    }
    else if (bVar3 == 0xb) goto LAB_2302a43c;
  }
  else if (bVar3 == 0x38) goto LAB_2302a488;
  DAT_23007792 = 1;
  DAT_230076dc = 0;
  DAT_230076de = 0;
LAB_2302a468:
  bVar5 = DAT_2300778a;
  uVar2 = (uint)DAT_230076da;
  uVar4 = (uint)DAT_2300495f * 2;
  if (DAT_2300778a == 0) {
    if (uVar4 < uVar2 || uVar4 - uVar2 == 0) {
      DAT_23007791 = 0;
      DAT_230076da = (short)uVar4;
      DAT_2300778f = DAT_23007790;
      return;
    }
    DAT_230076da = DAT_230076da + 1;
    return;
  }
  if ((DAT_2300778a & 0x80) == 0) {
    DAT_23007790 = '\x01';
  }
  else {
    DAT_23007790 = '\x02';
  }
  cVar1 = DAT_23007790;
  if ((uVar4 < uVar2 || uVar4 - uVar2 == 0) || (cVar1 = DAT_2300778f, DAT_2300778f == DAT_23007790))
  {
    DAT_2300778f = cVar1;
    DAT_230076da = 0;
    if (DAT_23007791 == '\0') {
      DAT_2300778a = DAT_23007791;
      DAT_23007789 = bVar5 + DAT_23007789;
      DAT_230076d2 = DAT_230076d2 | 2;
      return;
    }
  }
  else {
    DAT_23007791 = '\x01';
  }
  DAT_2300778a = 0;
  return;
}


